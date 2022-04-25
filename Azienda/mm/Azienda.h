#ifndef Azienda_h
#define Azienda_h
#define MAXLEN 64

#include <stdio.h>

struct Azienda{
    char nomeAzienda[MAXLEN];
    int dipendenti;
    int dipartimenti;
    int sedi;
    struct Azienda *next;
};

struct Azienda *leggiFile(FILE * input);
struct Azienda *inserisciCoda(struct Azienda * lista, struct Azienda * Azienda);
void stampaLista(struct Azienda * lista, FILE *stream);
struct Azienda *ordinaLista(struct Azienda * lista);
struct Azienda * eliminaPuntMinore(struct Azienda * lista, int num_dipendenti);
void scriviFile(FILE *fp, struct Azienda *lista);

#endif /* Azienda_h */
