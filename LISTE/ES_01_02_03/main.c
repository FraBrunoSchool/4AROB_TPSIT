/*crea una lista e la struct stampa*/
#include <stdlib.h>
#include "..\..\LIBRERIA\library.c"


int main(int argc, char const *argv[]){
    /* code */
    El *lista = NULL;
    inputLista(&lista);
    stampaLista(lista);
    stampaListaNonRicorsiva(lista);
    int n=0;
    lunghezzaCiclo(lista, &n);
    printf("\n%d\n", n);
    printf("\n%d\n", lunghezzaRicorsiva(lista));
}

