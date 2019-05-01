/**
 * @file interface_properties.c
 * @author João Moreira (jcmoreira@ua.pt)
 * @brief Functions used to set the properties of interface widgets.
 * @date 2019-01-25
 * 
 */

#include "quiz.h"


/**
 * @brief Sets the properties for all interface screens.
 * 
 */
void PARI_set_all_scrn_properties(void) {

    PARI_set_wlc_scrn_properties();
    PARI_set_menu_scrn_properties();
    PARI_set_edit_scrn_properties();
    PARI_set_save_scrn_properties();
    PARI_set_load_scrn_properties();
    PARI_set_play_scrn_properties();
    PARI_set_results_scrn_properties();

    PARI_reset_global_variables();
    PARI_check_resolution();
}


/**
 * @brief Sets the properties for the Welcome Screen.
 * 
 */
void PARI_set_wlc_scrn_properties(void) {

    GtkWindow *wlc_scrn;
    GtkImage *wlc_img;

    wlc_scrn = GTK_WINDOW(gtk_builder_get_object(builderG, "wlc_scrn"));
    wlc_img = GTK_IMAGE(gtk_builder_get_object (builderG, "wlc_logo"));

    gtk_window_set_title (wlc_scrn, "ClassQuiz");
    gtk_window_set_icon_from_file (wlc_scrn, "./birdie.svg", NULL);
    gtk_image_set_from_file (wlc_img, "./logo.png");

    kill(child_pidG, SIGUSR2);	
    server_onG = TRUE;
}


/**
 * @brief Sets the properties for the Main Menu Screen.
 * 
 */
void PARI_set_menu_scrn_properties(void) {

    GtkWindow *menu_scrn;
    
    menu_scrn = GTK_WINDOW(gtk_builder_get_object(builderG, "menu_scrn"));

    gtk_window_set_title (menu_scrn, "ClassQuiz");
    gtk_window_set_icon_from_file (menu_scrn, "./birdie.svg", NULL);
}


/**
 * @brief Sets the properties for the Creation/Edit Screen.
 * 
 */
void PARI_set_edit_scrn_properties(void) {

    GtkWindow *edit_scrn;

    edit_scrn = GTK_WINDOW(gtk_builder_get_object(builderG, "edit_scrn"));

    gtk_window_set_title (edit_scrn, "ClassQuiz - Creation Screen");
    gtk_window_set_icon_from_file (edit_scrn, "./birdie.svg", NULL);
    gtk_window_maximize (edit_scrn);
}
 

/**
 * @brief Sets the properties for the Save Screen.
 * 
 */
void PARI_set_save_scrn_properties(void) {

    GtkWindow *save_scrn;
    
    save_scrn = GTK_WINDOW(gtk_builder_get_object(builderG, "save_scrn"));

    gtk_window_set_title (save_scrn, "ClassQuiz - Save File");
    gtk_window_set_icon_from_file (save_scrn, "./birdie.svg", NULL);
}


/**
 * @brief Sets the properties for the Load Screen.
 * 
 */
void PARI_set_load_scrn_properties(void) {

    GtkWindow *load_scrn;
    
    load_scrn = GTK_WINDOW(gtk_builder_get_object(builderG, "load_scrn"));

    gtk_window_set_title (load_scrn, "ClassQuiz - Load File");
    gtk_window_set_icon_from_file (load_scrn, "./birdie.svg", NULL);
}


/**
 * @brief Sets the properties for the Play Screen.
 * 
 */
void PARI_set_play_scrn_properties(void) {

    GtkWindow *play_scrn;

    play_scrn = GTK_WINDOW(gtk_builder_get_object(builderG, "play_scrn"));

    gtk_window_set_title (play_scrn, "ClassQuiz - Play");
    gtk_window_set_icon_from_file (play_scrn, "./birdie.svg", NULL);
    gtk_window_fullscreen (play_scrn);
}


/**
 * @brief Sets the properties for the Results Screen.
 * 
 */
void PARI_set_results_scrn_properties(void) {

    GtkWindow *results_scrn;

    results_scrn = GTK_WINDOW(gtk_builder_get_object(builderG, "results_scrn"));

    gtk_window_set_title (results_scrn, "ClassQuiz - Results");
    gtk_window_set_icon_from_file (results_scrn, "./birdie.svg", NULL);
}