#ifndef funzioni_h
#define funzioni_h
#include <stdio.h>

#define MAXLEN 64

struct Cibi{
    char nome[MAXLEN];
    char unitaDiMisura[1];
    float quantita;
    char commenti[MAXLEN];
    struct Cibi *next;
};

struct Cibi *leggiFile(FILE * input);
struct Cibi *inserisciCoda(struct Cibi * lista, struct Cibi * Cibi);
void stampaLista(struct Cibi * lista, FILE *stream);
void scriviLista(struct Cibi *lista);
void scriviFile(FILE *fp, struct Cibi *lista);
#endif
