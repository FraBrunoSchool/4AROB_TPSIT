#include <stdlib.h>
#include "..\..\LIBRERIA\library.c"

int main(int argc, char const *argv[]){
    /* code */

    El* head = NULL;   //puntatore al primo elemento
    El* tail = NULL;

    inputCoda(&head, &tail);
    stampaLista(head);
    inversione(&head, &tail);
    stampaLista(head);

    return 0;
}