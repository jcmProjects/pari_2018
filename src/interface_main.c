/**
 * @file interface_main.c
 * @author João Moreira (jcmoreira@ua.pt)
 * @brief Main function of the interface.
 * @date 2019-01-25
 * 
 */

// Includes
#include <signal.h>
#include "quiz.h"

/**
 * @brief Main function of the interface, responsible for starting the interface and connecting signals to callbacks.
 * 
 * @param argc - inherited from main. not really used.
 * @param argv - inherited from main. not really used.
 * @return int - will return '0' when exiting normally.
 */
int interface_main(int argc, char *argv[]) {

    char *gladeFile = (char *)"./interface.glade";
    int ret;

    gtk_init (&argc, &argv);

    builderG = gtk_builder_new();

    /* load the interface from a file */
    ret = gtk_builder_add_from_file (builderG, gladeFile, NULL);
    if (!ret) {
        g_print ("%s file was not found. Aborting!\n", gladeFile);
        return 0;
    }

    /* connect the signals in the interface */
    gtk_builder_connect_signals (builderG, NULL);

    GtkWidget *menu_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "menu_scrn"));
    GtkWidget *edit_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "edit_scrn"));
    GtkWidget *server_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "server_scrn"));
    GtkWidget *results_scrn = GTK_WIDGET(gtk_builder_get_object (builderG, "results_scrn"));

    /* connect the desired interface signals - normally at window level */
    if (menu_scrn) {
        g_signal_connect(G_OBJECT(menu_scrn), "delete-event", G_CALLBACK(PARI_delete_event), NULL);
        g_signal_connect(G_OBJECT(menu_scrn), "destroy", G_CALLBACK(PARI_destroy), NULL);
    }
    if (edit_scrn) {
        g_signal_connect(G_OBJECT(edit_scrn), "delete-event", G_CALLBACK(PARI_delete_event), NULL);
        g_signal_connect(G_OBJECT(edit_scrn), "destroy", G_CALLBACK(PARI_destroy), NULL);
    }
    if (server_scrn) {
        g_signal_connect(G_OBJECT(server_scrn), "delete-event", G_CALLBACK(PARI_delete_event), NULL);
        g_signal_connect(G_OBJECT(server_scrn), "destroy", G_CALLBACK(PARI_destroy), NULL);
    }
    if (results_scrn) {
        g_signal_connect(G_OBJECT(results_scrn), "delete-event", G_CALLBACK(PARI_delete_event), NULL);
        g_signal_connect(G_OBJECT(results_scrn), "destroy", G_CALLBACK(PARI_destroy), NULL);
    }

    /* set windows properties */
    PARI_set_all_scrn_properties();
    PARI_init_tmr_wlc();

    /* use signal to catch SIGINT  (CTRL-C) */
    signal(SIGINT, PARI_intercept_ctrl_c);

    /* start the event loop */
    gtk_main();

    return 0;
}
