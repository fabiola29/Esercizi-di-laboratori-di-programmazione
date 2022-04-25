#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void gestisci_errore(int i) {

    if(i == 1) {
        printf("Memoria non allocata");
        exit(-1);
    }

    if(i == 0) {
        printf("File non aperto");
        exit(-1);
    }
}

static Partita *creaNodo(char faccia, int a, int b) {

    Partita *tmp = NULL;

    tmp = (Partita*) malloc(sizeof(Partita));
    if(tmp == NULL) gestisci_errore(1);

    tmp->moneta = faccia;
    tmp->dadoA = a;
    tmp->dadoB = b;
    tmp->next = NULL;

    return tmp;
}

static Partita *inserisciInCoda(Partita *head, char faccia, int a, int b) {

    if(head == NULL) return creaNodo(faccia, a, b);
    head->next = inserisciInCoda(head->next, faccia, a, b);
    return head;
}

void freeLista(Partita *head) {

    if(head != NULL) {

        freeLista(head->next);
        free(head);
    }
}

void stampaLista(Partita *head) {

    while(head != NULL) {

        printf("%c %d %d\n", head->moneta, head->dadoA, head->dadoB);
        head = head->next;
    }
}

Partita *leggiFile(FILE *fp) {

    Partita *tmp = NULL;
    char faccia;
    int a, b;
    while(fscanf(fp, "%c %d %d\n", &faccia, &a, &b) == 3) {

        tmp = inserisciInCoda(tmp, faccia, a, b);
    }

    return tmp;
}

static char vincitore(Partita *head) {

    char r;

    if(head->dadoA == head->dadoB){
        r = 'P';
    }

    else if (head->moneta == 'c'){
        if(head->dadoA < head->dadoB){
            r = 'A';
        } else {
            r = 'B';
        }

    }
    else if (head->moneta == 't'){
        if(head->dadoA > head->dadoB){
            r = 'A';
        } else {
            r = 'B';
        }
    }

    return r;
}

void stampaVincitori(Partita *head) {

    printf("La sequenza dei vincitori e'");

    while(head != NULL) {

        printf(" %c", vincitore(head));
        head = head->next;
    }
    puts("");
}

void maggiorNumeroPartiteVinte(Partita *head) {

    int a = 0, b = 0;

    while(head != NULL) {

        if(vincitore(head) == 'A') a++;
        else if(vincitore(head) == 'B') b++;

        head = head->next;
    }

    if(a > b) printf("Il giocatore A ha vinto più partite (A: %d B: %d)", a, b);
    if(a < b) printf("Il giocatore B ha vinto più partite (A: %d B: %d)", a, b);
    if(a == b) printf("I giocatori sono in parità (A: %d B: %d)", a, b);
}

Partita *eliminaPartite(Partita *head, char g) {

    Partita *tmp;
    if(head == NULL) return head;

    if(vincitore(head) == g) {
        tmp = head->next;
        free(head);
        return eliminaPartite(tmp, g);
    }

    head->next = eliminaPartite(head->next, g);
    return head;
}

void scriviFile(FILE *fp, Partita *head) {

    while(head != NULL) {

        fprintf(fp, "%c %d %d\n", head->moneta, head->dadoA, head->dadoB);
        head = head->next;

    }
}






