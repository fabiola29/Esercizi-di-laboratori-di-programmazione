#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dati.h"


static struct genere *nodoGenere(char *genere)
{
    struct genere *nodo;
    
    nodo = (struct genere *) malloc(sizeof(struct genere));
    strcpy(nodo->genere, genere);
    nodo->lista = NULL;
    nodo->next = NULL;
    
    return nodo;
}

static struct book *nodoLibro(char *autore, char *titolo, float prezzo, int Ncopie)
{
    struct book *nodo;
    
    nodo = (struct book *) malloc(sizeof(struct book));
    strcpy(nodo->autore, autore);
    strcpy(nodo->titolo, titolo);
    nodo->prezzo = prezzo;
    nodo->Ncopie = Ncopie;
    nodo->next = NULL;
    
    return nodo;
}


static struct book *inserisciListaLibro(struct book *head, char *autore, char *titolo, float prezzo, int Ncopie)
{
    struct book *nodo;
    
    nodo = nodoLibro(autore, titolo, prezzo, Ncopie);
    
    nodo->next = head;
    
    return nodo;
}

static struct genere *inserisciLibro(struct genere *head, char *autore, char *titolo, char *genere, float prezzo, int Ncopie)
{
    struct genere *l = head, *nodo=NULL;
    
    
    if (head != NULL) {
        while (l != NULL) {
            if (strcmp(l->genere, genere) == 0) {
                nodo = l;
                break;
            }
            l = l->next;
        }
    }
    
    if (nodo == NULL) {
        nodo = nodoGenere(genere);
        nodo->next = head;
        head = nodo;
    }
    
    nodo->lista = inserisciListaLibro(nodo->lista, autore, titolo, prezzo, Ncopie);
    
    return head;
}

static void stampaListaLibri(struct book *head)
{
    while (head != NULL) {
        printf("%s, \"%s\", %.2f, %d\n", head->autore, head->titolo, head->prezzo, head->Ncopie);
        head = head->next;
    }
}

void stampaLibri(struct genere *headGenere)
{
    while (headGenere != NULL) {
        printf("%s:\n", headGenere->genere);
        stampaListaLibri(headGenere->lista);
        printf("\n");
        headGenere = headGenere->next;
    }
}

static void freeLibri(struct book *head)
{
    struct book *tmp;
    
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void freeGeneri(struct genere *head)
{
    struct genere *tmp;
    
    while (head != NULL) {
        tmp = head;
        freeLibri(tmp->lista);
        head = head->next;
        free(tmp);
    }
}

static struct book *rimuoviLibri(struct book *head, int soglia)
{
    struct book *tmp;
    
    if (head==NULL) return head;
    if( head->Ncopie < soglia) {
        tmp = head->next;
        free(head);
        return rimuoviLibri(tmp, soglia);
    }
    
    head->next = rimuoviLibri(head->next, soglia);
    
    return head;
}

static struct genere *rimuoviGeneri(struct genere *head)
{
    struct genere *tmp;
    
    if (head==NULL) return head;
    if( head->lista == NULL) {
        tmp = head->next;
        free(head);
        return rimuoviGeneri(tmp);
    }
    
    head->next = rimuoviGeneri(head->next);
    
    return head;
}


struct genere *rimuoviCopie(struct genere *head, int soglia)
{
    struct genere *l=head;
    
    while (l != NULL) {
        l->lista = rimuoviLibri(l->lista, soglia);
        l = l->next;
    }
    
    head = rimuoviGeneri(head);
    
    return head;
}

struct genere *leggiFile(FILE *fp)
{
    char c;
    char str[5][STRINGLEGTH];
    char *autore, *titolo, *genere, *prezzo, *copie;
    struct genere *headGeneri = NULL;
    int counter = 0, nc = 0, comma = 0;
    
    autore = str[0]; titolo = str[1]; genere = str[2]; prezzo = str[3]; copie = str[4];
    while ( (c = fgetc(fp)) != EOF) {
        if (c=='\n') {
            str[counter][nc] = '\0';
            if (counter == 4)
                headGeneri = inserisciLibro(headGeneri, autore, titolo, genere, atof(prezzo), atoi(copie));
                //printf("%s; %s; %s; %f; %d\n", autore, titolo, genere, atof(prezzo), atoi(copie));
            counter = 0;
            nc = 0;
            
            continue;
        }
        
        if (c!=',') {
            if (c != '"') {
                str[counter][nc] = c;
                nc++;
            }
            else {
                comma = (comma == 0) ? 1 : 0;
            }
        } else {
            if (comma) {
                str[counter][nc] = c;
                nc++;
            } else {
                str[counter][nc] = '\0';
                counter++;
                nc = 0;
            }
        }
        
    }
    
    return headGeneri;
}
