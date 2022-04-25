#ifndef dati_h
#define dati_h
#define STRINGLEGTH  256

struct book{
    char autore[STRINGLEGTH];
    char titolo[STRINGLEGTH];
    float prezzo;
    int   Ncopie;
    struct book *next;
};


struct genere {
    char genere[STRINGLEGTH];
    struct book *lista;
    struct genere *next;
};


struct genere *leggiFile(FILE *fp);
void stampaLibri(struct genere *headGenere);
void freeGeneri(struct genere *head);
struct genere *rimuoviCopie(struct genere *head, int soglia);

#endif /* dati_h */
