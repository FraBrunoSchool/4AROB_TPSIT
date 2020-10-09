#ifndef LIBRERIA_LIBRARY_H
#define LIBRERIA_LIBRARY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct el{
    /* data */
    int valore;
    struct el *next;
}El;

void enqueue(El **head, El **tail, El *element);
El *dequeue (El **head ,El **tail );
int is_empty(El *head);
void stampaLista(El * l);
void push(El **head, El *element);
El *pop(El **head);
void inversione(El **head, El **tail);
void inputCoda(El **head, El **tail);
void svuotaCoda(El **head, El **tail);
void inputLista(El **head);
void stampaListaNonRicorsiva(El* l);
void lunghezzaCiclo(El *l, int *cont);
int lunghezzaRicorsiva(El *l);
void deAllocaLista(El *l);
void ordinaRipplesort(El *l);
El *merge(El *l, El *l2);
void stampaPila(El **head);
bool controlloStringa(char cifra[]);

#endif //LIBRERIA_LIBRARY_H