#include "Partite.h"
#include "Partite.h"
#include <stdio.h>
#include <stdlib.h>


struct partite * leggiFile(FILE * input){
    struct partite *tmp, *lista=NULL;
    while(!feof(input)){
        tmp=(struct partite*)malloc(sizeof(struct partite));
        fscanf(input,"%s\t %d\t %d\t %d\t %d\t %d\t",tmp->NomeSquadre,&tmp->Punteggio,&tmp->PartiteGiocate,&tmp->PartiteVinte,&tmp->PartitePareggiate,&tmp->PartitePerse);
        lista=inserisciCoda(lista,tmp);
    }
    return lista;
}

struct partite * inserisciCoda(struct partite * lista, struct partite * partite){
    if(lista==NULL){
        partite->next=lista;
        return partite;
    }
    lista->next=inserisciCoda(lista->next,partite);
    return lista;
}

void stampaLista(struct partite * lista, FILE *stream){
    fprintf(stream,"\nStampa della lista:\n\n");
    while(lista!=NULL){
        fprintf(stream,"%10s\t %d\t %d\t %d\t %d\t %d\t\n",lista->NomeSquadre,lista->Punteggio,lista->PartiteGiocate,lista->PartiteVinte,lista->PartitePareggiate,lista->PartitePerse);
        lista=lista->next;
    }
    fprintf(stream, "\nFine della stampa\n");
    return;
}

struct partite * eliminaPuntMinore(struct partite * lista, int num_punti){
    struct partite * prossima;
    if(lista==NULL)
        return lista;
    if(lista->Punteggio<num_punti){
        prossima=lista->next;
        free(lista);
        return eliminaPuntMinore(prossima, num_punti);
    }
    lista->next=eliminaPuntMinore(lista->next, num_punti);
    return lista;
}

struct partite * ordinaLista(struct partite * lista){
    struct partite * listaOrdinata, *curr, *prev;
    if(lista==NULL || lista->next==NULL)
        return lista;
    listaOrdinata=ordinaLista(lista->next);
    /* inserisco in ordine il primo elemento nel resto della lista ordinato */
    if(listaOrdinata==NULL){
        lista->next=listaOrdinata;
        return lista;
    }
    prev=curr=listaOrdinata;
    while(curr!=NULL && curr->Punteggio < lista->Punteggio){
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

void scriviFile(FILE *fp, struct partite *lista)
{
  while (lista!=NULL) {
    fprintf(fp,"%s\t %d\t %d\t %d\t %d\t %d\t\n",lista->NomeSquadre,lista->Punteggio,lista->PartiteGiocate,lista->PartiteVinte,lista->PartitePareggiate,lista->PartitePerse);
    lista = lista->next;
  }
}
