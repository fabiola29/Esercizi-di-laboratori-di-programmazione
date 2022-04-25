#include <stdio.h>
#include <stdlib.h>
#include "funzione.h"

int main()
{
    lista head = NULL;

    head = leggiFile(head);
    writeList(head);
    printf("\n\n");

    //findMinMaxMed(head);

    freeList(head);
    return 0;
}
