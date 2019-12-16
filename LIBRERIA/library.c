#include "library.h"

#include <stdio.h>
#include <stdlib.h>

void enqueue(El **head, El **tail, El *element){

    if (is_empty(*head)){
        /* code */
        *head = element;
    }else{
        /* code */
        (*tail)->next = element;
    }

    *tail = element;
    element->next = NULL;
}

El *dequeue (El **head ,El **tail ){

    El *ret = *head;

    if(is_empty(*head)){
        /* code */
        return NULL;
    }else{
        /* code */
        *head = ret->next;
    }

    if(*head==NULL){
        /* code */
        *tail = NULL;
    }

    return ret;
}

int is_empty(El *head){
    return head==NULL?1:0;
}

void stampaLista(El* l) {  //inserire l'inizio della lista
    if (l != NULL) {    //ripeto finchè esiste un elemento successivo
        printf("%d \n", l->valore);    //stampo il valore dell'elemento della lista e l'indirizzo del successivo
        l = l->next; //passo all'elemento successivo della lista
        stampaLista(l); //passo all'elemento successivo
    }
}

void push(El **head, El *element){
    if (is_empty(*head)){
        /* code */
        *head = element;
        element->next = NULL;
    }else{
        /* code */
        element->next = *head;
        *head = element;
    }
}

El *pop(El **head){
    El *ret = *head;
    if(*head==NULL){
        return NULL;
    }else{
        *head = ret->next;
        return ret;
    }
}

void inversione(El **head, El **tail){
    El* ret;
    El* pila;    //creo la pila necessaria per l'inversione
    pila=NULL;

    ret=dequeue(head,tail); //estraggo gli elementi dalla coda e li metto nella lista
    while(ret!=NULL){
        push(&pila,ret);
        ret=dequeue(head,tail);
    }

    ret=pop(&pila);  //estraggo gli elementi dalla pila e li metto nella coda
    while(ret!=NULL){
        enqueue(head,tail,ret);
        ret=pop(&pila);
    }
}

void inputCoda(El **head, El **tail){
    int n;
    El *element;

    do{
        /* code */
        printf("Inserisci un naturale o -1 per terminare\n");
        scanf("%d", &n);
        if (n>=0){
            /* code */
            element = (El*) malloc(sizeof(El));
            element->valore=n;
            enqueue(head, tail, element);
            printf("\tHead: %p, Tail: %p\n", head, tail);
        }
    } while (n>=0);
}

void svuotaCoda(El **head, El **tail){
    El* element = (El*) malloc(sizeof(El));
    while(element!=NULL){   //estraggo tutti gli elementi della coda liberandone lo spazio
        element=dequeue(head, tail);
        free(element);
    }
}

void inputLista(El **head){
    int n;
    El *l;
    *head = NULL;   //inizializzo il puntatore a null

    do{
        /* code */
        printf("Inserisci un naturale o -1 per terminare\n");
        scanf("%d", &n);
        if (n>=0){
            /* code */
            if (*head == NULL){
                /* code */
                *head = (El*) malloc(sizeof(El));
                l = *head;
            }else{
                /* code */
                //assegnoal puntatore l dell'elemento corrente un puntatore che punta all'elemento successivo
                l->next = (El*) malloc(sizeof(El));
                l = l->next;
            }
            l->valore = n;  //assegno n al campo valore dell'elemento corrente
            l->next = NULL; //assegno al campo next dell'elemento correnteil valore NULL
        }
    } while (n>=0);
}

void stampaListaNonRicorsiva(El* l) {  //inserire l'inizio della lista
    while (l!=NULL){
        /* code */
        printf("%d - %p \n",l->valore, l->next);
        l = l->next;    //il puntatore corrente è assegnato al puntatore all'elemento successivo
    }
}

void lunghezzaCiclo(El *l, int *cont){
    int c = 0;
    while (l!=NULL){
        /* code */
        l = l->next;
        c++;
    }
    *cont=c;
}

int lunghezzaRicorsiva(El *l){
    if (l->next == NULL){
        return 1;
    } else {
        return 1 + lunghezzaRicorsiva(l->next);
    }
}

void deAllocaLista(El *l){
    if (l->next != NULL){
        /* code */
        deAllocaLista(l->next);
    }
    free(l);
    printf("Free\n");
}