#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    /* code */
    int dim;
    int* punt;
    printf("Inserisci dimensione: ");
    scanf("%d", &dim);
    int *vett = malloc((dim)*sizeof(int));
    printf("Inserisci numeri: \n");

    for (int i = 0; i < dim; i++) {
        /* code */
        scanf("\t%d", vett+i);
    }

    for (int i = 0; i < dim; i++) {
        /* code */
        printf("|%d|: %d\n", i, *vett + i);
    }
    
    return 0;
}
