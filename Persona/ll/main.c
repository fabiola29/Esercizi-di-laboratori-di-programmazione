#include <stdio.h>
#include <stdlib.h>
#include "persone.h"


#define ETA_PESO 12


int main(void){
    FILE * fp;
    struct Persona * lista=NULL;
    fp=fopen("input.txt","r");
    if(fp!=NULL){
        printf("Leggo i dati dal file \"%s\"..\n","input.txt");
        lista=leggiFile(fp);
        fclose(fp);
        stampaLista(lista,stdout);
        printf("\nElimino individui che pesano meno di %d chil%s...",ETA_PESO,ETA_PESO==1?"o":"i");
        lista=eliminaPeso(lista,ETA_PESO);
        stampaLista(lista,stdout);
        printf("\nElaboro lista con duplicati...\n");
        lista = duplicaElementi(lista);
        stampaLista(lista,stdout);
        fp = fopen("dati2.txt","w");
        scriviFile(fp,lista);
        fclose(fp);
    }
    return 0;
}



