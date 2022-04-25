#include <stdio.h>
#include <stdlib.h>

struct nodo{
  int n1;
  int n2;
  int n3;
  struct nodo *next;
};

int **allocaMatrice(int n, int m);
void stampaMatrice(int **marice, int n, int m);
void leggiFile(FILE *fp);
void quadratoMagico(int **matrice, int n, int m);
struct nodo *creaNodo(int n1, int n2, int n3);
struct nodo *inserisciInCoda(struct nodo *lista, int n1, int n2, int n3);
struct nodo *creaLista(struct nodo *lista, int **matrice, int n, int m);
struct nodo *eliminaNodi(struct nodo *lista);
void stampaLista(struct nodo *lista);
void aggiornaMatrice(int **matrice, int n, int m);
void scriviFile(FILE *fp, int **matrice, int n, int m);

