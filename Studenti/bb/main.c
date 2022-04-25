#include <stdio.h>
#include <stdlib.h>
#include "Studenti.h"


#define ETA_STUDENTI 18


int main(void){
    FILE * fp;
    struct Studente * lista=NULL;
    fp=fopen("input.txt","r");
    if(fp!=NULL){
        printf("Leggo i dati dal file \"%s\"..\n","input.txt");
        lista=leggiFile(fp);
        fclose(fp);
        stampaLista(lista,stdout);
        printf("\nElimino gli studenti che hanno minore di %d i vot%s...",ETA_STUDENTI,ETA_STUDENTI==1?"o":"i");
        lista=eliminaPuntMinore(lista,ETA_STUDENTI);
        stampaLista(lista,stdout);
        printf("\nOrdino la lista secondo il numero di eta dei studenti..\n");
        lista=ordinaLista(lista);
        stampaLista(lista,stdout);
        fp = fopen("dati2.txt","w");
        scriviFile(fp, lista);
        fclose(fp);
        
    }
    return 0;
}


