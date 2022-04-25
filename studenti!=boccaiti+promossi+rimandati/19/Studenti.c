#include "Studenti.h"
#include <stdio.h>
#include <stdlib.h>


struct alunni * leggiFile(FILE * input){
    struct alunni *tmp, *lista=NULL;
    while(!feof(input)){
        tmp=(struct alunni*)malloc(sizeof(struct alunni));
        fscanf(input," %s\t %d\t %d\t %d\t %d\t",tmp->classe,&tmp->studenti,&tmp->promossi,&tmp->bocciati, &tmp->rimandati);
        lista=inserisciCoda(lista,tmp);
    }
    return lista;
}

struct alunni * inserisciCoda(struct alunni * lista, struct alunni * alunni){
    if(lista==NULL){
        alunni->next=lista;
        return alunni;
    }
    lista->next=inserisciCoda(lista->next,alunni);
    return lista;
}

void stampaLista(struct alunni * lista, FILE *stream){
    fprintf(stream,"\nStampa della lista:\n\n");
    while(lista!=NULL){
        fprintf(stream,"%s\t %d\t %d\t\t %d\t\t %d\t\n",lista->classe, lista->studenti,lista->promossi,lista->bocciati,lista->rimandati);
        lista=lista->next;
    }
    fprintf(stream, "\nFine della stampa\n");
    return;
}

struct alunni * eliminaAlunni(struct alunni * lista){
    if(!lista)
        return NULL;
        if(lista->studenti != lista->promossi + lista->bocciati + lista-> rimandati)
        return eliminaAlunni(lista->next);
        lista->next=eliminaAlunni(lista->next);
        return lista;
    }

void scriviFile(FILE *fp, struct alunni  *lista)
{
  while (lista!=NULL) {
      fprintf(fp,"%s %d %d %d %d\n",lista->classe,lista->studenti,lista->promossi,lista->bocciati,lista->rimandati);
    lista = lista->next;
  }
}

struct alunni * ordinaLista(struct alunni * lista){
    struct alunni * listaOrdinata, *curr, *prev;
    if(lista==NULL || lista->next==NULL)
        return lista;
    listaOrdinata=ordinaLista(lista->next);
    /* inserisco in ordine il primo elemento nel resto della lista ordinato */
    if(listaOrdinata==NULL){
        lista->next=listaOrdinata;
        return lista;
    }
    prev=curr=listaOrdinata;
    while(curr!=NULL && curr->promossi > lista->promossi){
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
