/**
 * @file callbacks_main_menu.c
 * @author João Moreira (jcmoreira@ua.pt)
 * @brief Callbacks associated with the Main Menu Screen.
 * @date 2019-01-25
 * 
 */

#include "quiz.h"

/**
 * @brief Callback to create new quiz.
 * 
 */
void on_menu_new_btn_clicked(void) {

    GtkWidget *menu_scrn;
    GtkWidget *edit_scrn;

    menu_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "menu_scrn"));
    edit_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "edit_scrn"));

    gtk_widget_hide(menu_scrn);
    gtk_widget_show(edit_scrn);

}


/**
 * @brief Callback to go to play screen.
 * 
 */
void on_menu_play_btn_clicked(void) {

    GtkWidget *menu_scrn;
    GtkWidget *play_scrn;
    GtkWidget *load_scrn;

    menu_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "menu_scrn"));
    play_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "play_scrn"));
    load_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "load_scrn"));

    if (newfileG == TRUE) {
        menuG = TRUE;
        gtk_widget_show (load_scrn);
    }
    else {
        PARI_play_scrn_set();
        gtk_widget_show(play_scrn);
        gtk_widget_hide(menu_scrn);
    }
}
