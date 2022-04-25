#include <stdio.h>
#include <stdlib.h>
#include "Azienda.h"

#define NUM_DIPARTIMENTI 300

int main(void){
    FILE * fp;
    struct Azienda * lista=NULL;
    fp=fopen("input.txt","r");
    if(fp!=NULL){
        printf("Leggo i dati dal file \"%s\"..\n","input.txt");
        lista=leggiFile(fp);
        fclose(fp);
        stampaLista(lista,stdout);
        printf("\nElimino le aziende con meno di %d dipartimenti%s..\n",NUM_DIPARTIMENTI,NUM_DIPARTIMENTI==1?"o":"i");
        lista=eliminaPuntMinore(lista,NUM_DIPARTIMENTI);
        stampaLista(lista,stdout);
        printf("\nOrdino la lista secondo il numero di dipendenti\"..\n");
        lista=ordinaLista(lista);
        stampaLista(lista,stdout);
        
        fp = fopen("dati2.txt","w");
        scriviFile(fp,lista);
        fclose(fp);
              
    }
}

