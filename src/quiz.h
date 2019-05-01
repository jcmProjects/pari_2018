/**
 * @file quiz.h
 * @author João Moreira (jcmoreira@ua.pt)
 * @brief Header file for main.c and files associated with the interface.
 * @date 2019-01-25
 * 
 */

// Includes
#include <gtk/gtk.h>
#include <stdbool.h>
#include <shm.h>
#include <server.h>

// Global Variables
#ifdef __MAIN_C_
    GtkBuilder *builderG;           /**< Gtk Builder. */
    gint timeG;                     /**< Time for timer. */
    gchar ansG;                     /**< Right answer (1, 2, ..., 5) */
    gint res_widthG;                /**< Widht of the screen (resolution) */
    const gchar *ans_a_G;           /**< Answer a) string. */
    const gchar *ans_b_G;           /**< Answer b) string. */
    const gchar *ans_c_G;           /**< Answer c) string. */
    const gchar *ans_d_G;           /**< Answer d) string. */
    const gchar *ans_e_G;           /**< Answer e) string. */
    const gchar *questionG;         /**< Question string. */
    const char *imgG;               /**< Image path. */
    gboolean newfileG;              /**< TRUE means new file in use, FALSE means existing file. */
    gboolean menuG;                 /**< TRUE means we're going to Play Screen straight from the Main Menu. */
    int shm_id;                     /**< Shared memory ID. */
    int stop_executionG;            /**< Indicates the server to stop execution (if = 1). */
    bool server_onG = FALSE;        /**< Server status (TRUE means on, FALSE means off). */
    int child_pidG;                 /**< Child pid. */
    int child_child_pidG;           /**< Child's child pid. */
    int parent_pidG;                /**< Parent pid. */
    int infinite_loopG = 1;         /**< Infinite loop for the server (keeps running while 1). */
#else
    extern GtkBuilder *builderG;    /**< Gtk Builder. */
    extern gint timeG;              /**< Time for timer. */
    extern gchar ansG;              /**< Right answer (1, 2, ..., 5) */
    extern gint res_widthG;         /**< Widht of the screen (resolution) */
    extern const gchar *ans_a_G;    /**< Answer a) string. */
    extern const gchar *ans_b_G;    /**< Answer b) string. */
    extern const gchar *ans_c_G;    /**< Answer c) string. */
    extern const gchar *ans_d_G;    /**< Answer d) string. */
    extern const gchar *ans_e_G;    /**< Answer e) string. */
    extern const gchar *questionG;  /**< Question string. */
    extern const char *imgG;        /**< Image path. */
    extern gboolean newfileG;       /**< TRUE means new file in use, FALSE means existing file. */
    extern gboolean menuG;          /**< TRUE means we're going to Play Screen straight from the Main Menu. */
    extern int shm_id;              /**< Shared memory ID. */
    extern int stop_executionG;     /**< Indicates the server to stop execution (if = 1). */
    extern bool server_onG;         /**< Server status (TRUE means on, FALSE means off). */
    extern int child_pidG;          /**< Child pid. */
    extern int child_child_pidG;    /**< Child's child pid. */
    extern int parent_pidG;         /**< Parent pid. */
    extern int infinite_loopG;      /**< Infinite loop for the server (keeps running while 1). */
#endif

// Prototypes
#include "prototypes.h" // tem de ser asseguir aos typedef