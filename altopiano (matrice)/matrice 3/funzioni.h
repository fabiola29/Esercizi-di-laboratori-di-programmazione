#ifndef funzioni_h
#define funzioni_h

#include <stdio.h>

struct matrice {
    int m; //numero di righe
    int n; //numero di colonne
    int **mat; //dati della matrice
};

typedef struct matrice Matrice;

Matrice *leggiMatrice(FILE *fp);
void stampaMatrice(Matrice *A);
void freeMatrice(Matrice *A);
int contienePermutazione(Matrice *A, int *r1, int *r2);
int esisteAltopiano(Matrice *A, int soglia, int k, int *riga, int *colonna);


#endif /* funzioni_h */
