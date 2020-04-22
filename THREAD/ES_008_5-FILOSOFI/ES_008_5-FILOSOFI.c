/*
5 filosofi sono a tavola per mangiare
Per mangiare occorrono 2 forchette
Alla destra di ciascun filosofo c'è una forchetta.
Per mangiare il filosofo deve prendere sia la forchetta alla sua destra
e anche la forchetta alla sua sinistra
Dopo aver mangiato il filosofo mette a posto le forchette e pensa per un po'
Poi gli viene ancora fame e cerca di mangiare
VINCOLI DEL PROBLEMA
1) Evidentemente non potranno mangiare tutti contemporaneamente ma occorre assicurare
il massimo grado di parallelismo. Cioè devo permetere che 2 filosofi (non adiacenti) mangino assieme
utilizzando 4 delle 5 forchette.
2) Contemporaneamente andrebbe evitato il deadlock: se ciascun filosofo prende la forchetta
di sinistra e poi si mette in attesa di quella di destra, si bloccano tutti indefinitamente.
Se si accorgono del blocco e tutti posano assieme la loro forchetta e poi le riprendono assieme
allora potrebbero non mangiare mai nessuno (starvation).
Come evitare il deadlock:
1. Prendere due forchette assieme, solo quando sono libere entrambe
2. Prendere le forchette in ordine diverso (tutti prendono per prima la forchetta alla destra, uno solo la forchetta a sinistra).
*/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define N 5

sem_t S[N];
int fil[N] = {0, 1, 2, 3, 4};

void *filosofo(void *num);

int main(int argc, char const *argv[]) {
  /* code */
  pthread_t t[N];
  for(int i=0; i<N; i++) sem_init(&S[i], 0, 1); // Sbloccato
  for(int i=0; i<N; i++) pthread_create(&t[i], NULL, filosofo, &fil[i]);
  for(int i=0; i<N; i++) pthread_join(t[i], NULL);
  return 0;
}

void *filosofo(void *num){
  int *i = num;
  while(1){
    printf("Il filosofo %d sta pensando\n", *i+1);
    sleep(1);
    printf("Il filosofo %d ha fame\n", *i+1);
    sleep(1);
    // prendi forchette
    if (sem_trywait(&S[*i])==0) {
      /* code */
      if (sem_trywait(&S[*i+1])==0) {
        /* code */
        printf("Il filosofo %d mangia\n", *i+1);
        sleep(1);
        sem_post(&S[*i]);
        sem_post(&S[*i+1]);
        // posa forchette
      }else sem_post(&S[*i]);
    }else sem_post(&S[*i+1]);
  }
}
