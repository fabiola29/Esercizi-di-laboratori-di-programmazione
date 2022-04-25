#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Viaggi.h"

#define NUM_VIAGGI 8
#define NOME 10


int main(void) {
    FILE * fp;
    struct elem * lista = NULL;
   /* char nome[NOME];
    int eta;
    int viaggi;
    int n;*/

    fp=fopen("input.txt","r");
    if(fp!=NULL){
        
        printf("Leggo i dati dal file \"%s\"..\n","input.txt");
        lista=leggiFile(fp,lista);
        fclose(fp);
        stampaLista(lista,stdout);
        
        printf("\nElimino record che hanno meno di %d viagg%s...\n",NUM_VIAGGI,NUM_VIAGGI==1?"o":"i");
        lista=eliminaViaggi(lista,NUM_VIAGGI);
        stampaLista(lista,stdout);
        
        printf("\nElaboro lista con duplicati...\n");
        lista = duplicaElementi(lista);
        stampaLista(lista,stdout);
        
        printf("\nElaboro lista senza duplicati...\n");
        lista = rimuoviDuplicati(lista);
        stampaLista(lista,stdout);

       //riscrivo su un nuovo file i risultati
        fp = fopen("output.txt","w");
        scriviFile(fp,lista);
        fclose(fp);
        
        printf("\nOrdina lista in base al numero di viaggi decrescente...\n");
        lista=ordinaLista(lista);
        stampaLista(lista,stdout);
   
        
         /*PER INSERIMENTO IN CODA
        printf("Inserire la dimensione della lista\n");
        scanf("%d",&n);
        
        for(int i=0; i<n; i++){

        printf("\nInserisci nome:");
        scanf("%s",nome);

        
        printf("\nInserisci età:");
        scanf("%d", &eta);

        
        printf("\nInserisci numero viaggi:");
        scanf("%d", &viaggi);
               
        
        lista = inserimentoInCoda(lista,nome,eta,viaggi);
        stampaLista(lista,stdout);
        
               }
    
        //PER INSERIMENTO IN TESTA
        
        printf("Inserire la dimensione della lista\n");
        scanf("%d",&n);
         
         for(int i=0; i<n; i++){

        printf("\nInserisci nome:");
        scanf("%s",nome);

              
       printf("\nInserisci età:");
       scanf("%d", &eta);

       printf("\nInserisci numero viaggi:");
       scanf("%d", &viaggi);
              
       lista = inserimentoInTesta(lista,nome,eta,viaggi);
       stampaLista(lista,stdout);
         
         }
        */
        
        freeLista(lista);

    }
    return 0;
   }

