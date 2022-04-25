#include "Viaggi.h"
#include <stdlib.h>
#include <string.h>
#define NOME 10


static struct elem *nuovoNodo(char *nome, int eta, int viaggi) 
{
   struct elem *nodo;
  
     nodo = (struct elem *) malloc(sizeof(struct elem));
     if (nodo == NULL)gestioneErrore();
  
    strcpy(nodo->nome, nome);

    nodo->eta =eta;
    nodo->viaggi = viaggi;
    nodo->next = NULL;
 
    return nodo;
}


void gestioneErrore(void)
{
  printf("Errore\n");

  exit(0);
}


struct elem *inserisciLista(struct elem *lista, struct elem *elem)
{
    if(lista==NULL){
        elem->next=lista;
        return elem;
    }
    
    lista->next=inserisciLista(lista->next,elem);
    return lista;
}

struct elem *leggiFile(FILE *fp, struct elem *lista)
{
   char nome[10];
   int eta, viaggi;
    
   struct elem *nodo;
    
   while(fscanf(fp,"%s%d%d",nome,&eta,&viaggi)==3){
       nodo = nuovoNodo(nome,eta,viaggi);
   
    if (nodo==NULL) gestioneErrore();
    lista = inserisciLista(lista, nodo);
       
  }
    
  return lista;
    
}

void stampaLista(struct elem * lista, FILE *stream)
{
    fprintf(stream,"\nStampa della lista\n");
    printf("-------------------\n");

    while(lista!=NULL){
        fprintf(stream,"%10.9s\t\t %d\t\t %d\t\t\n",lista->nome, lista->eta,lista->viaggi);
        lista=lista->next;
    }
    
    fprintf(stream, "\nFine della stampa\n");
    return;
}


struct elem * eliminaViaggi(struct elem *lista, int num_viaggi)
{
    struct elem * prossima;
    
    if(lista==NULL)
        return lista;
    
    if(lista->viaggi<num_viaggi){
        prossima=lista->next;
        free(lista);
        return eliminaViaggi(prossima, num_viaggi);
    }
    
    lista->next=eliminaViaggi(lista->next, num_viaggi);
    return lista;
}

void scriviFile(FILE *fp, struct elem *lista)
{
  while (lista!=NULL)
  {
    
    fprintf(fp,"%s\t %d\t %d\t\n",lista->nome,lista->eta,lista->viaggi);
    lista = lista->next;
      
   }
    
}

struct elem *duplicaNodo(struct elem *nodo) /*serve per la funzione di duplicaElementi*/
{
  struct elem *nuovo;
  nuovo = nuovoNodo(nodo->nome,nodo->eta,nodo->viaggi);
  return nuovo;
}


struct elem *duplicaElementi(struct elem *lista)
{
  struct elem *nodo;
  
    if (lista==NULL) return NULL;
    lista->next = duplicaElementi(lista->next);

    if (lista->eta%3) { //per duplicare quelli su lista iniziale basta eliminare il %3
    nodo = duplicaNodo(lista);
    nodo->next = lista->next;
    lista->next = nodo;
        
  }
    
  return lista;
}

struct elem * ordinaLista(struct elem * lista)
{
    struct elem * listaOrdinata, *curr, *prev;
    
    if(lista==NULL || lista->next==NULL)
        return lista;
    
    listaOrdinata=ordinaLista(lista->next);
   
    if(listaOrdinata==NULL){
        lista->next=listaOrdinata;
        return lista;
    }
    prev=curr=listaOrdinata;
    
    while(curr!=NULL && curr->viaggi > lista->viaggi){ /*ordino secondo il numero di viaggi dal più grande al più piccolo se voglio fare il contrario basta mettere al posto di ">" questo "<"*/
        prev=curr;
        curr=curr->next;
    }
    
    if(curr==listaOrdinata){
        lista->next=listaOrdinata;
        return lista;
   
    }else{
        
        lista->next=curr;
        prev->next=lista;
        return listaOrdinata;
    }
}

void freeLista(struct elem *lista)
{
    if (lista != NULL) {
    freeLista(lista->next);
    freeNodo(lista);
        
  }
}

void freeNodo(struct elem *nodo)
 {
     
   free((void *) nodo);
 }


struct elem *inserimentoInCoda(struct elem *lista, char nome[NOME], int eta, int viaggi){
 if (lista!= NULL) {
      lista->next = inserimentoInCoda(lista->next, nome, eta, viaggi);
  }else{
      lista = nuovoNodo(nome, eta, viaggi);
}
    return lista;
}


struct elem *rimuoviDuplicati(struct elem *lista)
{
  struct elem *ptr1, *ptr2, *nodo;
  
  for (ptr1=lista; ptr1!=NULL; ptr1=ptr1->next) {
    for (ptr2=ptr1->next; ptr2!=NULL; ) {
      if (strcmp(ptr1->nome,ptr2->nome)==0) {
    nodo = ptr2;
    ptr2 = ptr2->next;
    rimuoviNodo(lista,nodo);
      }
      else ptr2 = ptr2->next;
    }
  }
  return lista;
}

 struct elem *rimuoviNodo(struct elem *lista, struct elem *nodo)
{
  struct elem **indirect;

  indirect = &lista;

  while(*indirect != nodo) {
    indirect = &(*indirect)->next;
  }

  *indirect = nodo->next;

  free(nodo);
  
  return lista;
}


List inserimentoInTesta(List L,  char nome[NOME], int eta, int viaggi) {
    if (L != NULL) {
        List G = (List )malloc(sizeof(struct elem));
        strcpy(G->nome,nome);
        G->eta=eta;
        G->viaggi=viaggi;
        G->next = L;
        return G;
    }
    return nuovoNodo(nome,eta,viaggi);
}

