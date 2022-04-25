#include <stdio.h>
#include <stdlib.h>
#include "persone.h"


#define MASSA 25.00


int main(void){
    FILE * fp;
    struct Persona * lista=NULL;

    fp=fopen("input.txt","r");
    if(fp!=NULL){
        printf("Leggo i dati dal file \"%s\"..\n","input.txt");
        lista=leggiFile(fp);
        fclose(fp);
        stampaLista(lista,stdout);
        printf("\nelimini individui che hanno un indice maggiore di %f massa corp%s...",MASSA,MASSA==(1)?"o":"i");
        lista=eliminaPeso(lista,MASSA);
        stampaLista(lista,stdout);
        printf("\nOrdino la lista...\n");
        lista=ordinaLista(lista);
        stampaLista(lista,stdout);
        fp = fopen("output.txt","w");
        scriviFile(fp,lista);
        fclose(fp);
    }
    return 0;
}




