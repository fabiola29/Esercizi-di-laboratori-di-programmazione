#include <stdio.h>
#include <stdlib.h>
#include "funzione.h"
#include <string.h>

void Ordina(float v[], int n){//ASSEGNATA DALLA TRACCIA
    int i,j;
    float buff;

    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            if(v[i] > v[j]){
                buff = v[i];
                v[i] = v[j];
                v[j] = buff;
            }
        }
    }
}


static lista creaNodo(char *nomeAzienda,char *tmp, int count){
    lista nodo = (lista)malloc(sizeof(elem));
    if(nodo==NULL)  printf("NON ALLOCATO.\n");

    strcpy(nodo->nomeAzienda,nomeAzienda);
    nodo->Nquotazioni = count;

    nodo->quotazioni = (float *)malloc(count*sizeof(float));
    if(nodo->quotazioni == NULL) printf("NON ALLOCATO.\n");

    for(int i=0;i<count;i++){
        if(i!=count-1){
            nodo->quotazioni[i] = atof(strtok(NULL,"#"));
        }else{
            nodo->quotazioni[i] = atof(strtok(NULL,"$"));
        }
    }

    nodo->next = NULL;
    return nodo;
}

static lista insertToList(lista head,char *nomeAzienda,char *tmp,int count){
    if(head==NULL){
        head = creaNodo(nomeAzienda,tmp,count);
    }else{
        head->next = insertToList(head->next,nomeAzienda,tmp,count);
    }

    return head;
}

lista leggiFile(lista head){
    FILE *fpIn = fopen("dati.txt","r");
    if(fpIn == NULL) printf("NON LETTO.\n");

    int i, count;
    char *nomeAzienda;
    char tmp[STRINGLENGHT];
    while(fgets(tmp,STRINGLENGHT,fpIn)){
        count = 0;
        for(i=0;i<STRINGLENGHT;i++){
            if(tmp[i]=='#') count++;
            else if(tmp[i]=='$') break;
        }
        nomeAzienda = strtok(tmp,"#");
        head = insertToList(head,nomeAzienda,tmp,count);
    }

    fclose(fpIn);
    return head;
}

void writeList(lista head){
    if(head!=NULL){
        printf("%s,     ",head->nomeAzienda);
        for(int i=0;i<head->Nquotazioni;i++){
            printf("%.1f ", head->quotazioni[i]);
        }
        printf("\n");
        writeList(head->next);
    }else;
}


static void freeNodo(lista nodo){
    free((void *)nodo->quotazioni);
    free((void *)nodo);
}


void freeList(lista head){
    if(head==NULL) return;
    else{
        freeList(head->next);
        freeNodo(head);
    }
}

static  lista ordinaVects(lista head){
    if(head!=NULL){
        Ordina(head->quotazioni,head->Nquotazioni);
        head->next = ordinaVects(head->next);
    }else{
        return NULL;
    }
}



void findMinMaxMed(lista head){
    head = ordinaVects(head);

    lista list = head;

    while(list!=NULL){
        printf("%s      ",list->nomeAzienda);
        printf("%.1f ",list->quotazioni[0]);
        if(list->Nquotazioni%2==0){
            printf("%.1f ",list->quotazioni[(list->Nquotazioni/2)-1]);
        }else{
            printf("%.1f ",list->quotazioni[(list->Nquotazioni/2)]);
        }
        printf("%.1f\n",list->quotazioni[list->Nquotazioni-1]);

        list = list->next;
    }
}

