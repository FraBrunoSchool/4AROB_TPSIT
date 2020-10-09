/*
    Implementare i metodi enqueue() e dequeue() e creare un programma che permetta all’utente di
    riempire una coda di numeri interi di lunghezza arbitraria. Successivamente testare la funzione
    dequeue per svuotare la coda.
 */

#include <stdlib.h>
#include "..\..\LIBRERIA\library.c"


int main(int argc, char const *argv[]){
    /* code */
    El* head;   //puntatore al primo elemento
    El* tail;

    head = NULL;   //inizializzo il puntatore a null
    tail = NULL;

    inputCoda(&head, &tail);
    stampaLista(head);
    svuotaCoda(&head, &tail);
    stampaLista(head);
    return 0;
}
