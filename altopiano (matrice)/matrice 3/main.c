#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"


int main()
{
    Matrice *A;
    FILE *fp;
    int permutazione, r1, r2;
    int riga, colonna, k;
    
    fp = fopen("dati.txt", "r");
    
    A = leggiMatrice(fp);
    fclose(fp);
    stampaMatrice(A);
    
    permutazione = contienePermutazione(A, &r1, &r2);
    
    if (permutazione == 1) {
        printf("Le righe %d e %d permutano\n", r1, r2);
    } else {
        printf("La matrice non ha righe che permutano\n");
    }
    
    k = 4;
    if (esisteAltopiano(A, 10, k, &riga, &colonna)) {
        printf("Esiste altopiano di dimensione %d in posizione %d %d\n", k, riga, colonna);
    } else {
        printf("Non esiste alcun altopiano di dimensione %d\n", k);
    }
    
    freeMatrice(A);
}



