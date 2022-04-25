#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Azienda.h"

int main()
{
  struct azienda *lista=NULL;
  FILE *fp;


  fp = fopen("input.txt","r");
  if (fp == NULL) gestioneErrore();
  lista = leggiFile(fp, lista);
  fclose(fp);
  
    printf("                  ************\n");
    printf("                  stampa lista\n");
    printf("                  ************\n");

   scriviLista(lista);

    
     printf("Elimino aziende con almeno con meno di 2 filiari...\n");
     printf("                  ************\n");
     printf("                  stampa lista\n");
     printf("                  ************\n");
     lista = rimuoviAzienda(lista,2);
     scriviLista(lista);

 
  fp = fopen("output.txt","w");
  scriviFile(fp, lista);
  fclose(fp);



  freeLista(lista);

}


