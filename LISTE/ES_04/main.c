/*
Definire una funzione deallocaLista che riceve una ListaDiElementi e ne dealloca tutti gli elementi.
*/
#include <stdlib.h>
#include "..\..\LIBRERIA\library.c"


int main(int argc, char const *argv[]){
    /* code */
    El *lista = NULL;
    inputLista(&lista);
    stampaLista(lista);
    printf("\n%d\n", lunghezzaRicorsiva(lista));
    deAllocaLista(lista);
    printf("\n%d\n", lunghezzaRicorsiva(lista));
}



