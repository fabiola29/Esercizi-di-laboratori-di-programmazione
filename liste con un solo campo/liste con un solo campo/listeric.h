//
//  listeric.h
//  liste con un solo campo
//
//  Created by Fabiola on 08/07/2021.
//  Copyright © 2021 Fabiola. All rights reserved.
//

#ifndef listeric_h
#define listeric_h

#include <stdio.h>

struct el
{
    int info;
    struct el *next;
};
typedef struct el lista;


lista *newElem(int info);
lista *insertCoda(lista *head, int info);
lista *insertOrdLista(lista *head, int info);
void stampaLista(lista *head);
int lunghezzaLista(lista *head);
void deallocaLista(lista *head);
void stampaListaInversoStatic(lista *head);
//static void stampaListaInverso2(lista *head, int depth);
void stampaInverso(lista *head);
void stampaListaPostoDispari2(lista *head, int posto);
void stampaListaPostoDispari(lista *head);
lista *minimoElemento(lista *head);
lista *primoElementoPari(lista *head);
lista *minimoPariLista(lista *head);
lista *eliminatotElem(lista *head, int x);
lista *eliminaMinoriDi(lista *head, int y);




#endif /* listeric_h */
