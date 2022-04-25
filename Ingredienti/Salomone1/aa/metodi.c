#include "funzioni.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cibi * leggiFile(FILE * input){
    struct Cibi *tmp, *lista=NULL;
    char* commentChar = NULL;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, input)) != -1)
    {
        // Se la riga e' vuota, saltarla
        if (len <= 0)
            continue;
        
        commentChar = strchr(line, '#');
        if (commentChar != NULL)
        {
            // Se l'intera riga e' un commento, saltarla
            if (commentChar == line)
                continue;
            
            // Il commento e' alla fine della riga, troncarla
            *commentChar = '\n';
        }
        tmp=(struct Cibi*)malloc(sizeof(struct Cibi));
        sscanf(line, "%s %s %f\n",tmp->nome,tmp->unitaDiMisura,&tmp->quantita);
        lista=inserisciCoda(lista,tmp);
    }
    return lista;
}

struct Cibi * inserisciCoda(struct Cibi * lista, struct Cibi * Cibi){
    if(lista==NULL){
        Cibi->next=lista;
        return Cibi;
    }
    lista->next=inserisciCoda(lista->next,Cibi);
    return lista;
}

void stampaLista(struct Cibi * lista, FILE *stream){
    fprintf(stream,"\nStampa della lista:\n\n");
    while(lista!=NULL){
        fprintf(stream,"%6s\t %6s %2.2f \n",lista->nome,lista->unitaDiMisura,lista->quantita);
       lista=lista->next;
    }
    fprintf(stream,"\nFine della stampa\n");
    return;
}


void scriviLista(struct Cibi *lista)
{
  while (lista!=NULL) {
      printf("%6s %6s %2.2f \n",lista->nome,lista->unitaDiMisura,lista->quantita);
      lista = lista->next;
  }
  printf("\n");
}

void scriviFile(FILE *fp, struct Cibi *lista)
{
  while (lista!=NULL) {
      fprintf(fp,"%6s %6s %2.2f\n",lista->nome,lista->unitaDiMisura,lista->quantita);
      lista = lista->next;
  }
}
