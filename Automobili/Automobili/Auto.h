#ifndef Auto_h
#define Auto_h

#include <stdio.h>

#define MAXLEN 15

#include <stdio.h>

struct Auto{
    char Targa[MAXLEN];
    int AnnoImmatricolazione;
    int Cilindrata;
    int Peso;
    struct Auto *next;
};

struct Auto *leggiFile(FILE * input);
struct Auto *inserisciCoda(struct Auto * lista, struct Auto * Auto);
void stampaLista(struct Auto * lista, FILE *stream);
struct Auto *ordinaLista(struct Auto * lista);
struct Auto * eliminaPuntMinore(struct Auto * lista, int num_matricola);
struct Auto *duplicaNodo(struct Auto *nodo);
struct Auto *duplicaElementi(struct Auto *lista);
void scriviLista(struct Auto *lista);
void freeLista(struct Auto *lista);
void freeNodo(struct Auto *nodo);
void scriviFile(FILE *output, struct Auto *lista);
#endif /* persone_h */

