#include "Persona.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct elem * leggiFile(FILE * input){
    struct elem *tmp, *lista=NULL;
    while(!feof(input)){
        tmp=(struct elem*)malloc(sizeof(struct elem));
        fscanf(input,"%s\t %s\t %d\t %d\t %d\t\n",tmp->Nome,tmp->Cognome,&tmp->Peso,&tmp->Altezza,&tmp->Eta);
        lista=inserisciCoda(lista,tmp);
    }
    return lista;
}

struct elem * inserisciCoda(struct elem * lista, struct elem * elem){
    if(lista==NULL){
        elem->next=lista;
        return elem;
    }
    lista->next=inserisciCoda(lista->next,elem);
    return lista;
}

void stampaLista(struct elem * lista, FILE *stream){
    fprintf(stream,"\nStampa della lista:\n\n");
    while(lista!=NULL){
        fprintf(stream,"%10.10s\t\t %10.10s\t\t  %d\t\t %d\t\t %d\t\t \n",lista->Nome,lista->Cognome,lista->Peso,lista->Altezza,lista->Eta);
        lista=lista->next;
    }
    fprintf(stream,"\nFine della stampa\n");
    return;
}

struct elem * eliminaEta(struct elem *lista, int num_eta){
    struct elem * prossima;
    if(lista==NULL)
        return lista;
    if(lista->Eta<18){
        prossima=lista->next;
        free(lista);
        return eliminaEta(prossima, num_eta);
    }
    lista->next=eliminaEta(lista->next, num_eta);
    return lista;
}



void scriviFile(FILE *fp, struct elem *lista)
{
  while (lista!=NULL) {
      fprintf(fp,"%10.10s\t %10.10s\t  %d\t  %d\t %d\t\n",lista->Nome,lista->Cognome,lista->Peso,lista->Altezza,lista->Eta);
    lista = lista->next;
  }
}


void scriviLista(struct elem *lista)
{
  while (lista!=NULL) {
    printf("%s\t %s\t %d\t %d\t %d\t\n",lista->Nome,lista->Cognome,lista->Peso,lista->Altezza,lista->Eta);
    lista = lista->next;
  }
  printf("\n");
}

void freeLista(struct elem *lista)
{
  if (lista != NULL) {
    freeLista(lista->next);
    freeNodo(lista);
  }
}

void freeNodo(struct elem*nodo)
{
  free((void *) nodo);
}



struct elem * ordinaLista(struct elem * lista){
    struct elem * listaOrdinata, *curr, *prev;
    if(lista==NULL || lista->next==NULL)
        return lista;
    listaOrdinata=ordinaLista(lista->next);
    /* inserisco in ordine il primo elemento nel resto della lista ordinato */
    if(listaOrdinata==NULL){
        lista->next=listaOrdinata;
        return lista;
    }
    prev=curr=listaOrdinata;
    while(curr!=NULL && curr->Eta < lista->Eta){  //ordino secondo il numero di viaggi dal più piccolo al più grande se voglio fare il contrario basta mettere al posto di "<" questo ">"
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

struct elem * eliminaEta1(struct elem *lista, int num_eta1){
    struct elem * prossima;
    if(lista==NULL)
        return lista;
    if(lista->Eta>65){
        prossima=lista->next;
        free(lista);
        return eliminaEta1(prossima, num_eta1);
    }
    lista->next=eliminaEta1(lista->next, num_eta1);
    return lista;
}

