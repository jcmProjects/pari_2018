/**
 * @file callbacks_results_scrn.c
 * @author João Moreira (jcmoreira@ua.pt)
 * @brief Callbacks associated with the Results Screen.
 * @date 2019-01-25
 * 
 */

#include "quiz.h"

/**
 * @brief Callback to home button on Results Screen.
 * 
 */
void on_home_btn_clicked(void) {

    GtkWidget *results_scrn;
    GtkWidget *menu_scrn;
    GtkWidget *right_ans_img;
    GtkWidget *wrong_ans_img;

    results_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "results_scrn"));
    menu_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "menu_scrn"));
    right_ans_img = GTK_WIDGET(gtk_builder_get_object (builderG, "right_ans_img"));
    wrong_ans_img = GTK_WIDGET(gtk_builder_get_object (builderG, "wrong_ans_img"));

    gtk_widget_hide(results_scrn);
    gtk_widget_show(menu_scrn);

    gtk_widget_hide(right_ans_img);
    gtk_widget_hide(wrong_ans_img);
}