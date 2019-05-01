/**
 * @file callbacks_play_scrn.c
 * @author João Moreira (jcmoreira@ua.pt)
 * @brief Callbacks associated with the Play Screen.
 * @date 2019-01-25
 * 
 */

// Includes
#include <stdlib.h>
#include "quiz.h"


/**
 * @brief Callback to Play Screen's back button.
 * 
 */
void on_play_scrn_back_btn_clicked(void) {

    GtkWidget *edit_scrn;
    GtkWidget *play_scrn;

    edit_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "edit_scrn"));
    play_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "play_scrn"));

    gtk_widget_hide(play_scrn);
    gtk_widget_show(edit_scrn);
}


/**
 * @brief Callback to Play Screen's play button.
 * 
 */
void on_play_scrn_play_btn_clicked(void) {

    GtkWidget *play_scrn;
    GtkWidget *play_btn;
    GtkWidget *back_btn;
    GtkLabel *play_time_lbl;
    GtkLabel *result_ans_lbl;
    GtkLabel *student_lbl;
    GtkLabel *time_result_lbl;
    const gchar *timer_str;
    gchar *str = malloc(200);
    gint t;

    play_time_lbl = GTK_LABEL(gtk_builder_get_object (builderG, "play_time_lbl"));
    play_btn = GTK_WIDGET(gtk_builder_get_object (builderG, "play_scrn_play_btn"));
    play_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "play_scrn"));
    back_btn = GTK_WIDGET(gtk_builder_get_object (builderG, "play_scrn_back_btn"));
    result_ans_lbl = GTK_LABEL(gtk_builder_get_object (builderG, "result_ans_lbl"));
    student_lbl = GTK_LABEL(gtk_builder_get_object (builderG, "student_lbl"));
    time_result_lbl = GTK_LABEL(gtk_builder_get_object (builderG, "time_result_lbl"));

    timer_str = gtk_label_get_text (play_time_lbl);
    gtk_label_set_text (result_ans_lbl, "");
    gtk_label_set_text (student_lbl, "");
    gtk_label_set_text (time_result_lbl, "");

    PARI_shm_write("");

    t = atoi(timer_str);
    sprintf(str, "%d", t);
    timeG = t;

    gtk_widget_set_sensitive (play_btn, FALSE);
    gtk_widget_set_sensitive (back_btn, FALSE);
    g_timeout_add (1000, PARI_update_timer, play_scrn);

    g_free(str);
}


/**
 * @brief Callback to Play Screen's forward button.
 * 
 */
void on_results_btn_clicked(void) {

    GtkWidget *results_scrn;
    GtkWidget *play_scrn;
    GtkWidget *right_ans_img;
    GtkWidget *wrong_ans_img;
    GtkWidget *play_btn;
    GtkWidget *results_btn;
    GtkLabel *result_ans_lbl;
    GtkLabel *student_lbl;
    gchar *str = malloc(200);
    gchar *ans_str = malloc(200);
    const gchar *str2 = malloc(200);
    char num;

    results_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "results_scrn"));
    play_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "play_scrn"));
    right_ans_img = GTK_WIDGET(gtk_builder_get_object (builderG, "right_ans_img"));
    wrong_ans_img = GTK_WIDGET(gtk_builder_get_object (builderG, "wrong_ans_img"));
    play_btn = GTK_WIDGET(gtk_builder_get_object (builderG, "play_scrn_play_btn"));
    results_btn = GTK_WIDGET(gtk_builder_get_object (builderG, "results_btn"));
    result_ans_lbl = GTK_LABEL(gtk_builder_get_object (builderG, "result_ans_lbl"));
    student_lbl = GTK_LABEL(gtk_builder_get_object (builderG, "student_lbl"));

    str = PARI_shm_read();
    ans_str = PARI_convert_ans(str);

    str2 = gtk_label_get_text (student_lbl);

    if (str2[0] == 74) {
        // 97 = a, 98 = b, etc...
        if ( (ans_str[0] == 97) || (ans_str[0] == 98) || (ans_str[0] == 99) || (ans_str[0] == 100) || (ans_str[0] == 101) )
            gtk_label_set_text (result_ans_lbl, ans_str);

        num = atoi(str);
        if (num == ansG)
            gtk_widget_show(right_ans_img);
        else
            gtk_widget_show(wrong_ans_img);
    }

    gtk_widget_hide(play_scrn);
    gtk_widget_show(results_scrn);
    gtk_widget_hide(results_btn);
    gtk_widget_show(play_btn);
    gtk_widget_set_sensitive (play_btn, TRUE);
}