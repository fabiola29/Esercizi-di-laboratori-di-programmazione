#include <stdio.h>
#include <stdlib.h>
#include "Partite.h"


#define NUM_PUNTI 30


int main(void){
    FILE * fp;
    struct partite * lista=NULL;
    fp=fopen("input.txt","r");
    if(fp!=NULL){
        printf("Leggo i dati dal file \"%s\"..\n","input.txt");
        lista=leggiFile(fp);
        fclose(fp);
        stampaLista(lista,stdout);
        printf("\nElimino squadre con meno di %d punt%s..\n",NUM_PUNTI,NUM_PUNTI==1?"o":"i");
        lista=eliminaPuntMinore(lista,NUM_PUNTI);
        stampaLista(lista,stdout);
        printf("\nOrdino la lista secondo iL punteggio delle varie squadre..\n");
        lista=ordinaLista(lista);
        stampaLista(lista,stdout);
        fp = fopen("dati2.txt","w");
        scriviFile(fp,lista);
        fclose(fp);
    }
    return 0;
}


