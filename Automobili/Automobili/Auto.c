#include "Auto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Auto * leggiFile(FILE * input){
    struct Auto *tmp, *lista=NULL;
    while(!feof(input)){
        tmp=(struct Auto*)malloc(sizeof(struct Auto));
        fscanf(input,"%s %d %d %d",tmp->Targa,&tmp->AnnoImmatricolazione,&tmp->Cilindrata,&tmp->Peso);
        lista=inserisciCoda(lista,tmp);
    }
    return lista;
}

struct Auto * inserisciCoda(struct Auto * lista, struct Auto * Auto){
    if(lista==NULL){
        Auto->next=lista;
        return Auto;
    }
    lista->next=inserisciCoda(lista->next,Auto);
    return lista;
}

void stampaLista(struct Auto * lista, FILE *stream){
    fprintf(stream,"\nStampa della lista:\n\n");
    while(lista!=NULL){
      fprintf(stream,"%s\t %d\t %d\t %d\t\n",lista->Targa,lista->AnnoImmatricolazione,lista->Cilindrata,lista->Peso);
        lista=lista->next;
    }
    fprintf(stream,"\nFine della stampa\n");
    return;
}

struct Auto * eliminaPuntMinore(struct Auto * lista, int num_matricola){
    struct Auto * prossima;
    if(lista==NULL)
        return lista;
    if(lista->AnnoImmatricolazione<num_matricola){
        prossima=lista->next;
        free(lista);
        return eliminaPuntMinore(prossima, num_matricola);
    }
    lista->next=eliminaPuntMinore(lista->next, num_matricola);
    return lista;
}


static struct Auto *nuovoNodo(char *Targa, int AnnoImmatricolazione, int Cilindrata, int Peso)
{
  struct Auto *nodo;

  nodo = (struct Auto *) malloc(sizeof(struct Auto));
  if (nodo == NULL) return NULL;
  
  strcpy(nodo->Targa, Targa);
  nodo->AnnoImmatricolazione =AnnoImmatricolazione;
  nodo->Cilindrata = Cilindrata;
  nodo->Peso =Peso;
  nodo->next = NULL;
    
  return nodo;
}

struct Auto *duplicaNodo(struct Auto *nodo)
{
  struct Auto *nuovo;

  nuovo = nuovoNodo(nodo->Targa,nodo->AnnoImmatricolazione,nodo->Cilindrata,nodo->Peso);

  return nuovo;
}

struct Auto *duplicaElementi(struct Auto *lista)
{
  struct Auto *nodo;
  
  if (lista==NULL) return NULL;
  lista->next = duplicaElementi(lista->next);
  if (lista->Cilindrata<1500) {
    nodo = duplicaNodo(lista);
    nodo->next = lista->next;
    lista->next = nodo;
  }
  return lista;
}

void scriviLista(struct Auto *lista)
{
  while (lista!=NULL) {
    printf("%s %d %d %d\n",lista->Targa,lista->AnnoImmatricolazione,lista->Cilindrata,lista->Peso);
    lista = lista->next;
  }
  printf("\n");
}

void freeLista(struct Auto *lista)
{
  if (lista != NULL) {
    freeLista(lista->next);
    freeNodo(lista);
  }
}

void freeNodo(struct Auto *nodo)
{
  free((void *) nodo);
}

void scriviFile(FILE *output, struct Auto *lista)
{
  while (lista!=NULL) {
    fprintf(output,"%s\t %d\t %d\t %d\n",lista->Targa,lista->AnnoImmatricolazione,lista->Cilindrata,lista->Peso);
    lista = lista->next;
  }
}
