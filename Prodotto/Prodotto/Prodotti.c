#include "Prodotti.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRINGLENGTH 256


static struct Venditore *nuovoNodo(char *nome, int N)
{
  struct Venditore *nodo;
  int i;

  nodo = (struct Venditore *) malloc(sizeof(struct Venditore));
  if (nodo == NULL) return NULL;
  
  strcpy(nodo->nome, nome);
  nodo->N = N;
  nodo->prodotto = (char **) malloc(N*sizeof(char *));
  for (i=0; i<N; i++)
    nodo->prodotto[i] = (char *) malloc(STRINGLENGTH*sizeof(char));
  nodo->next = NULL;
    
  return nodo;
}

static void freeNodo(struct Venditore *nodo)
{
  int i;

  for (i=0; i<nodo->N; i++)
    free((void *) nodo->prodotto[i]);
  free((void *) nodo->prodotto);

  free((void *) nodo);
}

static struct Venditore *inserisciLista(struct Venditore *nodo, struct Venditore *lista)
{
  if (lista==NULL) return nodo;
  lista->next = inserisciLista(nodo, lista->next);
  return lista;
}

 static struct Venditore *rimuoviNodo(struct Venditore *lista, struct Venditore *nodo)
{
  struct Venditore *tmp;
  
  if (lista == nodo) {
    tmp = lista->next;
    freeNodo(lista);
    return tmp;
  }

  lista->next = rimuoviNodo(lista->next,nodo);
    return 0;
}


void gestioneErrore()
{
  printf("Errore\n");

  exit(0);
}

void freeLista(struct Venditore *lista)
{
  if (lista != NULL) {
    freeLista(lista->next);
    freeNodo(lista);
  }
}


void scriviLista(struct Venditore *lista)
{
  int i;
  
  while (lista!=NULL) {
    printf("%s\t %d\t ",lista->nome,lista->N);
    for (i=0; i<lista->N; i++) {
      printf("%10.90s\t\t ",lista->prodotto[i]);
    }
    printf("\n");
    lista = lista->next;
  }
  printf("\n");
}

struct Venditore *leggiFile(FILE *fp, struct Venditore *lista)
{
    char nome[STRINGLENGTH];
    int N, i;
  struct Venditore *nodo;

  while(fscanf(fp,"%s\t%d\t",nome,&N)==2){
    nodo = nuovoNodo(nome,N);
    if (nodo==NULL) gestioneErrore();
    for (i=0; i<N; i++) {
      fscanf(fp,"%s\t",nodo->prodotto[i]);
    }
    lista = inserisciLista(nodo, lista);
  }
  return lista;
}


void scriviFile(FILE *fp, struct Venditore *lista)
{
  int *buffer, n, i, j, count;
    struct Venditore *ptr1, *ptr2;
  while (lista!=NULL) {
    n = lista->N;
    fprintf(fp,"%s\t %d\t", lista->nome, n);
    buffer = (int *) calloc(n,sizeof(int));

    for (i=0; i<n; i++) {
      count = 0;
      if (!buffer[i]) {
    buffer[i] = 1;
    count++;
    fprintf(fp,"%s\t ",lista->prodotto[i]);
    for (j=i+1; j<n; j++) {
      if (strcmp(lista->prodotto[i],lista->prodotto[j])==0) {
        buffer[j] = 1;
        count++;
      }
    }
    fprintf(fp,"%d ",count);
      }
    }
    fprintf(fp,"\n");
    free((void *) buffer);
    lista = lista->next;
  }
}
struct Venditore *rimuoviAzienda(struct Venditore *lista, int soglia)
{
  if (lista==NULL) return lista;
  if (lista->N<soglia) {
    lista = rimuoviNodo(lista, lista);
    lista = rimuoviAzienda(lista, soglia);
  } else lista->next = rimuoviAzienda(lista->next, soglia);
  
  return lista;
}


