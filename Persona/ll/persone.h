#ifndef persone_h
#define persone_h

#include <stdio.h>

#define MAXLEN 15


struct Persona{
    char nome[MAXLEN];
    char cognome[MAXLEN];
    int peso;
    int altezza;
    int eta;
    struct Persona *next;
};

struct Persona *leggiFile(FILE * input);
struct Persona *inserisciCoda(struct Persona * lista, struct Persona * Persona);
void stampaLista(struct Persona * lista, FILE *stream);
struct Persona *ordinaLista(struct Persona * lista);
struct Persona * eliminaPeso(struct Persona * lista, int num_peso);
struct Persona *duplicaNodo(struct Persona *nodo);
struct Persona *duplicaElementi(struct Persona *lista);
void scriviLista(struct Persona *lista);
void scriviFile(FILE *fp, struct Persona *lista);
#endif /* persone_h */
