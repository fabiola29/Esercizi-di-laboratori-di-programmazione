#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodo.h"

int main(){
  FILE *fp;

  fp = fopen("in.txt", "r");
    if(!fp) {
        perror("Errore");
        exit(0);
        
    }

  leggiFile(fp);

  fclose(fp);
    
}

