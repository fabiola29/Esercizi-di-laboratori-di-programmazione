#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "luogo.h"

int main()
{
  struct luogo *lista=NULL;
  float **A;
  int n;
  
  FILE *fp;

  fp = fopen("input.txt","r");
  if (fp == NULL) gestioneErrore();
  lista = leggiFile(fp, lista);
  fclose(fp);
    
  printf("                       **************\n");
  printf("                        Stampo Lista\n");
  printf("                       ***************\n\n");

  scriviLista(lista);

  printf("               *******************************\n");
  printf("                Stampo lista senza duplicati\n");
  printf("               *******************************\n\n");
  lista = rimuoviDuplicati(lista);
  scriviLista(lista);

  printf("                       **************\n");
  printf("                       Stampo Matrice\n");
  printf("                       ***************\n\n");
  n = lengthLista(lista);
  A = allocaMatrice(n,n);
  matriceDistanze(lista, A);
  scriviMatrice(A,n,n);
  
  fp = fopen("output.txt","w");
  scriviFile(fp, lista,A,n);
  fclose(fp);


  freeMatrice(A);
  freeLista(lista);

}


