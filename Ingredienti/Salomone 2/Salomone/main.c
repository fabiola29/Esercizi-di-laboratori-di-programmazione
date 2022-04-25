#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 32

struct PesiSpecifici
{
char ingrediente[DIM];
float peso;
};

float PesoTotale(char nomefile[], struct PesiSpecifici pesi[], int n_pesi);
int CercaIngrediente(char nome_ingrediente[], struct PesiSpecifici pesi[], int n_pesi);

int main (int argc, char *argv[])
{
    struct PesiSpecifici pesi[4] = {
                                   {"latte", 1000},
                                    {"olio", 950},
                                    {"acqua", 1000},
                                    {"uova", 75.0}
                                   };
    printf("Peso totale: %f\n", PesoTotale(argv[1], pesi, 4));
    return 0;
}

float PesoTotale (char nomefile[], struct PesiSpecifici pesi[], int n_pesi) {
    FILE *fp;
    float quantita, peso_totale = 0.0;
    char ingrediente[DIM], unita[4];
    int indice_ingrediente;
    fp = fopen ("ingredienti.toc", "r");
    while (fscanf (fp, "%s %s %f", ingrediente, unita, &quantita) != EOF)
    {
        if (strcmp(unita,"g") == 0)
            peso_totale += quantita;
        else
        {
            /* cerca il peso specifico */
            indice_ingrediente = CercaIngrediente(ingrediente, pesi, n_pesi);
            peso_totale += pesi[indice_ingrediente].peso * quantita;
            
        }
        
    }
    fclose (fp);
    return peso_totale;
}

int CercaIngrediente(char nome_ingrediente[], struct PesiSpecifici pesi[], int n_pesi) {
  int i;
    for (i = 0; i < n_pesi; i++)
        if (strcmp(nome_ingrediente, pesi[i].ingrediente) == 0)
            return i;
    return -1;
}
