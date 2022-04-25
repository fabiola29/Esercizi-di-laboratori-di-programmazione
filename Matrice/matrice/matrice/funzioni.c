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
    
    A->mat = (int **) malloc(m*sizeof(int *));
    A->mat[0] = (int *) calloc(m*n, sizeof(int));
    
    
    for (i=1; i<m; i++) {
        A->mat[i] = A->mat[i-1] + n;
    }
    
    return A;
}

void freeMatrice(Matrice *A)
{
    free(A->mat[0]);
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


int lunghezza_massima(Matrice *A, int k)
{
    int  m, n;
    int length, max_length;
    int *ptr = NULL, *ptrMax;
    
    
    m = A->m;
    n = A->n;
    
    length = max_length = 0;
    ptrMax = ptr + n*m;
    for(ptr = A->mat[0]; ptr <= ptrMax; ptr++) {
        if (*ptr == k) {
            length++;
        } else {
            length = 0;
        }
        
        if (max_length < length) {
            max_length = length;
        }
    }
    
    
    return max_length;
}


struct nodo *creaNodo(int i, int j, int val)
{
    struct nodo *ptr;
    
    ptr = malloc(sizeof(struct nodo));
    ptr->i = i;
    ptr->j = j;
    ptr->val = val;
    ptr->next = NULL;
    
    return ptr;
}

struct nodo *inserisciTesta(struct nodo *head, struct nodo *ptr)
{
    ptr->next = head;
    
    return ptr;
}


struct MatriceSparsa *listaDaMatrice(Matrice *A)
{
    struct MatriceSparsa *MS;
    struct nodo *ptr;
    int i, j, m , n;
    
    MS = malloc(sizeof(struct MatriceSparsa));
    m = MS->m = A->m;
    n = MS->n = A->n;
    MS->mat = NULL;
    
    for (i=0; i<m; i++){
        for (j=0; j<n; j++) {
            if (A->mat[i][j] != 0) {
                ptr = creaNodo(i,j,A->mat[i][j]);
                MS->mat = inserisciTesta(MS->mat, ptr);
            }
        }
    }
    
    
    return MS;
}


void stampaMatriceSparsa(struct MatriceSparsa *MS)
{
    struct nodo *ptr;
    
    if (MS != NULL) {
        ptr = MS->mat;
        
        while (ptr != NULL) {
            printf("%d %d %d\n", ptr->i, ptr->j, ptr->val);
            ptr = ptr->next;
        }
    }
    printf("\n");
}


void freeMatriceSparsa(struct MatriceSparsa *MS)
{
    struct nodo *ptr, *tmp;
    
    if (MS != NULL) {
        ptr = MS->mat;
        while (ptr != NULL) {
            tmp = ptr;
            ptr = ptr->next;
            free(tmp);
        }
    }
    
    free(MS);
}

static struct nodo *eliminaMinoriXLista(struct nodo *head, int x)
{
    struct nodo *succ;
    
    if (head == NULL) return head;
    if (head->val < x) {
        succ = head->next;
        free(head);
        return eliminaMinoriXLista(succ, x);
    }
    
    head->next = eliminaMinoriXLista(head->next, x);
    
    return head;
}

struct MatriceSparsa *eliminaMinoriX(struct MatriceSparsa *MS, int x)
{
    if (MS == NULL) return NULL;
    
    MS->mat = eliminaMinoriXLista(MS->mat, x);
    
    return MS;
}


void aggiornaMatrice(Matrice *A, struct MatriceSparsa *MS)
{
    int m, n;
    struct nodo *ptr;
    
    m = A->m;
    n = A->n;
    
    memset(A->mat[0], 0, n*m*sizeof(int));
    
    ptr = MS->mat;
    
    while (ptr != NULL) {
        A->mat[ptr->i][ptr->j] = ptr->val;
        ptr = ptr->next;
    }
    
    
}












