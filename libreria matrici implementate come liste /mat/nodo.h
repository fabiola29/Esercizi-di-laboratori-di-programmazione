#ifndef nodo_h
#define nodo_h

#include <stdio.h>
#include <stdlib.h>

struct nodo{
  int n1;
  int n2;
  int n3;
  struct nodo *next;
};


/*STAMPA - LETTURA - SCRITTURA DI FILE*/
int **allocaMatrice(int n, int m);
void stampaMatrice(int **matrice, int n, int m);
void leggiFile(FILE *fp);
void scriviFile(FILE *fp, int **matrice, int n, int m);


/*ELIMINAZIONE DI NODI*/
struct nodo *eliminaNodi(struct nodo *lista);
void stampaLista(struct nodo *lista);
struct nodo *creaNodo(int n1, int n2, int n3);
struct nodo *inserisciInCoda(struct nodo *lista, int n1, int n2, int n3);
struct nodo *creaLista(struct nodo *lista, int **matrice, int n, int m);


/*AGGIORNAMENTO MATRICE DOPO ELIMINAZIONE*/
void aggiornaMatrice(int **matrice, int n, int m);

/*CALCOLA LA LUNGHEZZA MASSIMA
int lunghezza_massima(Matrice *A, int k); */
int lunghezzaLista(struct nodo *head);


/*AGGIORNAMENTO MATRICE DOPO ORDINAMENTO*/
struct nodo * ordinaLista(struct nodo * lista);
void aggiornaMatrice1(struct nodo *lista, int *matrice, int n, int m);


/*DUPLICAZIONE ELEMENTI */
struct nodo *duplicaNodo(struct nodo *elem);
struct nodo *duplicaElementi(struct nodo *lista);


/*ELIMINAZIONE DUPLICATI */
struct nodo *rimuoviNodo(struct nodo *lista, struct nodo *nodo);
struct nodo *rimuoviDuplicati(struct nodo *lista);


/*LIBERO MEMORIA PER LISTA E MATRICE*/
void freeLista(struct nodo *lista);
void freeMatrice(int **matrice);

#endif /* nodo_h */
