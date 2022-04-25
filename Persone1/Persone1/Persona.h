#ifndef Persona_h
#define Persona_h

#include <stdio.h>

#define NOME 10
#define COGNOME 10

struct elem{
    char Nome[10];
    char Cognome[15];
    int Peso;
    int Altezza;
    int Eta;
    struct elem *next;
};

struct elem *leggiFile(FILE * input);
struct elem *inserisciCoda(struct elem * lista, struct elem * elem);
void stampaLista(struct elem * lista, FILE *stream);
struct elem *ordinaLista(struct elem * lista);
struct elem * eliminaEta(struct elem *lista, int num_eta);
struct elem *duplicaNodo(struct elem *nodo);
struct elem *duplicaElementi(struct elem *lista);
void scriviLista(struct elem *lista);
void freeNodo(struct elem*nodo);
struct elem * eliminaEta1(struct elem *lista, int num_eta1);
void scriviFile(FILE *fp, struct elem *lista);
#endif /* Persona_h */
