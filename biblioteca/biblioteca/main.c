#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dati.h"


int main()
{
    struct genere *headGeneri;
    FILE *fp;
    
    fp = fopen("libri.txt", "r");
    headGeneri = leggiFile(fp);
    fclose(fp);
    stampaLibri(headGeneri);
    
    headGeneri = rimuoviCopie(headGeneri, 10);
    
    printf("Lista dopo eliminazione copie\n");
    stampaLibri(headGeneri);
    
    freeGeneri(headGeneri);
}
