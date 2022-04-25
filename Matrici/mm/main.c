#include <stdio.h>
#include <stdlib.h>

int naturale ()
 {
    int n=0;

    do {
            scanf("%d", &n);

            if (n<=0)
                printf("Il numero deve essere maggiore di 0. Riprova: ");

    } while(n<=0);

   return n;
 }


 int ** alloca_matrice (int n, int m)
 {
    int **matrix, i=0;

    matrix=(int **)malloc(n*sizeof(int *));    /* alloco il vettore delle righe, ogni elemento è un puntatore */

        for(i=0; i<n; i++)
            matrix[i]=(int *)malloc(m*sizeof(int));    /* per ogni riga alloco le colonne */

   return matrix;
 }




 void acquisici_matrice (int **matrix, int n, int m)
 {
    int i=0, j=0;

        for(i=0; i<n; i++) {

            for(j=0; j<m; j++) {

                printf("Inserire l'elemento (%d,%d): ", i, j);
                matrix[i][j]=naturale ();
            }
        }
 }


 void stampa_matrice (int **matrix, int n, int m)
 {
    int i=0, j=0;

        for(i=0; i<n; i++) {
            printf("\n");

            for(j=0; j<m; j++) {
                printf("    ");
                printf("%d", matrix[i][j]);
            }
        }

 }



 void elem_max_media (int **A, int n, int m)
 {
    float media=0, max=-1;
    int i=0, j=0;
    int somma=0;
    int x=0, y=0;


        for(i=1; i<(n-1); i++) {

            for(j=1; j<(m-1); j++) {

                somma=A[i-1][j]+A[i][j-1]+A[i][j+1]+A[i+1][j];
                media=(float)somma/4;

                    if(media>max) {
                        max=media;
                        x=i;
                        y=j;

                     }
             }
         }


    printf("\n\nL'elemento per cui la media degli elementi\n");
    printf("ad esso adiacenti sia massima ha cordinate (%d,%d) \n", x, y);
    printf("e il suo valore è %d", A[x][y]);


 }


 void dealloca_matrice (int **matrix, int n)
 {
   int i=0;

        for(i=0; i<n; i++)            /* per ogni riga dealloco le colonne */
            free(matrix[i]);

        free(matrix);                  /* dealloco il vettore delle righe */

 }


int main ()
{
  int N=0, M=0;
  int **A;

  printf("Inserire il numero di righe delle due matrici\n");
  N=naturale ();
  printf("Inserire il numero di colonne delle due matrici\n");
  M=naturale ();

  /* Allocazione dinamica della matrice */
  A=alloca_matrice(N, M);

  /* Inizializzazione della matrice */
  printf("Acquisizione matrice A\n");
  acquisici_matrice (A, N, M);


  /* Stampa della matrice */
  printf("\nMatrice A:\n");
  stampa_matrice (A, N, M);

  /* Procedura per trovare l'elemento per cui la media degli elementi ad esso adiacenti sia massima */
  elem_max_media (A, N, M);


  /* Dealloco la matrice */
  dealloca_matrice(A, N);

  printf("\n\nMemoria deallocata. Fine programma.\n");



 return 0;
}
