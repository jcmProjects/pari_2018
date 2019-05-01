/**
 * @file interface_functions.c
 * @author João Moreira (jcmoreira@ua.pt)
 * @brief Auxiliary functions related to the interface.
 * @date 2019-01-25
 * 
 */

// Includes
#include <gdk-pixbuf/gdk-pixbuf.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "quiz.h"


/*  *******************************************************************************
    *                             Screen Resolution                               *
    ******************************************************************************* */
/**
 * @brief Checks the screen resolution (important for allowed image sizes), and makes due alterations to windows.\n
 *  Adapted from: 
 *      https://stackoverflow.com/questions/43225956/how-to-get-the-size-of-the-screen-with-gtk
 * 
 */
void PARI_check_resolution(void) {

    GdkRectangle workarea = {0};

    gdk_monitor_get_workarea(gdk_display_get_primary_monitor (gdk_display_get_default()), &workarea);

    res_widthG = workarea.width;

    if (res_widthG < 1920)
        PARI_change_resolution();
}


/**
 * @brief Changes the allowed image size and the general layout of the widgets to the defined for resolution 1280x720 (16:9).
 * 
 */
void PARI_change_resolution(void) {

    GtkMessageDialog *message_dialog;
    GtkWidget *play_ans_box_720;
    GtkWidget *play_ans_box_1080;
    GtkWidget *play_time_1080;
    GtkWidget *play_time_720;
    GtkWidget *play_qst_lbl;
    GtkWidget *play_qst_lbl_720;
    GtkWidget *edit_box_1080;
    GtkWidget *edit_time_1080;
    GtkWidget *edit_box_720;
    GtkWidget *edit_time_720;
    GtkWidget *edit_qst_720;
    GtkWidget *edit_qst_1080;
    GtkWidget *result_top_1080;
    GtkWidget *result_top_720;
    GtkWidget *result_mid_1080;
    GtkWidget *result_mid_720;
    GtkWidget *time_mid_1080;
    GtkWidget *time_mid_720;
    GtkWidget *answer_1080;
    GtkWidget *answer_720;
    GtkWidget *student_1080;
    GtkWidget *student_720;

    message_dialog = GTK_MESSAGE_DIALOG(gtk_builder_get_object (builderG, "error_img_scrn"));
    play_ans_box_720 = GTK_WIDGET(gtk_builder_get_object (builderG, "play_box_720"));
    play_ans_box_1080 = GTK_WIDGET(gtk_builder_get_object (builderG, "play_box_1080"));
    play_time_1080 = GTK_WIDGET(gtk_builder_get_object (builderG, "play_time_1080"));
    play_time_720 = GTK_WIDGET(gtk_builder_get_object (builderG, "play_time_720"));
    play_qst_lbl = GTK_WIDGET(gtk_builder_get_object (builderG, "play_qst_lbl"));
    play_qst_lbl_720 = GTK_WIDGET(gtk_builder_get_object (builderG, "play_qst_lbl_720"));
    edit_box_1080 = GTK_WIDGET(gtk_builder_get_object (builderG, "edit_box_1080"));
    edit_box_720 = GTK_WIDGET(gtk_builder_get_object (builderG, "edit_box_720"));
    edit_time_1080 = GTK_WIDGET(gtk_builder_get_object (builderG, "edit_time_1080"));
    edit_time_720 = GTK_WIDGET(gtk_builder_get_object (builderG, "edit_time_720"));
    edit_qst_720 = GTK_WIDGET(gtk_builder_get_object (builderG, "preview_question_lbl1"));
    edit_qst_1080 = GTK_WIDGET(gtk_builder_get_object (builderG, "preview_question_lbl"));
    result_top_1080 = GTK_WIDGET(gtk_builder_get_object (builderG, "result_top_1080"));
    result_top_720 = GTK_WIDGET(gtk_builder_get_object (builderG, "result_top_720"));
    result_mid_1080 = GTK_WIDGET(gtk_builder_get_object (builderG, "result_mid_1080"));
    result_mid_720 = GTK_WIDGET(gtk_builder_get_object (builderG, "result_mid_720"));
    time_mid_1080 = GTK_WIDGET(gtk_builder_get_object (builderG, "time_mid_1080"));
    time_mid_720 = GTK_WIDGET(gtk_builder_get_object (builderG, "time_mid_720"));
    answer_1080 = GTK_WIDGET(gtk_builder_get_object (builderG, "answer_1080"));
    answer_720 = GTK_WIDGET(gtk_builder_get_object (builderG, "answer_720"));
    student_1080 = GTK_WIDGET(gtk_builder_get_object (builderG, "student_1080"));
    student_720 = GTK_WIDGET(gtk_builder_get_object (builderG, "student_720"));

    gtk_message_dialog_format_secondary_text (message_dialog, "Image exceeds maximum dimensions (340x192).");
    gtk_widget_show (play_ans_box_720);
    gtk_widget_show (play_time_720);
    gtk_widget_show (play_qst_lbl_720);
    gtk_widget_show (edit_box_720);
    gtk_widget_show (edit_time_720);
    gtk_widget_show (edit_qst_720);
    gtk_widget_show (result_top_720);
    gtk_widget_show (result_mid_720);
    gtk_widget_show (time_mid_720);
    gtk_widget_show (answer_720);
    gtk_widget_show (student_720);
    gtk_widget_hide (play_ans_box_1080);
    gtk_widget_hide (play_time_1080);
    gtk_widget_hide (play_qst_lbl);
    gtk_widget_hide (edit_box_1080);
    gtk_widget_hide (edit_time_1080);
    gtk_widget_hide (edit_qst_1080);
    gtk_widget_hide (result_top_1080);
    gtk_widget_hide (result_mid_1080);
    gtk_widget_hide (time_mid_1080);
    gtk_widget_hide (answer_1080);
    gtk_widget_hide (student_1080);
}


/*  *******************************************************************************
    *                        Set/Reset Global Variables                           *
    ******************************************************************************* */
/**
 * @brief Resets global variables and filename.
 * 
 */
void PARI_reset_global_variables(void) {

    timeG = 0;
    ansG = 0;

    ans_a_G = malloc(200);
    ans_b_G = malloc(200);
    ans_c_G = malloc(200);
    ans_d_G = malloc(200);
    ans_e_G = malloc(200);
    questionG = malloc(200);
    imgG = malloc(1000);

    ans_a_G = "";
    ans_b_G = "";
    ans_c_G = "";
    ans_d_G = "";
    ans_e_G = "";
    questionG = "";
    imgG = "";

    newfileG = TRUE;

    PARI_reset_filename();
}


/**
 * @brief Resets the filename of the Save Screen.
 * 
 */
void PARI_reset_filename(void) {

    GtkFileChooser *chooser;

    chooser = GTK_FILE_CHOOSER(gtk_builder_get_object (builderG, "save_scrn"));

    gtk_file_chooser_set_current_name (chooser, "*.quiz");
}


/**
 * @brief Sets the global variables, based on the Edit Screen.
 * 
 */
void PARI_set_global_variables(void) {

    GtkFileChooser *choose_img;
    GtkEntry *question_entry;
    GtkEntry *ans_a_entry;
    GtkEntry *ans_b_entry;
    GtkEntry *ans_c_entry;
    GtkEntry *ans_d_entry;
    GtkEntry *ans_e_entry;

    choose_img = GTK_FILE_CHOOSER(gtk_builder_get_object (builderG, "choose_img"));
    question_entry = GTK_ENTRY(gtk_builder_get_object (builderG, "question_entry"));
    ans_a_entry = GTK_ENTRY(gtk_builder_get_object (builderG, "ans_a_entry"));
    ans_b_entry = GTK_ENTRY(gtk_builder_get_object (builderG, "ans_b_entry"));
    ans_c_entry = GTK_ENTRY(gtk_builder_get_object (builderG, "ans_c_entry"));
    ans_d_entry = GTK_ENTRY(gtk_builder_get_object (builderG, "ans_d_entry"));
    ans_e_entry = GTK_ENTRY(gtk_builder_get_object (builderG, "ans_e_entry"));

    imgG = gtk_file_chooser_get_filename (choose_img);
    questionG = gtk_entry_get_text (question_entry);
    ans_a_G = gtk_entry_get_text (ans_a_entry);
    ans_b_G = gtk_entry_get_text (ans_b_entry);
    ans_c_G = gtk_entry_get_text (ans_c_entry);
    ans_d_G = gtk_entry_get_text (ans_d_entry);
    ans_e_G = gtk_entry_get_text (ans_e_entry);
}


/*  *******************************************************************************
    *                              Welcome Screen                                 *
    ******************************************************************************* */
/**
 * @brief Initiates the timer for the welcome screen.
 */
void PARI_init_tmr_wlc(void) {

    GtkWidget *wlc_scrn;
 
    wlc_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "wlc_scrn"));
 
    g_timeout_add (1500, PARI_show_menu_scrn, wlc_scrn);
}


/**
 * @brief Hides the welcome screen and shows the main menu screen.
 * 
 * @param  user_data just to be a proper handler.
 * @return Boolean to des-arm the timeout.
 */
gboolean PARI_show_menu_scrn(gpointer user_data) {

    GtkWidget *wlc_scrn;
    GtkWidget *menu_scrn;
    GtkLabel *connection_status_lbl;

    wlc_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "wlc_scrn"));
    menu_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "menu_scrn"));
    connection_status_lbl = GTK_LABEL(gtk_builder_get_object (builderG, "connection_status_lbl"));

    gtk_widget_hide(wlc_scrn);
    gtk_widget_show(menu_scrn);

    return FALSE; // to des-arm the timeout.
}


/*  *******************************************************************************
    *                              Check Image Size                               *
    ******************************************************************************* */
/**
 * @brief Checks image size.
 * 
 * @param img - image to be checked.
 * @return gboolean - TRUE if the image size is allowed. FALSE otherwise. 
 */
gboolean PARI_check_img_size(GtkImage *img) {

    GdkPixbuf *pb = gtk_image_get_pixbuf (img);
    gint width = gdk_pixbuf_get_width(pb);
    gint height = gdk_pixbuf_get_height(pb);

    if (res_widthG >= 1920) {
        if (width > 854)
            return FALSE;
        if (height > 480)
            return FALSE;
    }

    if (res_widthG < 1920) {
        if (width > 340) //128
            return FALSE;
        if (height > 192) //110
            return FALSE;
    }

    return TRUE;
}


/*  *******************************************************************************
    *                                     Save                                    *
    ******************************************************************************* */
/**
 * @brief Saves onto file.
 * 
 * @param filename - name of the file.
 */
void PARI_save(gchar *filename) {

    FILE *fp = fopen(filename, "w");
    if(!fp) 
        return; // error occurred with file opening

    fprintf(fp, "%d\n", timeG);
    fprintf(fp, "%d\n", ansG);
    fprintf(fp, "%s\n", questionG);
    fprintf(fp, "%s\n", imgG);
    fprintf(fp, "%s\n", ans_a_G);
    fprintf(fp, "%s\n", ans_b_G);
    fprintf(fp, "%s\n", ans_c_G);
    fprintf(fp, "%s\n", ans_d_G);
    fprintf(fp, "%s\n", ans_e_G);
    
    fclose(fp); // close file
}


/*  *******************************************************************************
    *                                     Load                                    *
    ******************************************************************************* */
/**
 * @brief Loads file.\n
 *  Adapted from:
 *      https://stackoverflow.com/questions/3501338/c-read-file-line-by-line
 * 
 * @param filename - name of the file to be loaded.
 */
void PARI_load(gchar *filename) {

    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int line_num = 0;

    fp = fopen(filename, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {

        if (line[read-1] == '\n')
            line[read-1] = '\0';

        if (line_num == 0)
            timeG = atoi(line);
        if (line_num == 1)
            ansG = atoi(line);
        if (line_num == 2)
            questionG = line;
        if (line_num == 3) {
            imgG = line;
            PARI_load_img();
        }
        if (line_num == 4)
            ans_a_G = line;
        if (line_num == 5)
            ans_b_G = line;
        if (line_num == 6)
            ans_c_G = line;
        if (line_num == 7)
            ans_d_G = line;
        if (line_num == 8)
            ans_e_G = line;

        line_num++;
        PARI_set_load();
    } 
}


/**
 * @brief Sets parameters loaded.
 *  
 */
void PARI_set_load(void) {

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

    gtk_entry_set_text (question_entry, questionG);
    gtk_entry_set_text (ans_a_entry, ans_a_G);
    gtk_entry_set_text (ans_b_entry, ans_b_G);
    gtk_entry_set_text (ans_c_entry, ans_c_G);
    gtk_entry_set_text (ans_d_entry, ans_d_G);
    gtk_entry_set_text (ans_e_entry, ans_e_G);
    gtk_spin_button_set_value (time_spin, timeG);
    if (ansG == 0) {
        gtk_toggle_button_set_active (check_a, FALSE);
        gtk_toggle_button_set_active (check_b, FALSE);
        gtk_toggle_button_set_active (check_c, FALSE);
        gtk_toggle_button_set_active (check_d, FALSE);
        gtk_toggle_button_set_active (check_e, FALSE);
    }
    if (ansG == 1)
        gtk_toggle_button_set_active (check_a, TRUE);
    if (ansG == 2)
        gtk_toggle_button_set_active (check_b, TRUE);
    if (ansG == 3)
        gtk_toggle_button_set_active (check_c, TRUE);
    if (ansG == 4)
        gtk_toggle_button_set_active (check_d, TRUE);
    if (ansG == 5)
        gtk_toggle_button_set_active (check_e, TRUE);

    PARI_play_scrn_set(); 
}


/**
 * @brief Loads the image on both the Edit Screen and Play Screen.
 * 
 */
void PARI_load_img(void) {

    GtkFileChooser *choose_img;
    GtkWidget *img_widget;
    GtkImage *img;
    GtkWidget *play_img_widget;
    GtkImage *play_img;    
    GtkWidget *error_scrn;

    choose_img = GTK_FILE_CHOOSER(gtk_builder_get_object (builderG, "choose_img"));
    img = GTK_IMAGE(gtk_builder_get_object (builderG, "preview_img"));
    img_widget = GTK_WIDGET(gtk_builder_get_object (builderG, "preview_img"));
    play_img = GTK_IMAGE(gtk_builder_get_object (builderG, "play_img"));
    play_img_widget = GTK_WIDGET(gtk_builder_get_object (builderG, "play_img"));
    error_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "error_img_scrn"));

    gtk_file_chooser_unselect_all (choose_img);
    gtk_file_chooser_set_filename (choose_img, imgG);

    gtk_image_set_from_file (img, imgG);
    gtk_widget_hide(img_widget);
    gtk_image_set_from_file (play_img, imgG);
    gtk_widget_hide(play_img_widget);

    size_t str_length = strlen(imgG);
    if (imgG[str_length-1] != ')') {
        gtk_widget_show(img_widget);
        gtk_widget_show(play_img_widget);
    }
}


/*  *******************************************************************************
    *                              Server Functions                               *
    ******************************************************************************* */

/**
 * @brief Sets the state of the global variables bases on server status.
 *  Used to catch signals.
 * 
 * @param signum - signal ID.
 */
void PARI_server_on(int signum) {

    if (server_onG == FALSE) {
        server_onG = TRUE;
        infinite_loopG = TRUE;
    }
    else {
        server_onG = FALSE;
        infinite_loopG = FALSE;
    }
}


/**
 * @brief Executes when the client is connected, or a valid RFID card is presented to the remote system.
 *  Used to catch signals.
 * 
 * @param signum - signal ID.
 */
void PARI_client_connected(int signum) {

    GtkWidget *play_btn;
    GtkLabel *connection_status_lbl;
    GtkLabel *edit_con_status_lbl;
    GtkLabel *student_lbl;
    GtkLabel *time_result_lbl;
    gchar *str = "Client connected!";
    const gchar *str2 = malloc(200);

    play_btn = GTK_WIDGET(gtk_builder_get_object (builderG, "play_scrn_play_btn"));
    connection_status_lbl = GTK_LABEL(gtk_builder_get_object (builderG, "connection_status_lbl"));
    edit_con_status_lbl = GTK_LABEL(gtk_builder_get_object (builderG, "edit_con_status_lbl"));
    student_lbl = GTK_LABEL(gtk_builder_get_object (builderG, "student_lbl"));
    time_result_lbl = GTK_LABEL(gtk_builder_get_object (builderG, "time_result_lbl"));

    str2 = gtk_label_get_text (connection_status_lbl);
    if (str2[0] == 67) {
        gtk_label_set_text (student_lbl, "João Moreira"); // because only my student card is allowed!
        gtk_label_set_text (time_result_lbl, "");
    }
    else {
        gtk_widget_set_sensitive (play_btn, TRUE);
        gtk_label_set_text (connection_status_lbl, str);
        gtk_label_set_text (edit_con_status_lbl, str);
    }
}


/**
 * @brief Executes when an error occurs starting the server, or a button is pressed on the remote system.
 *  Used to catch signals.
 * 
 * @param signum - signal ID.
 */
void PARI_server_error(int signum) {

    GtkWidget *play_btn;
    GtkWidget *btn_1;
    GtkWidget *btn_2;
    GtkLabel *connection_status_lbl;
    GtkLabel *edit_con_status_lbl;
    GtkLabel *time_result_lbl;
    GtkLabel *prev_time_lbl;
    gchar *str = "An error occurred starting the server. Please restart the application.";
    const gchar *str2 = malloc(200);
    gchar *str3 = malloc(200);
    gint t;

    play_btn = GTK_WIDGET(gtk_builder_get_object (builderG, "play_scrn_play_btn"));
    btn_1 = GTK_WIDGET(gtk_builder_get_object (builderG, "menu_new_btn"));
    btn_2 = GTK_WIDGET(gtk_builder_get_object (builderG, "menu_play_btn"));
    connection_status_lbl = GTK_LABEL(gtk_builder_get_object (builderG, "connection_status_lbl"));
    edit_con_status_lbl = GTK_LABEL(gtk_builder_get_object (builderG, "edit_con_status_lbl"));
    time_result_lbl = GTK_LABEL(gtk_builder_get_object (builderG, "time_result_lbl"));
    prev_time_lbl = GTK_LABEL(gtk_builder_get_object (builderG, "prev_time_lbl"));

    str2 = gtk_label_get_text (connection_status_lbl);
    t = atoi(gtk_label_get_text (prev_time_lbl));

    if (str2[0] == 67) {
        sprintf(str3, "%d", t-timeG);
        gtk_label_set_text (time_result_lbl, str3);
    }
    else {
        gtk_widget_set_sensitive (play_btn, TRUE);
        gtk_widget_set_sensitive (btn_1, FALSE);
        gtk_widget_set_sensitive (btn_2, FALSE);
        gtk_label_set_text (connection_status_lbl, str);
        gtk_label_set_text (edit_con_status_lbl, str);
    }
}


/*  *******************************************************************************
    *                           Play Screen Functions                             *
    ******************************************************************************* */
/**
 * @brief Sets the Play Screen (answers, image, question and time).
 * 
 */
void PARI_play_scrn_set(void) {

    GtkLabel *preview_question_lbl;
    GtkLabel *prev_a_lbl;
    GtkLabel *prev_b_lbl;
    GtkLabel *prev_c_lbl;
    GtkLabel *prev_d_lbl;
    GtkLabel *prev_e_lbl;
    GtkLabel *prev_time_lbl;
    GtkWidget *prev_img_widget;
    GtkImage *prev_img;

    GtkLabel *play_qst_lbl;
    GtkLabel *play_qst_lbl_720;
    GtkLabel *play_ans_a_lbl;
    GtkLabel *play_ans_b_lbl;
    GtkLabel *play_ans_c_lbl;
    GtkLabel *play_ans_d_lbl;
    GtkLabel *play_ans_e_lbl;
    GtkLabel *play_ans_a_lbl1;
    GtkLabel *play_ans_b_lbl1;
    GtkLabel *play_ans_c_lbl1;
    GtkLabel *play_ans_d_lbl1;
    GtkLabel *play_ans_e_lbl1;
    GtkLabel *play_time_lbl;
    GtkLabel *play_time_lbl1;
    GtkWidget *img_widget;
    GtkImage *img;


    preview_question_lbl = GTK_LABEL(gtk_builder_get_object (builderG, "preview_question_lbl"));
    prev_a_lbl = GTK_LABEL(gtk_builder_get_object (builderG, "prev_a_lbl"));
    prev_b_lbl = GTK_LABEL(gtk_builder_get_object (builderG, "prev_b_lbl"));
    prev_c_lbl = GTK_LABEL(gtk_builder_get_object (builderG, "prev_c_lbl"));
    prev_d_lbl = GTK_LABEL(gtk_builder_get_object (builderG, "prev_d_lbl"));
    prev_e_lbl = GTK_LABEL(gtk_builder_get_object (builderG, "prev_e_lbl"));
    prev_time_lbl = GTK_LABEL(gtk_builder_get_object (builderG, "prev_time_lbl"));
    prev_img = GTK_IMAGE(gtk_builder_get_object (builderG, "preview_img"));
    prev_img_widget = GTK_WIDGET(gtk_builder_get_object (builderG, "preview_img"));

    play_qst_lbl = GTK_LABEL(gtk_builder_get_object (builderG, "play_qst_lbl"));
    play_qst_lbl_720 = GTK_LABEL(gtk_builder_get_object (builderG, "play_qst_lbl_720"));
    play_ans_a_lbl = GTK_LABEL(gtk_builder_get_object (builderG, "play_ans_a_lbl"));
    play_ans_b_lbl = GTK_LABEL(gtk_builder_get_object (builderG, "play_ans_b_lbl"));
    play_ans_c_lbl = GTK_LABEL(gtk_builder_get_object (builderG, "play_ans_c_lbl"));
    play_ans_d_lbl = GTK_LABEL(gtk_builder_get_object (builderG, "play_ans_d_lbl"));
    play_ans_e_lbl = GTK_LABEL(gtk_builder_get_object (builderG, "play_ans_e_lbl"));
    play_ans_a_lbl1 = GTK_LABEL(gtk_builder_get_object (builderG, "play_ans_a_lbl1"));
    play_ans_b_lbl1 = GTK_LABEL(gtk_builder_get_object (builderG, "play_ans_b_lbl1"));
    play_ans_c_lbl1 = GTK_LABEL(gtk_builder_get_object (builderG, "play_ans_c_lbl1"));
    play_ans_d_lbl1 = GTK_LABEL(gtk_builder_get_object (builderG, "play_ans_d_lbl1"));
    play_ans_e_lbl1 = GTK_LABEL(gtk_builder_get_object (builderG, "play_ans_e_lbl1"));
    play_time_lbl = GTK_LABEL(gtk_builder_get_object (builderG, "play_time_lbl"));
    play_time_lbl1 = GTK_LABEL(gtk_builder_get_object (builderG, "play_time_lbl1"));
    img = GTK_IMAGE(gtk_builder_get_object (builderG, "play_img"));
    img_widget = GTK_WIDGET(gtk_builder_get_object (builderG, "play_img"));


    gtk_label_set_text (play_qst_lbl, gtk_label_get_text (preview_question_lbl));
    gtk_label_set_text (play_qst_lbl_720, gtk_label_get_text (preview_question_lbl));
    gtk_label_set_text (play_ans_a_lbl, gtk_label_get_text (prev_a_lbl));
    gtk_label_set_text (play_ans_b_lbl, gtk_label_get_text (prev_b_lbl));
    gtk_label_set_text (play_ans_c_lbl, gtk_label_get_text (prev_c_lbl));
    gtk_label_set_text (play_ans_d_lbl, gtk_label_get_text (prev_d_lbl));
    gtk_label_set_text (play_ans_e_lbl, gtk_label_get_text (prev_e_lbl));
    gtk_label_set_text (play_ans_a_lbl1, gtk_label_get_text (prev_a_lbl));
    gtk_label_set_text (play_ans_b_lbl1, gtk_label_get_text (prev_b_lbl));
    gtk_label_set_text (play_ans_c_lbl1, gtk_label_get_text (prev_c_lbl));
    gtk_label_set_text (play_ans_d_lbl1, gtk_label_get_text (prev_d_lbl));
    gtk_label_set_text (play_ans_e_lbl1, gtk_label_get_text (prev_e_lbl));
    gtk_label_set_text (play_time_lbl, gtk_label_get_text (prev_time_lbl));
    gtk_label_set_text (play_time_lbl1, gtk_label_get_text (prev_time_lbl));
}


/**
 * @brief Updates the timer on the Play Screen.
 * 
 * @param  user_data just to be a proper handler.
 * @return Boolean to des-arm the timer-updater.
 */
gboolean PARI_update_timer(gpointer user_data) {

    GtkWidget *play_button;
    GtkWidget *results_button;
    GtkWidget *back_btn;
    GtkLabel *play_time_lbl;
    GtkLabel *play_time_lbl1;
    gchar *str = malloc(200);

    play_time_lbl = GTK_LABEL(gtk_builder_get_object (builderG, "play_time_lbl"));
    play_time_lbl1 = GTK_LABEL(gtk_builder_get_object (builderG, "play_time_lbl1"));
    play_button = GTK_WIDGET(gtk_builder_get_object (builderG, "play_scrn_play_btn"));
    results_button = GTK_WIDGET(gtk_builder_get_object (builderG, "results_btn"));
    back_btn = GTK_WIDGET(gtk_builder_get_object (builderG, "play_scrn_back_btn"));

    timeG = timeG-1;

    sprintf(str, "%d", timeG);
    gtk_label_set_text (play_time_lbl, str);
    gtk_label_set_text (play_time_lbl1, str);

    g_free(str);

    if (timeG <= 0) {
        gtk_widget_hide(play_button);
        gtk_widget_show(results_button);
        gtk_widget_set_sensitive (back_btn, TRUE);
        return FALSE;
    }

    return TRUE;
}


/*  *******************************************************************************
    *                          Result Screen Functions                            *
    ******************************************************************************* */

/**
 * @brief Converts the string received from the client ("1", "2"...) to 
 *  the string displayed ("a)", "b)"...).
 * 
 * @param str -  string received from client (answer).
 * @return gchar* - string to be displayed.
 */
gchar *PARI_convert_ans(gchar *str) {

    gchar *ans_str = malloc(200);

    if (str[0] == 49)
        ans_str = "a)";
    if (str[0] == 50)
        ans_str = "b)";
    if (str[0] == 51)
        ans_str = "c)";
    if (str[0] == 52)
        ans_str = "d)";
    if (str[0] == 53)
        ans_str = "e)";

    return ans_str;
}