#include "Studenti.h"
#include <stdio.h>
#include <stdlib.h>

struct Studente * leggiFile(FILE * input){
    struct Studente *tmp, *lista=NULL;
    while(!feof(input)){
        tmp=(struct Studente*)malloc(sizeof(struct Studente));
        fscanf(input,"%s\t %s\t %d\t\t\t %s\t\t\t %d\t",tmp->nome,tmp->cognome,&tmp->matricola,tmp->esame,&tmp->voto);
        lista=inserisciCoda(lista,tmp);
    }
    return lista;
}

struct Studente * inserisciCoda(struct Studente * lista, struct Studente * Studente){
    if(lista==NULL){
        Studente->next=lista;
        return Studente;
    }
    lista->next=inserisciCoda(lista->next,Studente);
    return lista;
}

void stampaLista(struct Studente * lista, FILE *stream){
    fprintf(stream,"\nStampa della lista:\n\n");
    while(lista!=NULL){
      fprintf(stream,"%s\t %s\t %d\t %16.50s\t %d\t\n",lista->nome,lista->cognome,lista->matricola,lista->esame,lista->voto);
        lista=lista->next;
    }
    fprintf(stream, "\nFine della stampa\n");
    return;
}

struct Studente * eliminaPuntMinore(struct Studente * lista, int num_voto){
    struct Studente * prossima;
    if(lista==NULL)
        return lista;
    if(lista->voto<num_voto){
        prossima=lista->next;
        free(lista);
        return eliminaPuntMinore(prossima, num_voto);
    }
    lista->next=eliminaPuntMinore(lista->next, num_voto);
    return lista;
}

struct Studente * ordinaLista(struct Studente * lista){
    struct Studente * listaOrdinata, *curr, *prev;
    if(lista==NULL || lista->next==NULL)
        return lista;
    listaOrdinata=ordinaLista(lista->next);
    /* inserisco in ordine il primo elemento nel resto della lista ordinato */
    if(listaOrdinata==NULL){
        lista->next=listaOrdinata;
        return lista;
    }
    prev=curr=listaOrdinata;
    while(curr!=NULL && curr->voto > lista->voto){
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


void scriviFile(FILE *output, struct Studente *lista)
{
  while (lista!=NULL) {
    fprintf(output,"%s\t %s\t %d\t %15s\t %d\t\n",lista->nome,lista->cognome,lista->matricola,lista->esame,lista->voto);
    lista = lista->next;
  }
}
