#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"

int **allocaMatrice(int n, int m)
{
  int **matrice = NULL;

  matrice = (int**)malloc(n*sizeof(int*));

  for(int i = 0; i < n; i++){
    matrice[i] = (int*)malloc(m*sizeof(int));
  }

  return matrice;
}

void stampaMatrice(int **matrice, int n, int m)
{
  for(int i = 0; i < n; i++){
    printf("\n");
    for(int j = 0; j < m; j++){
      printf("%d\t ", matrice[i][j]);
    }
  }
}

void leggiFile(FILE *fp)
{
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

    printf("Matrice:");
    printf("\n------");
  
    stampaMatrice(matrice, n, m);
    
    lista = creaLista(lista, matrice, n, m);
    
    lunghezzaLista(lista);
    printf("\nLa lunghezza della matrice e' %d\n", n);
    
    lista = ordinaLista(lista);
    
    printf("\nLista di partenza ordinata :");
    printf("\n---------------------------\n");
    
    stampaLista(lista);
    
    aggiornaMatrice1(lista, *matrice,  n,  m);
    printf("Matrice aggiornata:\n");
    printf("-------------------");

    stampaMatrice(matrice, n, m);
    
    lista = eliminaNodi(lista);
    
    printf("\nLista dopo eliminazione elementi dispari:");
    printf("\n------------------------------------------\n");

    stampaLista(lista);

    aggiornaMatrice(matrice, n, m);

    printf("Matrice aggiornata:\n");
    printf("-------------------");

    stampaMatrice(matrice, n, m);
    
    lista = duplicaElementi(lista);
    printf("\nLlista con duplicati:\n");
    printf("-----------------------------\n");
    
    stampaLista(lista);
    
    aggiornaMatrice1(lista, *matrice,  n,  m);

    printf("Matrice aggiornata:\n");
    printf("-------------------");
    
    stampaMatrice(matrice, n, m);
    
    rimuoviDuplicati(lista);
   
    printf("\nLlista con duplicati eliminati:\n");
    printf("------------------------------\n");
    
    stampaLista(lista);
    
    aggiornaMatrice1(lista, *matrice,  n,  m);
    
    printf("Matrice aggiornata:\n");
    printf("-------------------");
       
    stampaMatrice(matrice, n, m);

    printf("\n");

  fp1 = fopen("output.txt", "w");
  if(!fp1) {
      perror("Errore");
      exit(0);
      
  }

  scriviFile(fp1, matrice, n, m);

  fclose(fp1);
    
    freeMatrice(matrice);
    freeLista(lista);


}


void scriviFile(FILE *fp, int **matrice, int n, int m)
{
  fprintf(fp, "%d %d", n, m);
  for(int i = 0; i < n; i++){
    fprintf(fp, "\n");
    for(int j = 0; j < m; j++){
      fprintf(fp, "%d ", matrice[i][j]);
    }
  }
}

struct nodo *eliminaNodi(struct nodo *lista)
{
  if(!lista) return NULL;
    if(lista->n3 %2 != 0) return eliminaNodi(lista->next); //DISPARI, ALTRIMENTI PER I PARI BASTA INSERIRE ==
  lista->next = eliminaNodi(lista->next);
  return lista;
}

void stampaLista(struct nodo *lista)
{
  if(!lista)
      return;
  printf("(%d,%d,%d)\n", lista->n1, lista->n2, lista->n3);
  return stampaLista(lista->next);
}

void aggiornaMatrice(int **matrice, int n, int m)
{
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(matrice[i][j] %2 != 0) //DISPARI, ALTRIMENTI PER I PARI BASTA INSERIRE ==
          matrice[i][j] = 0;
    }
  }
}

struct nodo *creaNodo(int n1, int n2, int n3)
{
  struct nodo *nuovoNodo = (struct nodo *)malloc(sizeof(struct nodo));
  if(!nuovoNodo) return NULL;

  nuovoNodo->n1 = n1;
  nuovoNodo->n2 = n2;
  nuovoNodo->n3 = n3;
  nuovoNodo->next = NULL;

  return nuovoNodo;
}

struct nodo *inserisciInCoda(struct nodo *lista, int n1, int n2, int n3)
{
  if(!lista) return creaNodo(n1, n2, n3);
  lista->next = inserisciInCoda(lista->next, n1, n2, n3);
  return lista;
}

struct nodo *creaLista(struct nodo *lista, int **matrice, int n, int m)
{
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      lista = inserisciInCoda(lista, i, j, matrice[i][j]);
    }
  }
  return lista;
}

/*int lunghezza_massima(Matrice *A, int k)
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
*/

struct nodo * ordinaLista(struct nodo * lista)
{
    struct nodo * listaOrdinata, *curr, *prev;
    
    if(lista==NULL || lista->next==NULL)
        return lista;
    
    listaOrdinata=ordinaLista(lista->next);
   
    if(listaOrdinata==NULL){
        lista->next=listaOrdinata;
        return lista;
    }
    prev=curr=listaOrdinata;
    
    while(curr!=NULL && curr->n1 > lista->n1){ /*ordino  dal più grande al più piccolo se voglio fare il contrario basta mettere al posto di ">" questo "<"*/
        prev=curr;
        curr=curr->next;
    }
    
    if(curr==listaOrdinata){
        lista->next=listaOrdinata;
        return lista;
   
    }else{
        
        lista->next=curr;
        prev->next=lista;
        return listaOrdinata;
    }
}

void aggiornaMatrice1(struct nodo *lista, int *matrice, int n, int m)
{
    struct nodo *elemento = lista;
    for(int j = 0; j < m; j++) {
        matrice[n*j + 0] = elemento->n1;
        matrice[n*j + 1] = elemento->n2;
        matrice[n*j + 2] = elemento->n3;
        elemento = elemento->next;
    }
}

struct nodo *duplicaNodo(struct nodo *nodo) /*serve per la funzione di duplicaElementi*/
{
  struct nodo *nuovo;
    nuovo = creaNodo(nodo->n1,nodo->n2,nodo->n3);
  return nuovo;
}

struct nodo *duplicaElementi(struct nodo *lista)
{
  struct nodo *nodo;
  
    if (lista==NULL) return NULL;
    lista->next = duplicaElementi(lista->next);

    if (lista->n1) {
    nodo = duplicaNodo(lista);
    nodo->next = lista->next;
    lista->next = nodo;
        
  }
    
  return lista;
}


struct nodo *rimuoviDuplicati(struct nodo *lista)
{
  struct nodo *ptr1, *ptr2, *nodo;
  
  for (ptr1=lista; ptr1!=NULL; ptr1=ptr1->next) {
    for (ptr2=ptr1->next; ptr2!=NULL; ) {
        if (((void)(ptr1->n1),ptr2->n2)==0) {
    nodo = ptr2;
    ptr2 = ptr2->next;
    rimuoviNodo(lista,nodo);
      }
      else ptr2 = ptr2->next;
    }
  }
  return lista;
}

 struct nodo *rimuoviNodo(struct nodo *lista, struct nodo *nodo)
{
  struct nodo **indirect;

  indirect = &lista;

  while(*indirect != nodo) {
    indirect = &(*indirect)->next;
  }

  *indirect = nodo->next;

  free(nodo);
  
  return lista;
}


void freeLista(struct nodo *lista)
{
  if (lista != NULL) {
    freeLista(lista->next);
  }
}

 void freeNodo(struct nodo *nodo)
{
  free((void *) nodo);
}

void freeMatrice(int **matrice)
{
  free((void *) matrice[0]);
  free((void *) matrice);
}

int lunghezzaLista(struct nodo *head)
{
    if(head==NULL)
    {
        return 0;
    }
    return 1+lunghezzaLista(head->next);
}

