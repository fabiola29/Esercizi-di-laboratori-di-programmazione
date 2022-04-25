#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"


int main()
{
    FILE *fp;
    Matrice *A;
    int k = 0;
    struct MatriceSparsa *MS;
    
    fp = fopen("in.txt","r");
    //controllo fp
    
    A = leggiMatrice(fp);
    fclose(fp);
    
    stampaMatrice(A);
    
    printf("lunghezza della massima sequenza di %d : %d\n", k, lunghezza_massima(A,k));
    
    MS = listaDaMatrice(A);
    stampaMatriceSparsa(MS);
    
    MS = eliminaMinoriX(MS, 7);
    stampaMatriceSparsa(MS);
    
    
    aggiornaMatrice(A, MS);
    stampaMatrice(A);
    
    
    freeMatriceSparsa(MS);
    freeMatrice(A);
    
}
