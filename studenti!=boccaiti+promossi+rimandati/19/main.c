#include <stdio.h>
#include <stdlib.h>
#include "Studenti.h"

#define MAX_STUDENTI 2

int main(void){
    FILE * fp;
    struct alunni * lista=NULL;
    
    fp=fopen("input.txt","r");
    if(fp!=NULL){
        
        printf("Leggo i dati dal file \"%s\"..\n","input.txt");
        lista=leggiFile(fp);
        fclose(fp);
        stampaLista(lista,stdout);
        
        printf("\nElimino: \n");
        lista=eliminaAlunni(lista);
        stampaLista(lista,stdout);
        
        printf("\nOrdino la lista secondo il numero di dipendenti\"..\n");
        lista=ordinaLista(lista);
        stampaLista(lista,stdout);
        
        fp = fopen("output.txt","w");
        scriviFile(fp, lista);
        fclose(fp);
        
    }
    return 0;
}


