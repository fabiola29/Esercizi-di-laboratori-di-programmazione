#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


int main() {

    FILE *fp, *fpOut;
    Partita *head;

    fp = fopen("dati.txt", "r"); //se non va, provi a cambiare il folder, ho messo solo il nome del file perche mi sembra palese che avremmo percorsi diversi
    if(fp == NULL) gestisci_errore(0);

    fpOut = fopen("out.txt", "w");
    if(fpOut == NULL) gestisci_errore(0);

    head = leggiFile(fp);
    fclose(fp);

    stampaLista(head);
    stampaVincitori(head);
    maggiorNumeroPartiteVinte(head);
    eliminaPartite(head, 'A');
    puts("\n\nLa lista senza le partite vinte dal giocatore A");

    stampaLista(head);

    scriviFile(fpOut, head);
    fclose(fpOut);

    freeLista(head);

    return 0;
}
