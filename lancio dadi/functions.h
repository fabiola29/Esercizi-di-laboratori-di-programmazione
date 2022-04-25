typedef struct P {
    char moneta;
    int dadoA, dadoB;
    struct P *next;
}Partita;


void gestisci_errore(int i);
void stampaLista(Partita *head);
void freeLista(Partita *head);
Partita *leggiFile(FILE *fp);
void stampaVincitori(Partita *head);
void maggiorNumeroPartiteVinte(Partita *head);
Partita *eliminaPartite(Partita *head, char g);
void scriviFile(FILE *fp, Partita *head);