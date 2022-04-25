#include "Azienda.h"
#include <stdio.h>
#include <stdlib.h>


struct Azienda * leggiFile(FILE * input){
    struct Azienda *tmp, *lista=NULL;
    while(!feof(input)){
        tmp=(struct Azienda*)malloc(sizeof(struct Azienda));
        fscanf(input," %s\t %d\t %d\t %d\t",tmp->nomeAzienda,&tmp->dipendenti,&tmp->dipartimenti,&tmp->sedi);
        lista=inserisciCoda(lista,tmp);
    }
    return lista;
}

struct Azienda * inserisciCoda(struct Azienda * lista, struct Azienda * Azienda){
    if(lista==NULL){
        Azienda->next=lista;
        return Azienda;
    }
    lista->next=inserisciCoda(lista->next,Azienda);
    return lista;
}

void stampaLista(struct Azienda * lista, FILE *stream){
    fprintf(stream,"\nStampa della lista:\n\n");
    while(lista!=NULL){
        fprintf(stream,"%8.8s\t\t %d\t\t %d\t\t %d\t\t\n",lista->nomeAzienda, lista->dipendenti,lista->dipartimenti,lista->sedi);
        lista=lista->next;
    }
    fprintf(stream, "\nFine della stampa\n");
    return;
}

struct Azienda * eliminaPuntMinore(struct Azienda * lista, int num_dipendenti){
    struct Azienda * prossima;
    if(lista==NULL)
        return lista;
    if(lista->dipendenti<num_dipendenti){
        prossima=lista->next;
        free(lista);
        return eliminaPuntMinore(prossima, num_dipendenti);
    }
    lista->next=eliminaPuntMinore(lista->next, num_dipendenti);
    return lista;
}

struct Azienda * ordinaLista(struct Azienda * lista){
    struct Azienda * listaOrdinata, *curr, *prev;
    if(lista==NULL || lista->next==NULL)
        return lista;
    listaOrdinata=ordinaLista(lista->next);
    /* inserisco in ordine il primo elemento nel resto della lista ordinato */
    if(listaOrdinata==NULL){
        lista->next=listaOrdinata;
        return lista;
    }
    prev=curr=listaOrdinata;
    while(curr!=NULL && curr->dipendenti > lista->dipendenti){
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

void scriviFile(FILE *fp, struct Azienda *lista)
{
  while (lista!=NULL) {
    fprintf(fp,"%s\t\t %d\t\t %d\t\t %d\t\t\n",lista->nomeAzienda,lista->dipendenti,lista->dipartimenti,lista->sedi);
    lista = lista->next;
  }
}
