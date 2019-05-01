/**
 * @file main.c
 * @author João Moreira (jcmoreira@ua.pt)
 * @brief Main function for the ClassQuiz application, responsible for the start of the processes.\n
 *  Forks into two processes, one responsible for the graphical interface, and another responsible for the tcp/ip communications.
 * @date 2019-01-25
 * 
 */

// Defines
#define __MAIN_C_

// Includes
#include <stdio.h> 
#include <signal.h>
#include <sys/types.h> 
#include <unistd.h>
#include "quiz.h"

/**
 * @brief Main function for the ClassQuiz application. Forks into:\n
 *  Parent - responsable for the graphical interface;\n
 *  Child - responsable for tcp/ip communications.
 * 
 * @param argc - number of arguments.
 * @param argv - array with said arguments.
 * @return int - will return '0' when exiting normally, and returns '-1' otherwise.
 */
int main(int argc, char *argv[]) {

	int pid = fork();
        
	if (pid == -1) { 
		printf("Could not fork(). Exiting\n"); 
		return -1;
	}

    // Child process
    if (pid == 0) {	
        shm_id = PARI_shm_get();
        parent_pidG = getppid();
        signal(SIGUSR1, PARI_server_kill);
        signal(SIGUSR2, PARI_server_on);
        PARI_server_main(argc, argv);
    }
    // Parent process
    else {				
        shm_id = PARI_shm_get();	
        PARI_shm_write("");	
        child_pidG = pid;
        signal(SIGUSR1, PARI_client_connected);
        signal(SIGUSR2, PARI_server_error);
        interface_main(argc, argv);
    }

    return 0;
}
