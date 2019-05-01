/**
 * @file callbacks_edit_file.c
 * @author João Moreira (jcmoreira@ua.pt)
 * @brief Callbacks associated with the File Menu (topbar) from the Edit Screen.
 * @date 2019-01-25
 * 
 */

#include "quiz.h"

/*  *******************************************************************************
    *                                      New                                    *
    ******************************************************************************* */
/**
 * @brief Callback to create new file (from menu).
 * 
 */
void on_file_new_btn_activate(void) {

    GtkWidget *warning_scrn;

    warning_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "warning_scrn"));

    gtk_widget_show (warning_scrn);
}


/**
 * @brief Callback to ok button 2 (new file warning window).
 * 
 */
void on_ok_btn_2_clicked(void) {

    on_clean_btn_1_clicked ();
    on_cancel_btn_2_clicked ();
}


/**
 * @brief Callback to cancel button 2 (new file warning window).
 * 
 */
void on_cancel_btn_2_clicked(void) {

    GtkWidget *warning_scrn;

    warning_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "warning_scrn"));

    gtk_widget_hide (warning_scrn);
}


/*  *******************************************************************************
    *                                     Save                                    *
    ******************************************************************************* */
/**
 * @brief Callback to save (from menu).
 * 
 */
void on_file_save_btn_activate(void) {

    GtkFileChooser *chooser;
    GtkWidget *save_scrn;
    const gchar *filename;

    chooser = GTK_FILE_CHOOSER(gtk_builder_get_object (builderG, "save_scrn"));
    save_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "save_scrn"));

    filename = gtk_file_chooser_get_current_name (chooser);

    if (newfileG == TRUE)
        gtk_widget_show (save_scrn);
    else
        on_ok_btn_3_clicked();    
}



/*  *******************************************************************************
    *                                   Save As                                   *
    ******************************************************************************* */
/**
 * @brief Callback to save as (from menu).
 * 
 */
void on_file_save_as_btn_activate(void) {

    GtkWidget *save_scrn;
    GtkFileChooser *chooser;
    GtkFileChooser *chooser_PH;

    save_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "save_scrn"));
    chooser = GTK_FILE_CHOOSER(gtk_builder_get_object (builderG, "save_scrn"));
    chooser_PH = GTK_FILE_CHOOSER(gtk_builder_get_object (builderG, "chooser_PH"));

    if (gtk_file_chooser_get_current_name (chooser) != NULL) {
        gchar *filename;
        filename = gtk_file_chooser_get_current_name (chooser);
        gtk_file_chooser_set_current_name (chooser_PH, filename);
        g_free (filename);
    }

    gtk_widget_show (save_scrn);
}


/**
 * @brief Callback to ok button 3 (save as window).
 * 
 */
void on_ok_btn_3_clicked(void) {

    GtkWidget *error_save_scrn;
    GtkWidget *save_scrn;
    GtkFileChooser *chooser;

    error_save_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "error_save_scrn"));
    save_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "save_scrn"));
    chooser = GTK_FILE_CHOOSER(gtk_builder_get_object (builderG, "save_scrn"));

    if (gtk_file_chooser_get_current_name (chooser) != NULL) {
        gchar *filename;
        filename = gtk_file_chooser_get_current_name (chooser);
        PARI_set_global_variables();
        PARI_save (filename);
        g_free (filename);
        newfileG == FALSE;
    }
    else
        gtk_widget_show (error_save_scrn);

    gtk_widget_hide (save_scrn);
}


/**
 * @brief Callback to cancel button 3 (save as window).
 * 
 */
void on_cancel_btn_3_clicked(void) {

    GtkWidget *save_scrn;
    GtkFileChooser *chooser;
    GtkFileChooser *chooser_PH;

    save_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "save_scrn"));
    chooser = GTK_FILE_CHOOSER(gtk_builder_get_object (builderG, "save_scrn"));
    chooser_PH = GTK_FILE_CHOOSER(gtk_builder_get_object (builderG, "chooser_PH"));

    if (newfileG == FALSE) {
        gchar *filename;
        filename = gtk_file_chooser_get_filename (chooser_PH);
        gtk_file_chooser_set_current_name (chooser, filename);
        g_free(filename);
    }
    else
        PARI_reset_filename();

    gtk_widget_hide (save_scrn);
}


/**
 * @brief Callback to cancel button 4 (error save window).
 * 
 */
void on_ok_btn_4_clicked(void) {

    GtkWidget *error_save_scrn;

    error_save_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "error_save_scrn"));

    gtk_widget_hide (error_save_scrn);
}


/*  *******************************************************************************
    *                                     Load                                    *
    ******************************************************************************* */
/**
 * @brief Callback to load (from menu).
 * 
 */
void on_file_load_btn_activate(void) {

    GtkWidget *load_scrn;

    load_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "load_scrn"));

    gtk_widget_show (load_scrn);
}


/**
 * @brief Callback to cancel button 5 (load window).
 * 
 */
void on_cancel_btn_5_clicked(void) {

    GtkWidget *load_scrn;

    load_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "load_scrn"));

    gtk_widget_hide (load_scrn);
}


/**
 * @brief Callback to ok button 5 (load window).
 * 
 */
void on_ok_btn_5_clicked(void) {

    GtkWidget *load_scrn;
    GtkWidget *play_scrn;
    GtkWidget *menu_scrn;
    GtkFileChooser *chooser;
    GtkFileChooser *chooser_save;

    load_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "load_scrn"));
    play_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "play_scrn"));
    menu_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "menu_scrn"));
    chooser = GTK_FILE_CHOOSER(gtk_builder_get_object (builderG, "load_scrn"));
    chooser_save = GTK_FILE_CHOOSER(gtk_builder_get_object (builderG, "save_scrn"));

    on_clean_btn_1_clicked();

    if (gtk_file_chooser_get_filename (chooser) != NULL) {
        gchar *filename;
        filename = gtk_file_chooser_get_filename (chooser);
        PARI_load (filename);
        gtk_file_chooser_set_current_name (chooser_save, filename);
        g_free (filename);
        newfileG = FALSE;
    }

    if (menuG == TRUE) {
        gtk_widget_show (play_scrn);
        gtk_widget_hide (menu_scrn);
        menuG = FALSE;
    }

    on_cancel_btn_5_clicked();
}


/*  *******************************************************************************
    *                                     Quit                                    *
    ******************************************************************************* */
/**
 * @brief Callback to quit (from menu).
 * 
 */
void on_file_quit_btn_activate(void) {

    
    GtkWidget *warning_scrn;

    warning_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "warning_scrn_2"));

    gtk_widget_show (warning_scrn);
}


/**
 * @brief Callback to ok button 6 (quit warning window).
 * 
 */
void on_ok_btn_6_clicked(void) {

    GtkWidget *warning_scrn;
    GtkWidget *menu_scrn;
    GtkWidget *edit_scrn;

    menu_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "menu_scrn"));
    edit_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "edit_scrn"));
    warning_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "warning_scrn_2"));

    on_cancel_btn_6_clicked ();
    gtk_widget_show(menu_scrn);
    gtk_widget_hide(edit_scrn);
}


/**
 * @brief Callback to cancel button 6 (quit warning window).
 * 
 */
void on_cancel_btn_6_clicked(void) {

    GtkWidget *warning_scrn;

    warning_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "warning_scrn_2"));

    gtk_widget_hide (warning_scrn);
}