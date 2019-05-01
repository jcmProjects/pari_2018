/*File generated automatically in joao-linux by joao on sex jan 25 18:05:09 WET 2019*/
#ifdef __cplusplus
extern "C" {
#endif
/* server.c */
void PARI_my_error (const char *msg);
void PARI_process_client (int sock, char *clientID);
void PARI_server_kill (int signum);
int PARI_server_main (int argc, char *argv[]);
void PARI_start_server (void);
#ifdef __cplusplus
}
#endif
