#include <stdio.h>
#include <stdlib.h>
#include "Persona.h"

#define NUM_ETA 18
#define NUM_ETA1 26


int main(void){
    FILE * fp;
    struct elem * lista=NULL;
    fp=fopen("input.txt","r");
    if(fp!=NULL){
        
        printf("Leggo i dati dal file \"%s\"..\n","input.txt");
        lista=leggiFile(fp);
        fclose(fp);
        stampaLista(lista,stdout);
        
        printf("\nElimino record che hanno meno di %d ann%s..\n",NUM_ETA,NUM_ETA==1?"o":"i");
        lista=eliminaEta(lista,NUM_ETA);
        stampaLista(lista,stdout);
        
        printf("\nElimino record che hanno più di %d ann%s..\n",NUM_ETA1,NUM_ETA1==1?"o":"i");
        lista=eliminaEta1(lista,NUM_ETA1);
        stampaLista(lista,stdout);
        
    
        printf("\nOrdina lista in base al numero di eta crescente...\n");
        lista=ordinaLista(lista);
        stampaLista(lista,stdout);
        
        fp = fopen("output.txt","w");
        scriviFile(fp,lista);
        fclose(fp);
               
      
              
    }
    return 0;
}


