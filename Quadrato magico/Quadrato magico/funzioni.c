#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"

int **allocaMatrice(int n, int m){
  int **matrice = NULL;

  matrice = (int**)malloc(n*sizeof(int*));

  for(int i = 0; i < n; i++){
    matrice[i] = (int*)malloc(m*sizeof(int));
  }

  return matrice;
}

void stampaMatrice(int **matrice, int n, int m){
  for(int i = 0; i < n; i++){
    printf("\n");
    for(int j = 0; j < m; j++){
      printf("%d\t ", matrice[i][j]);
    }
  }
}

void leggiFile(FILE *fp){
  FILE *fp1;
  int **matrice, n, m;
  struct nodo *lista = NULL;

  fscanf(fp, "%d %d", &n, &m);

  matrice = allocaMatrice(n, m);

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
        fscanf(fp, "%d", &matrice[i][j]);
      }
    }

  stampaMatrice(matrice, n, m);
  quadratoMagico(matrice, n, m);
  lista = creaLista(lista, matrice, n, m);

  printf("\nLista:\n");
  stampaLista(lista);

  lista = eliminaNodi(lista);

  printf("\nLista dopo eliminazione elementi dispari:\n");
  stampaLista(lista);

  aggiornaMatrice(matrice, n, m);
  printf("\nMatrice aggiornata:\n");
  stampaMatrice(matrice, n, m);

  fp1 = fopen("output.txt", "w");
  if(!fp1) {
      perror("Errore");
      exit(0);
      
  }

  scriviFile(fp1, matrice, n, m);

  fclose(fp1);

}

void quadratoMagico(int **matrice, int n, int m){
  int sommaColonne = 0;
  int sommaRighe = 0;
  int sommaDiagonale1 = 0;
  int sommaDiagonale2 = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++){
      sommaColonne += matrice[j][i];
      sommaRighe += matrice[i][j];
      sommaDiagonale1 += matrice[i][i];
      sommaDiagonale2 += matrice[i][n-1-i];
    }
  }

  if(sommaRighe == sommaColonne && sommaColonne == sommaDiagonale1 && sommaDiagonale1 == sommaDiagonale2){
    printf("\n\nLa matrice e\' un quadrato magico.\n");
  }else{
    printf("\n\nLa matrice non e\' un quadrato magico.\n");
  }
}

struct nodo *creaNodo(int n1, int n2, int n3){
  struct nodo *nuovoNodo = (struct nodo *)malloc(sizeof(struct nodo));
  if(!nuovoNodo) return NULL;

  nuovoNodo->n1 = n1;
  nuovoNodo->n2 = n2;
  nuovoNodo->n3 = n3;
  nuovoNodo->next = NULL;

  return nuovoNodo;
}

struct nodo *inserisciInCoda(struct nodo *lista, int n1, int n2, int n3){
  if(!lista) return creaNodo(n1, n2, n3);
  lista->next = inserisciInCoda(lista->next, n1, n2, n3);
  return lista;
}

struct nodo *creaLista(struct nodo *lista, int **matrice, int n, int m){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      lista = inserisciInCoda(lista, i, j, matrice[i][j]);
    }
  }
  return lista;
}

struct nodo *eliminaNodi(struct nodo *lista){
  if(!lista) return NULL;
  if(lista->n3 % 2 != 0) return eliminaNodi(lista->next);
  lista->next = eliminaNodi(lista->next);
  return lista;
}

void stampaLista(struct nodo *lista){
  if(!lista)
      return;
  printf("(%d,%d,%d)\n", lista->n1, lista->n2, lista->n3);
  return stampaLista(lista->next);
}

void aggiornaMatrice(int **matrice, int n, int m){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(matrice[i][j] % 2 != 0)
          matrice[i][j] = 0;
    }
  }
}

void scriviFile(FILE *fp, int **matrice, int n, int m){
  fprintf(fp, "%d %d", n, m);
  for(int i = 0; i < n; i++){
    fprintf(fp, "\n");
    for(int j = 0; j < m; j++){
      fprintf(fp, "%d ", matrice[i][j]);
    }
  }
}


