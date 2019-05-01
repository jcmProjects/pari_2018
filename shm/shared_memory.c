/**
 * @file shared_memory.c
 * @author João Moreira (jcmoreira@ua.pt)
 * @brief Functions associated with shared memory.
 *  Allows the creation and management of said memory.
 * @date 2019-01-25
 * 
 */

// Defines
#define SHM_SIZE 128         /**< 128 bytes for shared memory. */
// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "shm.h"


/**
 * @brief  Gets a shared memory and connects to it. Uses apthname "/".
 * 
 * @return int - The Shared memory ID. Returns -1 in case of failure.
 */
int PARI_shm_get(void) {
    
    key_t key;                       /* it's a long int */
    int shm_id;

    key = ftok("/", 'X');       /* generate a random key based on a file name and char */

    if (key == -1) {
        perror("ftok");
        return -1;
    }

    /* now connect to (or possibly create) the shared memory segment with permission 644 */
    shm_id = shmget(key, SHM_SIZE, 0644 | IPC_CREAT);  // | IPC_CREAT é para criar memoria se ela não existir
    /*
    0644 is related with permissions
         u   g   o
      - rwx rwx rwx
      0 110 100 100     = 0644
    */
    if (shm_id == -1) { 
        perror("shmget"); 
        return -1; 
    }

    return shm_id;
}


/**
 * @brief Writes data to shared memory.
 * 
 * @param str - data to be written.
 */
void PARI_shm_write(char *str) {

	char *data;      			// generic pointer to serve as link for the shared memory
    int shm_id;

    shm_id = PARI_shm_get();    // shared memory ID

	/* attach to the memory segment to get a pointer to it */
    data = (char*)shmat(shm_id, (void *)0, 0);
    if (data == (char *)(-1)) {      
        perror("shmat");
        exit(1);
    }

	// Copy to shared memory
	strcpy(data, str);
	
    /* detach from the mem segment since it is leaving */
    if (shmdt(data) == -1) {
        perror("shmdt");
        exit(1);
    }
}


/**
 * @brief Reads data from shared memory.
 * 
 * @return char* - Data read.
 */
char *PARI_shm_read(void) {

    char *data;      			// generic pointer to serve as link for the shared memory
    char *str;
    int shm_id;

    shm_id = PARI_shm_get();    // shared memory ID

	/* attach to the memory segment to get a pointer to it */
    data = (char*)shmat(shm_id, (void *)0, 0);
    if (data == (char *)(-1)) {      
        perror("shmat");
        exit(1);
    }

	// Copy to shared memory
	strcpy(str, data);
	
    /* detach from the mem segment since it is leaving */
    if (shmdt(data) == -1) {
        perror("shmdt");
        exit(1);
    }

    return str;
}