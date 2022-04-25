#include "listeric.h"
#include <stdio.h>
#include <stdlib.h>
#include "listeric.h"

lista *newElem(int info)
{
    lista *tmp;

    tmp=(lista *)malloc(sizeof(lista));

    tmp->info=info;
    tmp->next=NULL;

    return tmp;
}

lista *insertCoda(lista *head, int info)
{
    if(head==NULL)
    {
        head=newElem(info);
    }else
    {
        head->next=insertCoda(head->next,info);
    }
    return head;
}

lista *insertOrdLista(lista *head, int info)
{
    lista *tmp;

    if(head==NULL)
    {
        return newElem(info);
    }
    if(head->info>info)
    {
        tmp=newElem(info);
        tmp->next=head;
        return tmp;
    }
    head->next=insertOrdLista(head->next,info);

    return head;
}

void stampaLista(lista *head)
{
    if(head==NULL)
    {
        printf("//\n");
    }else
    {
        printf("%d->",head->info);
        stampaLista(head->next);
    }
}

int lunghezzaLista(lista *head)
{
    if(head==NULL)
    {
        return 0;
    }
    return 1+lunghezzaLista(head->next);
}

void deallocaLista(lista *head)
{
    if(head!=NULL)
    {
        deallocaLista(head->next);
        free(head);
    }
}

void stampaListaInversoStatic(lista *head)
{
    int static n=0;

    if(head!=NULL)
    {
        n++;
        stampaListaInversoStatic(head->next);
        n--;
        printf("%d->", head->info);
    }
    if(n==0)
    {
        printf("//\n");
    }
}

static void stampaListaInverso2(lista *head, int depth)
{
    if(head!=NULL)
    {
        stampaListaInverso2(head->next,depth+1);
        printf("%d->",head->info);
    }
    if(depth==0)
    {
        printf("//\n");
    }
}

void stampaInverso(lista *head)
{
    stampaListaInverso2(head,0);
}

void stampaListaPostoDispari2(lista *head, int posto)
{
    if(head==NULL)
    {
        printf("//\n");
    }else
    {
        if(posto%2!=0)
        {
            printf("%d->",head->info);
        }
        stampaListaPostoDispari2(head->next,posto+1);
    }
}

void stampaListaPostoDispari(lista *head)
{
    stampaListaPostoDispari2(head,1);
}

lista *minimoElemento(lista *head)
{
    lista *tmp;

    if(head==NULL)
    {
        return NULL;
    }
    if(head->next==NULL)
    {
        return head;
    }
    tmp=minimoElemento(head->next);
    if(tmp->info>head->info)
    {
        return head;
    }else
    {
        return tmp;
    }
}

lista *primoElementoPari(lista *head)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(head->info%2==0)
    {
        return head;
    }
    return primoElementoPari(head->next);
}

lista *minimoPariLista(lista *head)
{
    lista *tmp;

    if(head==NULL)
    {
        return NULL;
    }
    if(head->info%2==0)
    {
        tmp=minimoPariLista(head->next);
        if(tmp==NULL)
        {
            return head;
        }
        if(tmp->info>head->info)
        {
            return head;
        }else
        {
            return tmp;
        }
    }
    return minimoPariLista(head->next);
}

lista *eliminatotElem(lista *head,int x)
{
    lista *tmp;

    if(head==NULL)
    {
        return NULL;
    }
    if(x==0)
    {
        return head;
    }
    /*tmp=head;
    head=head->next;
    free(tmp);
    return eliminatotElem(head,x-1);*/

    tmp=eliminatotElem(head->next,x-1);
    free(head);
    return tmp;
}

lista *eliminaMinoriDi(lista *head, int y)
{
    lista *succ;

    if(head==NULL)
    {
        return NULL;
    }
    succ=head->next;
    if(head->info<y)
    {
        free(head);
        return eliminaMinoriDi(succ,y);
    }
    head->next=eliminaMinoriDi(succ,y);

    return head;
}

