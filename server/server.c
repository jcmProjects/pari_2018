/**
 * @file server.c
 * @author João Moreira (jcmoreira@ua.pt)
 * @brief TCP/IP server main function, and functions to manage clients.\n
 *  Adapted from http://www.linuxhowtos.org/C_C++/socket.htm
 * @date 2019-01-25
 * 
 */

// Includes
#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <errno.h>
#include <shm.h>
#include "server.h"

/**
 * @brief Main function of the server. Is idle until it receives instructions to start the server.
 *  In this version, the server will start by default.
 * 
 * @param argc - inherited from main. not really used.
 * @param argv - inherited from main. not really used.
 * @return int - will return '0' when exiting normally.
 */
int PARI_server_main(int argc, char *argv[]) {

    while(1) {
        while(server_onG == FALSE) {
        }

        PARI_start_server();
    }

    exit(1);
	return 0;		/* we only get here when someone breaks the infinite loop */
}


/**
 * @brief Starts the server, and keeps it running.
 * 
 */
void PARI_start_server(void) {

    int sockfd, clientsockfd, portno, pid;
    portno = 50000;
	int ret;
	char clntName[INET_ADDRSTRLEN];	                   // String to contain client name
	socklen_t clilen;
	struct sockaddr_in serv_addr, cli_addr;

	// To avoid defuncts due to the fork() below. 
	// It is actually the default action and occurs when Child stopped or terminated
	signal(SIGCHLD, SIG_IGN);

	sockfd = socket(AF_INET, SOCK_STREAM, 0);	//create a INET socket to communicate
	if (sockfd < 0)
        PARI_my_error("ERROR opening socket");

	bzero((char *) &serv_addr, sizeof(serv_addr));	// fill with zeros
	serv_addr.sin_family      = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port        = htons(portno);
	ret = bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));	// bind the name to the socket
	if (ret < 0) {
        kill(parent_pidG, SIGUSR2);
        PARI_my_error("ERROR on binding");
    }

    puts("Server opened...");

	listen(sockfd, 1);          // start waiting for connections on the socket up to a maximum of 1 connections
                                // NOTE: limited to 1 connection, because there is only one remote client. Potencially, could be more.
	clilen = sizeof(cli_addr);

	// make socket non blocking so other events may be processed inside the infinite loop
	// An equivalent action could also be done at the socket creation...
	int flags = fcntl(sockfd, F_GETFL, 0); fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);  

	while (infinite_loopG) {
        signal(SIGUSR1, PARI_server_kill);
        
        /* accept the connection */
		clientsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
		if (clientsockfd < 0) {  
			if (errno == EAGAIN) 
                continue;   
			PARI_my_error("ERROR on accept");
		}

		if (inet_ntop (AF_INET, &cli_addr.sin_addr.s_addr, clntName, sizeof(clntName)) != NULL) {
            kill(parent_pidG, SIGUSR1);
            printf("Client %s connected/%d\n", clntName, ntohs(cli_addr.sin_port));
        }
        else
			printf("Unable to get client address\n");

		pid = fork();
		if (pid < 0) PARI_my_error("ERROR on fork");
		if (pid == 0) {	 
			close(sockfd);	// child no longer needs the parent socket. Close it, after all it's simply a handle
					        // Cf. http://stackoverflow.com/questions/14427898/socket-from-parent-to-child
            signal(SIGUSR2, PARI_server_kill);
			PARI_process_client(clientsockfd, clntName);	 //Process client request (a new process)
			exit(0);	    // Exits when finishing processing the client request
		}
		else {	            // It is the parent... does nothing: closes the client socket and resume accepting..
            child_child_pidG = pid;
			close(clientsockfd);
        }
	}

	close(sockfd);
}


/**
 * @brief  Function to process client request.
 *  There will be a separate instance of this function 
 * for each connection established by clients. It handles 
 * all communications once a connection has been established.
 *
 * @param  sock - the socket ID.
 * @param  clientID - the client ID (normally the IP).
 */
void PARI_process_client(int sock, char *clientID) {

	const int BUFFSIZE = 1024;		/*If this is small, enlarge it or use dynamic allocation */
	int n, numBytesSent, bufLen;
	char inbuffer[BUFFSIZE], outbuffer[BUFFSIZE], *str;
	int keepGoing = 1;
    size_t size;

	while(keepGoing) {
        
		bzero(inbuffer, BUFFSIZE);	//empty buffer
		n = recv(sock, inbuffer, BUFFSIZE-1,0);
		if (n == BUFFSIZE-1) {	//means read the entire buffer... there is the chance that more data may be waiting
			printf("Buffer filled\n");
			//mysocketflush(sock);
			//in that case additional memory should be allocated
			//to read the remainder of the message and build it entirely to deal with it.
			//Not done in this example but may be necessary if large bunchs of data were sent from client.
		}
        
		if (n < 0) 
            PARI_my_error("ERROR reading from socket");

        // Print message from client
		if (strlen(inbuffer) > 0) {
            if (infinite_loopG == 0)
                exit(0);

			printf("Message received from the client %s: %s\n", clientID, inbuffer);

            /* shared memory */
            PARI_shm_write(inbuffer);

            size = strlen(inbuffer);
            if (size >= 10)
                kill(parent_pidG, SIGUSR1);
            else
                kill(parent_pidG, SIGUSR2);
        }
	}
	printf("\nConnection to client %s terminated.\n", clientID);
    exit(0);
}


/**
 * @brief Prints error and exits.
 * 
 * @param msg 
 */
void PARI_my_error(const char *msg) {

	perror(msg);
	exit(1);
}


/**
 * @brief Sends signal to child (client manager) to shutdown and exit.
 * 
 * @param signum 
 */
void PARI_server_kill(int signum) {	

    infinite_loopG = 0;
    kill(child_child_pidG, SIGUSR2);
	exit(0);
}


