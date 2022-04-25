#ifndef Prodotti_h
#define Prodotti_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRINGLENGTH 256

struct Venditore {
  char nome[STRINGLENGTH];
  int N;
  char **prodotto;
  struct Venditore *next;
};



void gestioneErrore(void);
struct Venditore *leggiFile(FILE *fp, struct Venditore *lista);
void scriviLista(struct Venditore *lista);
struct Venditore *rimuoviAzienda(struct Venditore *lista, int soglia);
void scriviFile(FILE *fp, struct Venditore *lista);
void freeLista(struct Venditore*lista);


#endif /* Prodotti_h */
