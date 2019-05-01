/**
 * @file callbacks_edit_scrn.c
 * @author João Moreira (jcmoreira@ua.pt)
 * @brief Callbacks associated with the Edit Screen.
 * @date 2019-01-25
 * 
 */

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quiz.h"

/*  *******************************************************************************
    *                                Choose Image                                 *
    ******************************************************************************* */
/**
 * @brief Callback to choose a image file.
 * 
 */
void on_choose_img_file_set(void) {

    GtkWidget *img_widget;
    GtkWidget *error_scrn;
    GtkImage *img;
    GtkWidget *play_img_widget;
    GtkImage *play_img; 
    GtkFileChooser *choose_img;
    gchar *filename = malloc(200);
    const GdkPixbuf *pb;

    img = GTK_IMAGE(gtk_builder_get_object (builderG, "preview_img"));
    img_widget = GTK_WIDGET(gtk_builder_get_object (builderG, "preview_img"));
    error_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "error_img_scrn"));
    choose_img = GTK_FILE_CHOOSER(gtk_builder_get_object (builderG, "choose_img"));
    play_img = GTK_IMAGE(gtk_builder_get_object (builderG, "play_img"));
    play_img_widget = GTK_WIDGET(gtk_builder_get_object (builderG, "play_img"));

    filename = gtk_file_chooser_get_filename (choose_img);
    imgG = filename;

    if (filename != NULL) {
        
        gtk_image_set_from_file (img, filename);
        gtk_image_set_from_file (play_img, filename);

        if (PARI_check_img_size(img) == TRUE) {
            gtk_widget_show(img_widget);
            gtk_widget_show(play_img_widget);
        }
        else {
            gtk_file_chooser_unselect_all (choose_img);
            gtk_image_clear (img);
            gtk_image_clear (play_img);
            gtk_widget_hide(img_widget);
            gtk_widget_hide(play_img_widget);
            gtk_widget_show(error_scrn);
        }
    }

    g_free(filename);
}


/*  *******************************************************************************
    *                              Back to Main Menu                              *
    ******************************************************************************* */
/**
 * @brief Callback to go back to main menu.
 * 
 */
void on_back_btn_1_clicked(void) {

    GtkWidget *edit_scrn;
    GtkWidget *menu_scrn;

    edit_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "edit_scrn"));
    menu_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "menu_scrn"));

    gtk_widget_hide(edit_scrn);
    gtk_widget_show(menu_scrn);
}


/*  *******************************************************************************
    *                            Forward to Play Screen                           *
    ******************************************************************************* */
/**
 * @brief Callback to go forward to play screen.
 * 
 */
void on_ok_btn_1_clicked(void) {

    GtkWidget *edit_scrn;
    GtkWidget *play_scrn;

    edit_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "edit_scrn"));
    play_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "play_scrn"));

    PARI_play_scrn_set();
    gtk_widget_hide(edit_scrn);
    gtk_widget_show(play_scrn);
}


/*  *******************************************************************************
    *                               Clean Variables                               *
    ******************************************************************************* */
/**
 * @brief Callback to clean. The "clean button" is hidden, but the callback is still used.
 * 
 */
void on_clean_btn_1_clicked(void) {

    GtkImage *img;
    GtkFileChooser *choose_img;
    GtkEntry *question_entry;
    GtkEntry *ans_a_entry;
    GtkEntry *ans_b_entry;
    GtkEntry *ans_c_entry;
    GtkEntry *ans_d_entry;
    GtkEntry *ans_e_entry;
    GtkSpinButton *time_spin;
    GtkToggleButton *check_a;
    GtkToggleButton *check_b;
    GtkToggleButton *check_c;
    GtkToggleButton *check_d;
    GtkToggleButton *check_e;  

    img = GTK_IMAGE(gtk_builder_get_object (builderG, "preview_img"));
    choose_img = GTK_FILE_CHOOSER(gtk_builder_get_object (builderG, "choose_img"));
    question_entry = GTK_ENTRY(gtk_builder_get_object (builderG, "question_entry"));
    ans_a_entry = GTK_ENTRY(gtk_builder_get_object (builderG, "ans_a_entry"));
    ans_b_entry = GTK_ENTRY(gtk_builder_get_object (builderG, "ans_b_entry"));
    ans_c_entry = GTK_ENTRY(gtk_builder_get_object (builderG, "ans_c_entry"));
    ans_d_entry = GTK_ENTRY(gtk_builder_get_object (builderG, "ans_d_entry"));
    ans_e_entry = GTK_ENTRY(gtk_builder_get_object (builderG, "ans_e_entry"));
    time_spin = GTK_SPIN_BUTTON(gtk_builder_get_object (builderG, "time_spin"));
    check_a = GTK_TOGGLE_BUTTON(gtk_builder_get_object (builderG, "ans_a_check"));
    check_b = GTK_TOGGLE_BUTTON(gtk_builder_get_object (builderG, "ans_b_check"));
    check_c = GTK_TOGGLE_BUTTON(gtk_builder_get_object (builderG, "ans_c_check"));
    check_d = GTK_TOGGLE_BUTTON(gtk_builder_get_object (builderG, "ans_d_check"));
    check_e = GTK_TOGGLE_BUTTON(gtk_builder_get_object (builderG, "ans_e_check"));
    
    gtk_image_clear (img);
    gtk_file_chooser_unselect_all (choose_img);
    gtk_entry_set_text (question_entry, "");
    gtk_entry_set_text (ans_a_entry, "");
    gtk_entry_set_text (ans_b_entry, "");
    gtk_entry_set_text (ans_c_entry, "");
    gtk_entry_set_text (ans_d_entry, "");
    gtk_entry_set_text (ans_e_entry, "");
    gtk_spin_button_set_value (time_spin, 0);
    gtk_toggle_button_set_active (check_a, FALSE);
    gtk_toggle_button_set_active (check_b, FALSE);
    gtk_toggle_button_set_active (check_c, FALSE);
    gtk_toggle_button_set_active (check_d, FALSE);
    gtk_toggle_button_set_active (check_e, FALSE);

    PARI_reset_global_variables();
}


/*  *******************************************************************************
    *                                   Question                                  *
    ******************************************************************************* */
/**
 * @brief Callback to writing a question.
 * 
 */
void on_question_entry_changed(void) {

    GtkLabel *question_lbl;
    GtkLabel *question_lbl1;
    GtkEntry *question_entry;
    gchar *question;
    size_t len;

    question_lbl = GTK_LABEL(gtk_builder_get_object (builderG, "preview_question_lbl"));
    question_lbl1 = GTK_LABEL(gtk_builder_get_object (builderG, "preview_question_lbl1"));
    question_entry = GTK_ENTRY(gtk_builder_get_object (builderG, "question_entry"));

    if (gtk_entry_get_text (question_entry) != NULL) {
        question = (gchar *)gtk_entry_get_text (question_entry);
        questionG = question;
        len = strlen(question);

        if (len > 35)
            return;    
                    
        if (res_widthG == 1024)
            if (len > 25)
                return;
                     
        gtk_label_set_text (question_lbl, question);
        gtk_label_set_text (question_lbl1, question);
    }
}


/*  *******************************************************************************
    *                                    Timer                                    *
    ******************************************************************************* */
/**
 * @brief Callback to get time for the answer.
 * 
 */
void on_time_spin_value_changed(void) {

    GtkSpinButton *time_spin;
    GtkLabel *time_lbl;
    GtkLabel *time_lbl1;
    gchar *str = malloc(200);

    time_spin = GTK_SPIN_BUTTON(gtk_builder_get_object (builderG, "time_spin"));
    time_lbl = GTK_LABEL(gtk_builder_get_object (builderG, "prev_time_lbl"));
    time_lbl1 = GTK_LABEL(gtk_builder_get_object (builderG, "prev_time_lbl1"));

    timeG = gtk_spin_button_get_value_as_int (time_spin);
    sprintf(str, "%d", timeG);
    gtk_label_set_text (time_lbl, str);
    gtk_label_set_text (time_lbl1, str);
    g_free(str);
}


/*  *******************************************************************************
    *                                   Answers                                   *
    ******************************************************************************* */
/**
 * @brief Callback to writing answer a.
 * 
 */
void on_ans_a_entry_changed(void) {

    GtkLabel *prev_lbl;
    GtkLabel *prev_lbl1;
    GtkEntry *ans_entry;
    gchar *str;
    size_t len;

    prev_lbl = GTK_LABEL(gtk_builder_get_object (builderG, "prev_a_lbl"));
    prev_lbl1 = GTK_LABEL(gtk_builder_get_object (builderG, "prev_a_lbl1"));
    ans_entry = GTK_ENTRY(gtk_builder_get_object (builderG, "ans_a_entry"));

    if (gtk_entry_get_text (ans_entry) != NULL) {
        str = (gchar *)gtk_entry_get_text (ans_entry);
        ans_a_G = str;
        len = strlen(str);

        if (len > 25)
            return;
                    
        if (res_widthG == 1024)
            if (len > 15)
                return;
                
        gtk_label_set_text (prev_lbl, str);
        gtk_label_set_text (prev_lbl1, str);
    } 
}


/**
 * @brief Callback to writing answer b.
 * 
 */
void on_ans_b_entry_changed(void) {

    GtkLabel *prev_lbl;
    GtkLabel *prev_lbl1;
    GtkEntry *ans_entry;
    gchar *str;
    size_t len;

    prev_lbl = GTK_LABEL(gtk_builder_get_object (builderG, "prev_b_lbl"));
    prev_lbl1 = GTK_LABEL(gtk_builder_get_object (builderG, "prev_b_lbl1"));
    ans_entry = GTK_ENTRY(gtk_builder_get_object (builderG, "ans_b_entry"));

    if (gtk_entry_get_text (ans_entry) != NULL) {
        str = (gchar *)gtk_entry_get_text (ans_entry);
        ans_b_G = str;
        len = strlen(str);

        if (len > 25)
            return;  
                    
        if (res_widthG == 1024)
            if (len > 15)
                return;
                
        gtk_label_set_text (prev_lbl, str);
        gtk_label_set_text (prev_lbl1, str);
    } 
}


/**
 * @brief Callback to writing answer c.
 * 
 */
void on_ans_c_entry_changed(void) {

    GtkLabel *prev_lbl;
    GtkLabel *prev_lbl1;
    GtkEntry *ans_entry;
    gchar *str;
    size_t len;

    prev_lbl = GTK_LABEL(gtk_builder_get_object (builderG, "prev_c_lbl"));
    prev_lbl1 = GTK_LABEL(gtk_builder_get_object (builderG, "prev_c_lbl1"));
    ans_entry = GTK_ENTRY(gtk_builder_get_object (builderG, "ans_c_entry"));

    if (gtk_entry_get_text (ans_entry) != NULL) {
        str = (gchar *)gtk_entry_get_text (ans_entry);
        ans_c_G = str;
        len = strlen(str);

        if (len > 25)
            return;  
                    
        if (res_widthG == 1024)
            if (len > 15)
                return;
                
        gtk_label_set_text (prev_lbl, str);
        gtk_label_set_text (prev_lbl1, str);
    } 
}


/**
 * @brief Callback to writing answer d.
 * 
 */
void on_ans_d_entry_changed(void) {

    GtkLabel *prev_lbl;
    GtkLabel *prev_lbl1;
    GtkEntry *ans_entry;
    gchar *str;
    size_t len;

    prev_lbl = GTK_LABEL(gtk_builder_get_object (builderG, "prev_d_lbl"));
    prev_lbl1 = GTK_LABEL(gtk_builder_get_object (builderG, "prev_d_lbl1"));
    ans_entry = GTK_ENTRY(gtk_builder_get_object (builderG, "ans_d_entry"));

    if (gtk_entry_get_text (ans_entry) != NULL) {
        str = (gchar *)gtk_entry_get_text (ans_entry);
        ans_d_G = str;
        len = strlen(str);

        if (len > 25)
            return;
                    
        if (res_widthG == 1024)
            if (len > 15)
                return;
                
        gtk_label_set_text (prev_lbl, str);
        gtk_label_set_text (prev_lbl1, str);
    } 
}


/**
 * @brief Callback to writing answer e.
 * 
 */
void on_ans_e_entry_changed(void) {

    GtkLabel *prev_lbl;
    GtkLabel *prev_lbl1;
    GtkEntry *ans_entry;
    gchar *str;
    size_t len;

    prev_lbl = GTK_LABEL(gtk_builder_get_object (builderG, "prev_e_lbl"));
    prev_lbl1 = GTK_LABEL(gtk_builder_get_object (builderG, "prev_e_lbl1"));
    ans_entry = GTK_ENTRY(gtk_builder_get_object (builderG, "ans_e_entry"));

    if (gtk_entry_get_text (ans_entry) != NULL) {
        str = (gchar *)gtk_entry_get_text (ans_entry);
        ans_e_G = str;
        len = strlen(str);

        if (len > 25)
            return;
        
        if (res_widthG == 1024)
            if (len > 15)
                return;

        gtk_label_set_text (prev_lbl, str);
        gtk_label_set_text (prev_lbl1, str);
    } 
}


/*  *******************************************************************************
    *                               Answer Toggles                                *
    ******************************************************************************* */
/**
 * @brief Callback to toggle ans_a.
 * 
 */
void on_ans_a_check_toggled(void) {

    GtkToggleButton *check_a;
    GtkToggleButton *check_b;
    GtkToggleButton *check_c;
    GtkToggleButton *check_d;
    GtkToggleButton *check_e;

    check_a = GTK_TOGGLE_BUTTON(gtk_builder_get_object (builderG, "ans_a_check"));
    check_b = GTK_TOGGLE_BUTTON(gtk_builder_get_object (builderG, "ans_b_check"));
    check_c = GTK_TOGGLE_BUTTON(gtk_builder_get_object (builderG, "ans_c_check"));
    check_d = GTK_TOGGLE_BUTTON(gtk_builder_get_object (builderG, "ans_d_check"));
    check_e = GTK_TOGGLE_BUTTON(gtk_builder_get_object (builderG, "ans_e_check"));

    gtk_toggle_button_set_active (check_b, FALSE);
    gtk_toggle_button_set_active (check_c, FALSE);
    gtk_toggle_button_set_active (check_d, FALSE);
    gtk_toggle_button_set_active (check_e, FALSE);

    if (gtk_toggle_button_get_active (check_a) == TRUE)
        ansG = 1;
    else
        ansG = 0;
}


/**
 * @brief Callback to toggle ans_b.
 * 
 */
void on_ans_b_check_toggled(void) {

    GtkToggleButton *check_a;
    GtkToggleButton *check_b;
    GtkToggleButton *check_c;
    GtkToggleButton *check_d;
    GtkToggleButton *check_e;

    check_a = GTK_TOGGLE_BUTTON(gtk_builder_get_object (builderG, "ans_a_check"));
    check_b = GTK_TOGGLE_BUTTON(gtk_builder_get_object (builderG, "ans_b_check"));
    check_c = GTK_TOGGLE_BUTTON(gtk_builder_get_object (builderG, "ans_c_check"));
    check_d = GTK_TOGGLE_BUTTON(gtk_builder_get_object (builderG, "ans_d_check"));
    check_e = GTK_TOGGLE_BUTTON(gtk_builder_get_object (builderG, "ans_e_check"));

    gtk_toggle_button_set_active (check_a, FALSE);
    gtk_toggle_button_set_active (check_c, FALSE);
    gtk_toggle_button_set_active (check_d, FALSE);
    gtk_toggle_button_set_active (check_e, FALSE);

    if (gtk_toggle_button_get_active (check_b) == TRUE)
        ansG = 2;
    else
        ansG = 0;
}


/**
 * @brief Callback to toggle ans_c.
 * 
 */
void on_ans_c_check_toggled(void) {

    GtkToggleButton *check_a;
    GtkToggleButton *check_b;
    GtkToggleButton *check_c;
    GtkToggleButton *check_d;
    GtkToggleButton *check_e;

    check_a = GTK_TOGGLE_BUTTON(gtk_builder_get_object (builderG, "ans_a_check"));
    check_b = GTK_TOGGLE_BUTTON(gtk_builder_get_object (builderG, "ans_b_check"));
    check_c = GTK_TOGGLE_BUTTON(gtk_builder_get_object (builderG, "ans_c_check"));
    check_d = GTK_TOGGLE_BUTTON(gtk_builder_get_object (builderG, "ans_d_check"));
    check_e = GTK_TOGGLE_BUTTON(gtk_builder_get_object (builderG, "ans_e_check"));

    gtk_toggle_button_set_active (check_a, FALSE);
    gtk_toggle_button_set_active (check_b, FALSE);
    gtk_toggle_button_set_active (check_d, FALSE);
    gtk_toggle_button_set_active (check_e, FALSE);

    if (gtk_toggle_button_get_active (check_c) == TRUE)
        ansG = 3;
    else
        ansG = 0;
}


/**
 * @brief Callback to toggle ans_d.
 * 
 */
void on_ans_d_check_toggled(void) {

    GtkToggleButton *check_a;
    GtkToggleButton *check_b;
    GtkToggleButton *check_c;
    GtkToggleButton *check_d;
    GtkToggleButton *check_e;

    check_a = GTK_TOGGLE_BUTTON(gtk_builder_get_object (builderG, "ans_a_check"));
    check_b = GTK_TOGGLE_BUTTON(gtk_builder_get_object (builderG, "ans_b_check"));
    check_c = GTK_TOGGLE_BUTTON(gtk_builder_get_object (builderG, "ans_c_check"));
    check_d = GTK_TOGGLE_BUTTON(gtk_builder_get_object (builderG, "ans_d_check"));
    check_e = GTK_TOGGLE_BUTTON(gtk_builder_get_object (builderG, "ans_e_check"));

    gtk_toggle_button_set_active (check_a, FALSE);
    gtk_toggle_button_set_active (check_b, FALSE);
    gtk_toggle_button_set_active (check_c, FALSE);
    gtk_toggle_button_set_active (check_e, FALSE);

    if (gtk_toggle_button_get_active (check_d) == TRUE)
        ansG = 4;
    else
        ansG = 0;
}


/**
 * @brief Callback to toggle ans_e.
 * 
 */
void on_ans_e_check_toggled(void) {

    GtkToggleButton *check_a;
    GtkToggleButton *check_b;
    GtkToggleButton *check_c;
    GtkToggleButton *check_d;
    GtkToggleButton *check_e;

    check_a = GTK_TOGGLE_BUTTON(gtk_builder_get_object (builderG, "ans_a_check"));
    check_b = GTK_TOGGLE_BUTTON(gtk_builder_get_object (builderG, "ans_b_check"));
    check_c = GTK_TOGGLE_BUTTON(gtk_builder_get_object (builderG, "ans_c_check"));
    check_d = GTK_TOGGLE_BUTTON(gtk_builder_get_object (builderG, "ans_d_check"));
    check_e = GTK_TOGGLE_BUTTON(gtk_builder_get_object (builderG, "ans_e_check"));

    gtk_toggle_button_set_active (check_a, FALSE);
    gtk_toggle_button_set_active (check_b, FALSE);
    gtk_toggle_button_set_active (check_c, FALSE);
    gtk_toggle_button_set_active (check_d, FALSE);

    if (gtk_toggle_button_get_active (check_e) == TRUE)
        ansG = 5;
    else
        ansG = 0;
}
