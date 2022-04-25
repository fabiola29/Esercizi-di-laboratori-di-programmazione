#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listeric.h"

void menu(void);

int main()
{
    lista *list=NULL;
    lista *min=NULL;
    lista *primoPari=NULL;
    lista *minPari=NULL;


    int info;
    int n;
    int x;
    int y;


    while((info=rand()%101)!=0)
    {
        list=insertCoda(list,info);
    }

    int scelta=1;
    printf("\t\tPROGRAMMA DI GESTIONE PER LISTE CONCATENATE\n\n");
    while(scelta>0 && scelta<10)
    {
        menu();
        printf("\n");
        printf("FAI LA TUA OPERAZIONE: ");
        scanf("%d", &scelta);
        printf("\n");
        switch(scelta)
        {
        case 1:
            system("CLS");
            printf("Lista originale : ");
            stampaLista(list);
            printf("\n");
            n=lunghezzaLista(list);
            printf("La lunghezza della lista e' %d\n", n);
            printf("\n");
            system("PAUSE");
            break;
        case 2:
            system("CLS");
            printf("Lista originale : ");
            stampaLista(list);
            printf("\n");
            printf("Lista in ordine inverso : ");
            stampaInverso(list);
            printf("\n");
            system("PAUSE");
            break;
        case 3:
            system("CLS");
            printf("Lista originale : ");
            stampaLista(list);
            printf("\n");
            printf("Elementi in posizione dispari : ");
            stampaListaPostoDispari(list);
            printf("\n");
            system("PAUSE");
            break;
        case 4:
            system("CLS");
            printf("Lista originale : ");
            stampaLista(list);
            printf("\n");
            min=minimoElemento(list);
            printf("L'elemento minimo della lista e' %d", min->info);
            printf("\n");
            system("PAUSE");
            break;
        case 5:
            system("CLS");
            printf("Lista originale : ");
            stampaLista(list);
            printf("\n");
            primoPari=primoElementoPari(list);
            if(primoPari==NULL)
            {
                printf("Elemento pari non presente o lista vuota\n");
            }else
            {
                printf("Primo elemento pari lista : %d\n", primoPari->info);
            }
            printf("\n");
            system("PAUSE");
            break;
        case 6:
            system("CLS");
            printf("Lista originale : ");
            stampaLista(list);
            printf("\n");
            minPari=minimoPariLista(list);
            if(minPari==NULL)
            {
                printf("Lista vuota o elemento pari non presente\n");
            }else
            {
                printf("Elemento minimo pari della lista : %d\n", minPari->info);
            }
            printf("\n");
            system("PAUSE");
            break;
        case 7:
            system("CLS");
            printf("Lista originale : ");
            stampaLista(list);
            printf("\n");
            n=lunghezzaLista(list);
            printf("La lunghezza della lista e' %d", n);
            printf("\n");
            printf("Quanti elementi vuoi eliminare: ");
            scanf("%d", &x);
            printf("\n");
            list=eliminatotElem(list,x);
            printf("Lista modificata : ");
            stampaLista(list);
            printf("\n");
            system("PAUSE");
            break;
        case 8:
            system("CLS");
            printf("Lista originale : ");
            stampaLista(list);
            printf("\n");
            n=lunghezzaLista(list);
            printf("La lunghezza della lista e' %d", n);
            printf("\n");
            printf("Elimina elementi minori di : ");
            scanf("%d", &y);
            printf("\n");
            list=eliminaMinoriDi(list,y);
            printf("Lista modificata : ");
            stampaLista(list);
            printf("\n");
            system("PAUSE");
            break;
        case 9:
            system("CLS");
            deallocaLista(list);
            list=NULL;
            n=lunghezzaLista(list);
            printf("Dopo aver deallocato, ");
            printf("la lunghezza della lista e' : %d\n",n);
            system("PAUSE");
            break;
        case 10:
            system("PAUSE");
            return 0;
            break;
        }
    }



    return 0;
}


void menu()
{
    printf("1--> STAMPA LISTA E LA SUA LUNGHEZZA\n");
    printf("2--> STAMPA LISTA IN ORDINE INVERSO\n");
    printf("3--> VISUALIZZA GLI ELEMENTI DELLA LISTA IN POSIZIONE DISPARI\n");
    printf("4--> VISUALIZZA IL MINIMO ELEMENTO DELLA LISTA\n");
    printf("5--> VISUALIZZA IL PRIMO ELEMENTO PARI DELLA LISTA\n");
    printf("6--> VISUALIZZA L'ELEMENTO MINIMO PARI DELLA LISTA\n");
    printf("7--> ELIMINA I PRIMI X ELEMENTI\n");
    printf("8--> ELIMINA ELEMENTI MINORI DI UN CERTO Y\n");
    printf("9--> DEALLOCA LISTA\n");
    printf("10--> ESCI\n");

}

