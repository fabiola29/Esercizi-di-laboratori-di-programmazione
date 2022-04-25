#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"

static Matrice *allocaMatrice(int m, int n)
{
    Matrice *A;
    int i;
    
    A = malloc(sizeof(Matrice));
    A->m = m;
    A->n = n;
    
    A->mat = malloc(m*sizeof(int *));
    for (i=0; i<m; i++) {
        A->mat[i] = malloc(n*sizeof(int));
    }
    
    return A;
}


void freeMatrice(Matrice *A)
{
    int i;
    int m;
    
    m = A->m;
    
    for (i=0; i<m; i++) {
        free(A->mat[i]);
    }
    
    free(A->mat);
    
    free(A);
}

void stampaMatrice(Matrice *A)
{
    int i, j, m, n;
    
    m = A->m; n = A->n;
    
    for (i=0; i<m; i++) {
        for (j=0; j<n; j++) {
            printf("%3d ", A->mat[i][j]);
        }
        printf("\n");
    }
}

Matrice *leggiMatrice(FILE *fp)
{
    Matrice *A;
    int m, n, i, j;
    
    fscanf(fp, "%d%d",&m,&n);
    
    A = allocaMatrice(m,n);
    
    A->m = m;
    A->n = n;
    for (i=0; i<m; i++) {
        for (j=0; j<n; j++) {
            fscanf(fp,"%d", A->mat[i] + j);
        }
    }
    
    return A;
}

static void zeroBuffer(unsigned char *buffer, int n)
{
    int i;
    
    for (i=0; i<n; i++) {
        buffer[i] = 0;
    }
    
}


int contienePermutazione(Matrice *A, int *r1, int *r2)
{
    int ri, rj, i, j, m, n;
    unsigned char *buffer;
    int permutazione = 0, trovato;
    
    m = A->m; n = A->n;
    
    buffer = calloc(n, sizeof(unsigned char));
    
    for (ri=0; permutazione==0 && ri<m-1; ri++) {
        for (rj=ri+1; permutazione==0 && rj<m; rj++) {
            zeroBuffer(buffer, n);
            trovato = 1;
            
            for (i=0; trovato==1 && i<n; i++) {
                trovato = 0;
                for (j=0; trovato==0 && j<n; j++) {
                    if (A->mat[ri][i] == A->mat[rj][j]) {
                        if (buffer[j] == 0) {
                            buffer[j] = 1;
                            trovato = 1;
                        }
                    }
                }
            }
            
            if (trovato==1) {
                *r1 = ri;
                *r2 = rj;
                permutazione = 1;
            }
        }
    }
    
    free(buffer);
    
    return permutazione;
}

static int isAltopiano(Matrice *A, int k, int soglia, int i, int j)
{
    int r, c, min, max;
    
    min = max = A->mat[i][j];
    for (r=i; r<i+k; r++) {
        for (c=j; c<j+k; c++) {
            min = (min > A->mat[r][c]) ? A->mat[r][c] : min;
            max = (max < A->mat[r][c]) ? A->mat[r][c] : max;
        }
    }
    
    if (max-min <= soglia) return 1;
    
    return 0;
}


int esisteAltopiano(Matrice *A, int soglia, int k, int *riga, int *colonna)
{
    int m, n, i, j;
    
    m = A->m; n = A->n;
    
    for (i=0; i<=m-k; i++) {
        for (j=0; j<=n-k; j++) {
            if (isAltopiano(A, k, soglia, i, j)) {
                *riga = i;
                *colonna = j;
                return 1;
            }
        }
    }
    
    return 0;
}






