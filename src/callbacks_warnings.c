/**
 * @file callbacks_warnings.c
 * @author João Moreira (jcmoreira@ua.pt)
 * @brief Callbacks associated with the Warning Screens.
 * @date 2019-01-25
 * 
 */

#include "quiz.h"

/**
 * @brief Callback to cancel button 1.
 * 
 */
void on_cancel_btn_1_clicked (void) {

    GtkWidget *error_scrn;

    error_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "error_img_scrn"));

    gtk_widget_hide(error_scrn);
}