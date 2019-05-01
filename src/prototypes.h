/*File generated automatically in joao-linux by joao on qua jan 30 22:11:30 WET 2019*/
#ifdef __cplusplus
extern "C" {
#endif
/* callbacks_warnings.c */
void on_cancel_btn_1_clicked (void);
/* callbacks_main_menu.c */
void on_menu_new_btn_clicked (void);
void on_menu_play_btn_clicked (void);
/* callbacks_play_scrn.c */
void on_play_scrn_back_btn_clicked (void);
void on_play_scrn_play_btn_clicked (void);
void on_results_btn_clicked (void);
/* interface_main.c */
int interface_main (int argc, char *argv[]);
/* callbacks_edit_file.c */
void on_cancel_btn_2_clicked (void);
void on_cancel_btn_3_clicked (void);
void on_cancel_btn_5_clicked (void);
void on_cancel_btn_6_clicked (void);
void on_file_load_btn_activate (void);
void on_file_new_btn_activate (void);
void on_file_quit_btn_activate (void);
void on_file_save_as_btn_activate (void);
void on_file_save_btn_activate (void);
void on_ok_btn_2_clicked (void);
void on_ok_btn_3_clicked (void);
void on_ok_btn_4_clicked (void);
void on_ok_btn_5_clicked (void);
void on_ok_btn_6_clicked (void);
/* main.c */
int main (int argc, char *argv[]);
/* callbacks_edit_scrn.c */
void on_ans_a_check_toggled (void);
void on_ans_a_entry_changed (void);
void on_ans_b_check_toggled (void);
void on_ans_b_entry_changed (void);
void on_ans_c_check_toggled (void);
void on_ans_c_entry_changed (void);
void on_ans_d_check_toggled (void);
void on_ans_d_entry_changed (void);
void on_ans_e_check_toggled (void);
void on_ans_e_entry_changed (void);
void on_back_btn_1_clicked (void);
void on_choose_img_file_set (void);
void on_clean_btn_1_clicked (void);
void on_ok_btn_1_clicked (void);
void on_question_entry_changed (void);
void on_time_spin_value_changed (void);
/* interface_properties.c */
void PARI_set_all_scrn_properties (void);
void PARI_set_edit_scrn_properties (void);
void PARI_set_load_scrn_properties (void);
void PARI_set_menu_scrn_properties (void);
void PARI_set_play_scrn_properties (void);
void PARI_set_results_scrn_properties (void);
void PARI_set_save_scrn_properties (void);
void PARI_set_wlc_scrn_properties (void);
/* interface_functions.c */
void PARI_change_resolution (void);
gboolean PARI_check_img_size (GtkImage * img);
void PARI_check_resolution (void);
void PARI_client_connected (int signum);
gchar *PARI_convert_ans (gchar * str);
void PARI_init_tmr_wlc (void);
void PARI_load (gchar * filename);
void PARI_load_img (void);
void PARI_play_scrn_set (void);
void PARI_reset_filename (void);
void PARI_reset_global_variables (void);
void PARI_save (gchar * filename);
void PARI_server_error (int signum);
void PARI_server_on (int signum);
void PARI_set_global_variables (void);
void PARI_set_load (void);
gboolean PARI_show_menu_scrn (gpointer user_data);
gboolean PARI_update_timer (gpointer user_data);
/* callbacks_results_scrn.c */
void on_home_btn_clicked (void);
/* destroy_signals.c */
gboolean PARI_delete_event (GtkWidget * window, GdkEvent * event, gpointer data);
void PARI_destroy (GtkWidget * window, gpointer data);
void PARI_intercept_ctrl_c (int a);
#ifdef __cplusplus
}
#endif
