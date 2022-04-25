#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct nodo{
  char nome[MAX];
  char cognome[MAX];
  int peso;
  int altezza;
  struct nodo *next;
};

struct nodo *CreaNodo(char *nome, char *cognome, int peso, int altezza);
struct nodo *InserisciInCoda(struct nodo *lista, char *nome, char *cognome, int peso, int altezza);
struct nodo *LeggiFile(struct nodo *lista, FILE *fp);
struct nodo *EliminaNodi(struct nodo *lista);
int LunghezzaLista(struct nodo *lista);
float **CreaMatrice(struct nodo *lista);
void StampaMatrice(float **matrice, int n);
void stampaLista(struct nodo * lista, FILE *stream);
void StampaListaToFile(struct nodo *lista, float **matrice, int n, FILE *fpw);



int main(){
  struct nodo* lista = NULL;
  FILE *fp;
  float **matrice = NULL;

  fp = fopen("dati.txt", "r");
  if(!fp) {
      perror("Errore");
      exit(0);
      
  }

  lista = LeggiFile(lista, fp);
  printf("\nLista in input:\n");
  stampaLista(lista,stdout);

  lista = EliminaNodi(lista);
  printf("\nLista dopo eliminazione nodi:\n");
  stampaLista(lista,stdout);
  fclose(fp);

  matrice = CreaMatrice(lista);
  StampaMatrice(matrice,LunghezzaLista(lista));

  fp = fopen("output.txt", "w");
    if(!fp) {
        perror("Errore");
        exit(0);
        
    }

  StampaListaToFile(lista, matrice, LunghezzaLista(lista), fp);
  fclose(fp);   
}

struct nodo *CreaNodo(char *nome, char *cognome, int peso, int altezza){
  struct nodo *nuovoNodo = (struct nodo *)malloc(sizeof(struct nodo));
  if(!nuovoNodo) return NULL;

  strcpy(nuovoNodo->nome, nome);
  strcpy(nuovoNodo->cognome, cognome);
  nuovoNodo->peso = peso;
  nuovoNodo->altezza = altezza;
  nuovoNodo->next = NULL;
  return nuovoNodo;
}

struct nodo *InserisciInCoda(struct nodo *lista, char *nome, char *cognome, int peso, int altezza){
  if(!lista)
      return CreaNodo(nome, cognome, peso, altezza);
  lista->next = InserisciInCoda(lista->next, nome, cognome, peso, altezza);
  return lista;
}

struct nodo *LeggiFile(struct nodo *lista, FILE *fp){
  char nome[MAX];
  char cognome[MAX];
  int peso;
  int altezza;

  while(!feof(fp)){
    if(fscanf(fp, "%s\t %s\t %d\t %d\t", nome, cognome, &peso, &altezza) == 4){
      lista = InserisciInCoda(lista, nome, cognome, peso, altezza);
    }
  }
  return lista;
}

struct nodo *EliminaNodi(struct nodo *lista){
  if(!lista)
      return NULL;
  if(lista->peso < 12) return EliminaNodi(lista->next);
  lista->next = EliminaNodi(lista->next);
  return lista;
}

int LunghezzaLista(struct nodo *lista){
  if(!lista) return 0;
  return(1 + LunghezzaLista(lista->next));
}

  float **CreaMatrice(struct nodo *lista){
    struct nodo *temp, *testa = lista;
    float **matrice = NULL;
    int n = LunghezzaLista(lista);
    float media = 0;

    matrice = (float**)malloc(n * sizeof(float*));
    for(int i = 0; i < n; i++){
      matrice[i] = (float*)malloc(n * sizeof(float));
    }

    for(int i = 0; i < n; i++){
      temp = testa;
      for(int j = 0; j < i + 1; j++){
        if(j != i){
          media = (lista->peso + temp->peso) / 2.0;
          matrice[i][j] = media;
          matrice[j][i] = media;
          temp = temp->next;
        }
      }
      lista = lista->next;
    }
    return matrice;
  }

void StampaMatrice(float **matrice, int n){
    printf("\nMatrice:");
    for(int i = 0; i < n; i++){
      printf("\n");
      for(int j = 0; j < n; j++){
        printf("%f", matrice[i][j]);
      }
    }
    printf("\n");
  }    

void stampaLista(struct nodo * lista, FILE *stream){
    fprintf(stream,"\nStampa della lista:\n\n");
    while(lista!=NULL){
      fprintf(stream,"%10.10s\t %10.10s\t %d\t %d\t\n",lista->nome,lista->cognome,lista->peso,lista->altezza);
        lista=lista->next;
    }
    fprintf(stream,"\nFine della stampa\n");
    return;
}

void StampaListaToFile(struct nodo *lista, float **matrice, int n, FILE *fp){
  float max;
  struct nodo *temp, *testa = lista;

  for(int i = 0; i < n; i++){
    temp = testa;
    max = matrice[i][0];

    for(int j = 1; j < n; j++) if(matrice[i][j] > max) max = matrice[i][j];

    for(int j = 0; j < n; j++){
      if(matrice[i][j] != max){
        temp = temp->next;
      }else{
        break;
      }
    }

    fprintf(fp, "%10.10s\t %10.10s\t %10.10s\t %10.10s\t %f\t \n",lista->nome, lista->cognome, temp->nome, temp->cognome, max);
    lista = lista->next;
  }
}


