#ifndef Studenti_h
#define Studenti_h

#include <stdio.h>

#define MAX_STUDENTI 2

struct alunni {
    char classe[2];
    int studenti;
    int promossi;
    int bocciati;
    int rimandati;
    struct alunni *next;
};

struct alunni *leggiFile(FILE * input);
struct alunni *inserisciCoda(struct alunni * lista, struct alunni * alunni);
void stampaLista(struct alunni * lista, FILE *stream);
struct alunni * eliminaAlunni(struct alunni * lista);
void scriviFile(FILE *fp, struct alunni  *lista);
struct alunni * ordinaLista(struct alunni * lista);
#endif /* Studenti_h */
