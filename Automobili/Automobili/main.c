#include <stdio.h>
#include <stdlib.h>
#include "Auto.h"


#define NUM_MATRICOLA 2000


int main(void){
    FILE * input, * output;
    struct Auto * lista=NULL;
    input=fopen("input.txt","r");
    if(input!=NULL){
        printf("Leggo i dati dal file \"%s\"..\n","input.txt");
        lista=leggiFile(input);
        fclose(input);
        stampaLista(lista,stdout);
        printf("\nElimino veicoli prima del %d immatricolat%s\n",NUM_MATRICOLA,NUM_MATRICOLA==1?"o":"i");
        lista=eliminaPuntMinore(lista,NUM_MATRICOLA);
        stampaLista(lista,stdout);
        printf("\nLista con duplicati: ");
        lista = duplicaElementi(lista);
        stampaLista(lista,stdout);
      output = fopen("output.txt","w");
       scriviFile(output, lista);
       fclose(output);


      freeLista(lista);
      
    }
    return 0;
}


