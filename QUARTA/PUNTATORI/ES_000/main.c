#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  /* code */
  int dim;
  int magg;
  printf("Inserisci dimensione: ");
  scanf("%d", &dim);
  int *vett = malloc((dim)*sizeof(int));
  printf("Inserisci numeri: \n");

  for (int i = 0; i < dim; i++) {
    /* code */
    scanf("\t%d", &vett[i]);
  }

  for (int i = 0; i < dim; i++) {
    /* code */
    printf("|%d|: %d\n", i, vett[i]);
  }

  magg = vett[0];
  for (int i = 1; i < dim; i++) {
    /* code */
    if (vett[i] > magg) {
      /* code */
      magg = vett[i];
    }
  }
  printf("il maggiore è: %d\n", magg);
  return 0;
}
