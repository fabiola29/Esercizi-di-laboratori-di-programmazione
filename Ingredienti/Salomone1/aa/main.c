#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int main(void){
    FILE * fp;
    struct Cibi * lista=NULL;
    fp=fopen("ingredienti.tic","r");
    if(fp!=NULL){
        printf("Leggo i dati dal file \"%s\"..\n","ingredienti.txt");
        lista=leggiFile(fp);
        fclose(fp);
        stampaLista(lista,stdout);
        fp = fopen("ingredienti.toc","w");
        scriviFile(fp,lista);
        fclose(fp);
    }
    return 0;
}


