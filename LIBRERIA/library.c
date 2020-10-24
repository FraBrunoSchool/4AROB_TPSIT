#include "library.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

void ordinaRipplesort(El *l) {
    El *lista = l;
    int x;
    while (l->next != NULL){
        if ((l->valore) > (l->next->valore)) {
            x = l->next->valore;
            l->next->valore = l->valore;
            l->valore = x;
            l = lista;
        }else{
            printf("else\n");
            l = l->next;
        }
    }
}

El *merge(El *l, El *l2){
    El *firstElement = NULL;
    El *pointer = NULL;

    while(l != NULL) {
        if (pointer == NULL) {
            firstElement = (El *) malloc(sizeof(El));
            firstElement->valore = l->valore;
            firstElement->next = NULL;
            pointer = firstElement;
        }
        else {
            pointer->next = (El *) malloc(sizeof(El));
            pointer = pointer->next;
            pointer->valore = l->valore;
            pointer->next = NULL;
        }
        l = l-> next;
    }

    while(l2 != NULL) {
        if (pointer == NULL) {
            firstElement = (El *) malloc(sizeof(El));
            firstElement->valore = l2->valore;
            firstElement->next = NULL;
            pointer = firstElement;
        }
        else {
            pointer->next = (El *) malloc(sizeof(El));
            pointer = pointer->next;
            pointer->valore = l2->valore;
            pointer->next = NULL;
        }
        l2 = l2-> next;
    }

    ordinaRipplesort(firstElement);

    return firstElement;
}

void stampaPila(El **head){  //stampo la pila
    El *ret;
    int i=1;

    ret=pop(head);
    while(ret!=NULL){   //ripeto finchè ci sono elementi
        printf("\n valore [%d]: %d", i, ret->valore);
        i++;
        free(ret);  //libero lo spazio che ormai non mi serve più
        ret=pop(head);  //leggo il prossimo elemento
    }
}

bool controlloStringa(char cifra[]){    //controllo se la stringa è composta solo da cifre
    char numeri[11]="0123456789";
    int i,k;
    bool error=true;
    for(i=0;cifra[i]!='\0';i++){
        for(k=0;k<11;k++){
            if(cifra[i]==numeri[k]){
               error=false;
            }
        }
        if(error!=false){
            return false;
        }else{
            error=true;
        }
    }
    return true;
}