#ifndef Partite_h
#define Partite_h

#define MAXLEN 15

#include <stdio.h>

struct partite{
    char NomeSquadre[MAXLEN];
    int Punteggio;
    int PartiteGiocate;
    int PartiteVinte;
    int PartitePareggiate;
    int PartitePerse;
    struct partite *next;
};

struct partite *leggiFile(FILE * input);
struct partite *inserisciCoda(struct partite * lista, struct partite *partite);
void stampaLista(struct partite * lista, FILE *stream);
struct partite *ordinaLista(struct partite * lista);
struct partite *eliminaPuntMinore(struct partite * lista, int num_punti);
void scriviFile(FILE *fp, struct partite *lista);

#endif /* Partite_h */

