/**
 * @file destroy_signals.c
 * @author João Moreira (jcmoreira@ua.pt)
 * @brief Callbacks associated with destroy events (destroy window, ctrl+c, ...)
 * @date 2019-01-25
 * 
 */

// Includes
#include <signal.h>
#include "quiz.h"

/**
 * @brief  Callback to process the delete_event (usually, window kill request)
 *
 * @param  window - The widget that generated the event (not used here)
 * @param  event - The event description (not used here)
 * @param  data - generic user data (not used here)
 * 
 * @return FALSE - destroy window but does not leave gtk_main loop, and generates a "destroy" event that you can intersect with another callback.
 * @return TRUE - ignore this delete_event request and does nothing. This can be used to give a second chance to user before closing window!
 * 
 * The same effect of <b>TRUE</b> is obtained by returning no value, that is using a <b>void</b> type of function.
 */
gboolean PARI_delete_event(GtkWidget *window, GdkEvent *event, gpointer data) {

    return FALSE;   //destroy window but does not leave gtk_main loop, and generates a "destroy" event
    //return TRUE;    //ignore this delete_event request and does nothing. Same effect as returning 'void'
}


/**
 * @brief  Callback to process the "destroy" event
 *
 * Here you can decide whether you keep in the gtk_main loop operation or if you terminate it
 * That is, you can decide to continue with the GUI running or close the GUI, but not necessarily the application
 * Stop the GTK+ main loop function when the window is destroyed.
 * This event only occurs if delete_event returns FALSE
 * 
 * @param  window - The widget that generated the event (not used here)
 * @param  data - generic user data (not used here)
 * 
 * @return void
 */
void PARI_destroy(GtkWidget *window, gpointer data) {

    gtk_main_quit(); 
    kill(child_pidG, SIGUSR1);
    infinite_loopG = 0;
}


/**
 * @brief  Callback to catch CTRL-C, and quit gtk_main.
 * 
 */
void PARI_intercept_ctrl_c(int a) {

    gtk_main_quit();
    infinite_loopG = 0;
}