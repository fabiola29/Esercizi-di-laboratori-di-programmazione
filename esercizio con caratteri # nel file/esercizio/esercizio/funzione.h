//
//  funzione.h
//  esercizio
//
//  Created by Fabiola on 14/06/2021.
//  Copyright © 2021 Fabiola. All rights reserved.
//

#ifndef funzione_h
#define funzione_h

#include <stdio.h>

#define STRINGLENGHT 512

typedef struct nodo{
    char nomeAzienda[20];
    int Nquotazioni;
    float *quotazioni;
    struct nodo *next;
}elem;

typedef elem *lista;

void Ordina(float v[], int n);//ASSEGNATA DALLA TRACCIA

lista leggiFile(lista head);

void writeList(lista head);

void freeList(lista head);


#endif /* funzione_h */
