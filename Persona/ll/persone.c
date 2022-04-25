#include "persone.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Persona * leggiFile(FILE * input){
    struct Persona *tmp, *lista=NULL;
    while(!feof(input)){
        tmp=(struct Persona*)malloc(sizeof(struct Persona));
        fscanf(input,"%s\t %s\t %d\t %d\t %d\t",tmp->nome,tmp->cognome,&tmp->peso,&tmp->altezza,&tmp->eta);
        lista=inserisciCoda(lista,tmp);
    }
    return lista;
}

struct Persona * inserisciCoda(struct Persona * lista, struct Persona * Persona){
    if(lista==NULL){
        Persona->next=lista;
        return Persona;
    }
    lista->next=inserisciCoda(lista->next,Persona);
    return lista;
}

void stampaLista(struct Persona * lista, FILE *stream){
    fprintf(stream,"\nStampa della lista:\n\n");
    while(lista!=NULL){
      fprintf(stream,"%10.10s\t %10.10s\t %d\t %d\t %d\t\n",lista->nome,lista->cognome,lista->peso,lista->altezza,lista->eta);
        lista=lista->next;
    }
    fprintf(stream,"\nFine della stampa\n");
    return;
}

struct Persona * eliminaPeso(struct Persona * lista, int num_peso){
    struct Persona * prossima;
    if(lista==NULL)
        return lista;
    if(lista->peso<num_peso){
        prossima=lista->next;
        free(lista);
        return eliminaPeso(prossima, num_peso);
    }
    lista->next=eliminaPeso(lista->next, num_peso);
    return lista;
}

struct Persona * ordinaLista(struct Persona * lista){
    struct Persona * listaOrdinata, *curr, *prev;
    if(lista==NULL || lista->next==NULL)
        return lista;
    listaOrdinata=ordinaLista(lista->next);
    /* inserisco in ordine il primo elemento nel resto della lista ordinato */
    if(listaOrdinata==NULL){
        lista->next=listaOrdinata;
        return lista;
    }
    prev=curr=listaOrdinata;
    while(curr!=NULL && curr->peso > lista->peso){
        prev=curr;
        curr=curr->next;
    }

    if(curr==listaOrdinata){
        lista->next=listaOrdinata;
        return lista;
    }
    else{
        lista->next=curr;
        prev->next=lista;
        return listaOrdinata;
    }
}


static struct Persona *nuovoNodo(char *nome,char *cognome, int peso, int altezza, int eta)
{
  struct Persona *nodo;

  nodo = (struct Persona *) malloc(sizeof(struct Persona));
  if (nodo == NULL) return NULL;
  
  strcpy(nodo->nome, nome);
  strcpy(nodo->cognome, cognome);
  nodo->peso =peso;
  nodo->altezza = altezza;
  nodo->eta = eta;
  nodo->next = NULL;
    
  return nodo;
}

struct Persona *duplicaNodo(struct Persona *nodo)
{
  struct Persona *nuovo;

  nuovo = nuovoNodo(nodo->nome,nodo->cognome,nodo->peso,nodo->altezza,nodo->eta);

  return nuovo;
}

struct Persona *duplicaElementi(struct Persona *lista)
{
  struct Persona *nodo;
  
  if (lista==NULL) return NULL;
  lista->next = duplicaElementi(lista->next);
  if (lista->eta%2==0) {
    nodo = duplicaNodo(lista);
    nodo->next = lista->next;
    lista->next = nodo;
  }
  return lista;
}

void scriviLista(struct Persona *lista)
{
  while (lista!=NULL) {
    printf("%s\t %s\t %d\t %d\t %d\t\n",lista->nome,lista->cognome,lista->peso,lista->altezza,lista->eta);
    lista = lista->next;
  }
  printf("\n");
}

void scriviFile(FILE *fp, struct Persona *lista)
{
  while (lista!=NULL) {
    fprintf(fp,"%s\t %10.5s\t %d\t %d\t %d\t\n",lista->nome,lista->cognome,lista->peso,lista->altezza,lista->eta);
    lista = lista->next;
  }
}
