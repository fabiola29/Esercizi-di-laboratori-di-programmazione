#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funzioni.h"

int main()
{
    struct nodo *head=NULL;
    FILE *fp;
    
    fp = fopen("dati.txt","r");
    
    head = leggiFile(fp,head);
    fclose(fp);
    printf("La lista --->");
    stampaLista(head);
    
    printf("la lista con valori maggiori di 30 ---> ");
    head = eliminaElementi(head,30);
    stampaLista(head);
    
    fp = fopen("out.txt","w");
    scriviFile(fp,head);
    fclose(fp);
     
    freeLista(head);
    
}
