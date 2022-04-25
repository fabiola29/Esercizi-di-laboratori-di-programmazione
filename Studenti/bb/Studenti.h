#ifndef Studenti_h
#define Studenti_h


#define MAXLEN 10
#define NOME_ESAME 20



#include <stdio.h>

struct Studente{
    char nome[MAXLEN];
    char cognome[MAXLEN];
    int matricola;
    char esame[NOME_ESAME];
    int voto;
    struct Studente *next;
};

struct Studente *leggiFile(FILE * input);
struct Studente *inserisciCoda(struct Studente * lista, struct Studente * Studente);
void stampaLista(struct Studente * lista, FILE *stream);
struct Studente *ordinaLista(struct Studente * lista);
struct Studente * eliminaPuntMinore(struct Studente * lista, int eta_studente);
void scriviFile(FILE *output, struct Studente *lista);

#endif /* Studenti_h */
