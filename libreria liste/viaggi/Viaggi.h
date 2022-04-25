#ifndef Viaggi_h
#define Viaggi_h

#include <stdio.h>

#define NOME 10

struct elem{
    char nome[NOME];
    int eta;
    int viaggi;
    struct elem *next;
};

typedef struct elem* List;

// Stampa il file
struct elem *leggiFile(FILE *fp, struct elem *lista);
struct elem * inserisciLista(struct elem * lista, struct elem * elem);/*serve per stampare il file*/
void stampaLista(struct elem * lista, FILE *stream); /*serve per stampare il file*/
void scriviFile(FILE *fp, struct elem *lista); /*serve per scrivere i risultati su un'altro file*/
void freeLista(struct elem *lista);
void freeNodo(struct elem *nodo);
void gestioneErrore(void);
struct elem * eliminaViaggi(struct elem *lista, int num_viaggi);/*serve per eliminare*/
struct elem *duplicaElementi(struct elem *lista);/*serve per duplicere gli elementi*/
struct elem * ordinaLista(struct elem * lista); /*ordinamento della lista secondo il numero di viaggi*/
struct elem *inserimentoInCoda(struct elem *lista, char nome[NOME], int eta, int viaggi);
List inserimentoInTesta(List L,  char nome[NOME], int eta, int viaggi);
struct elem *rimuoviDuplicati(struct elem *lista);
struct elem *rimuoviNodo(struct elem *lista, struct elem *nodo);

#endif/* Viaggi_h */
