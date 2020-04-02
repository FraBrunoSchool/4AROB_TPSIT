/*
    Creare un programma che simuli l'acquisto dei biglietti di un concerto
    I biglietti disponibili sono prefissati (risorsa condivisa)
    All'avvio vengono generati n clienti/threads che "vanno alla cassa" per procedere all'acquisto.
    Ogni cliente:
        - accede alla risorsa "biglietti disponibili" in modalità ESCLUSIVA
        - random, acquista un numero di biglietti compreso tra 1 e 10
        - infine, stampa un messaggio a video indicando
            1. Quanti biglietti ha tentato di acquistare
            2. Quanti biglietti ha di fatto acquistato
            3. Quanti biglietti sono ancora disponibili
        - prevedere la possibilità in cui:
            1. non tutti i clienti riescano ad acquistare x biglietti (in questo caso acquistare i biglietti residui)
            2. i biglietti siano completamente esauriti
    Esempio esecuzione:
    > Sono il cliente 489737546 e voglio acquistare 4 biglietti:
    > biglietti acquistati: 4
    > biglietti disponibili: 96
    ....
    > Sono il cliente 792837528 e voglio acquistare 8 biglietti:
    > biglietti acquistati: 2
    > biglietti disponibili: 0
    > Sono il cliente 876865756 e voglio acquistare 10 biglietti:
    > biglietti acquistati: 0
    > biglietti disponibili: 0
*/

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t m1;
int numeroBiglietti=100;

void *cassa(void *arg) {
  /* code */
  pthread_mutex_lock(&m1); //blocchiamo la mutex ->rosso

  srand(time(NULL));
  int  i = rand() % 10 + 1;

  printf("\n> Sono il cliente %ld e voglio acquistare %d biglietti: \n", pthread_self(), i);

  if (numeroBiglietti>0) {
    /* code */
    printf("> biglietti disponibili prima l'acquisto: %d\n", numeroBiglietti>=0?numeroBiglietti:0);
    printf("> biglietti acquistati: %d\n", numeroBiglietti>=i?i:numeroBiglietti);
    numeroBiglietti=numeroBiglietti-i;
    printf("> biglietti disponibili dopo l'acquisto: %d\n", numeroBiglietti>=0?numeroBiglietti:0);
  }else{
    if (numeroBiglietti<=0) {
      /* code */
      printf("> biglietti acquistati: 0\n");
      printf("> biglietti disponibili: 0\n");
    }
  }

  pthread_mutex_unlock(&m1); //sblocchiamo la mutex ->verde
  pthread_exit(NULL);
}

int main(int argc, char **argv){
  pthread_t t[20];
  pthread_mutex_unlock(&m1); //sblocchiamo la mutex ->verde

  for (int i=0; i<20; i++) {
    /* code */
    pthread_create(&t[i], NULL, (void *)cassa, NULL);
    sleep(1);
  }

  for (int i=0; i<20; i++) pthread_join(t[i], NULL);

  return 0;
}
