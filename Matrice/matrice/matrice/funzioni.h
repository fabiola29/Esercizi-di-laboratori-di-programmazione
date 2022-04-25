struct matrice{
    int m;
    int n;
    int **mat;
};

struct nodo {
    int i;
    int j;
    int val;
    struct nodo *next;
};

struct MatriceSparsa {
    int m;
    int n;
    struct nodo *mat;
};

typedef struct matrice  Matrice;

Matrice *leggiMatrice(FILE *fp);
void stampaMatrice(Matrice *A);
void freeMatrice(Matrice *A);
int lunghezza_massima(Matrice *A, int k);
struct MatriceSparsa *listaDaMatrice(Matrice *A);
void stampaMatriceSparsa(struct MatriceSparsa *MS);
void freeMatriceSparsa(struct MatriceSparsa *MS);
struct MatriceSparsa *eliminaMinoriX(struct MatriceSparsa *MS, int x);
void aggiornaMatrice(Matrice *A, struct MatriceSparsa *MS);
