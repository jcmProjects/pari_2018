/**
 * @file server.h
 * @author João Moreira (jcmoreira@ua.pt)
 * @brief Header file for server.c
 * @version 0.1
 * @date 2019-01-25
 * 
 * @copyright Copyright (c) 2019
 * 
 */

// Includes
#include <stdbool.h>

// Global Variables
extern int stop_executionG;     /**< Indicates the server to stop execution (if = 1). */
extern bool server_onG;         /**< Server status (TRUE means on, FALSE means off). */
extern int child_pidG;          /**< Child pid. */
extern int child_child_pidG;    /**< Child's child pid. */
extern int parent_pidG;         /**< Parent pid. */
extern int infinite_loopG;      /**< Infinite loop for the server (keeps running while 1). */

// Prototypes
#include "prototypes.h"
