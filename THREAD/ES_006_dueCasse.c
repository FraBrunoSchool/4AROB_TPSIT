/*
        Creare un programma che simuli l'acquisto dei biglietti di un cinema avente due casse
        I biglietti disponibili sono prefissati (risorsa condivisa)
        All'avvio vengono generati n clienti/threads "per la cassa1 e per la cassa2" per procedere all'acquisto.
            - Gestire la situazione in cui vengono generati x clienti per cassa1 e y clienti per cassa2
        Ogni cliente:
            - accede alla risorsa "biglietti disponibili" in modalità ESCLUSIVA
            - random, acquista un numero di biglietti compreso tra 1 e 5
            - infine, stampa un messaggio a video indicando
                1. Quanti biglietti ha tentato di acquistare
                2. Quanti biglietti ha di fatto acquistato
                3. Quanti biglietti sono ancora disponibili
            - prevedere la possibilità in cui:
                1. non tutti i clienti riescano ad acquistare x biglietti (in questo caso acquistare i biglietti residui)
                2. i biglietti siano completamente esauriti
        La rispettiva cassa, al termine di ogni acquisto (o tentativo di acquisto), valuta, con probabilità 1/2 (50% o random val 0-1),
        se far 'passare' il cliente subito successivo alla medesima fila oppure dare la precedenza al cliente in fila sull'altra cassa
        Esempio esecuzione:
        > Sono il cliente 489737546 in fila alla cassa1 e voglio acquistare 4 biglietti:
        > biglietti acquistati: 4
        > biglietti disponibili: 96
        > Sono il cliente 794632639 in fila alla cassa2 e voglio acquistare 3 biglietti:
        > biglietti acquistati: 3
        > biglietti disponibili: 93
        > Sono il cliente 876432834 in fila alla cassa2 e voglio acquistare 10 biglietti:
        > biglietti acquistati: 10
        > biglietti disponibili: 83
        ....
        > Sono il cliente 982374984 in fila alla cassa1 e voglio acquistare 8 biglietti:
        > biglietti acquistati: 2
        > biglietti disponibili: 0
        > Sono il cliente 876865756 in fila alla cassa2 e voglio acquistare 10 biglietti:
        > biglietti acquistati: 0
        > biglietti disponibili: 0
*/
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define CLIENTI 25

pthread_mutex_t m1, m2;
int numeroBiglietti=100;

void *cassa1(void *arg);
void *cassa2(void *arg);

int main(int argc, char const *argv[]) {
  /* code */

  pthread_t t[CLIENTI];

  pthread_mutex_unlock(&m1); //sblocchiamo la mutex ->verde
  pthread_mutex_unlock(&m2); //blocchiamo la mutex ->rosso
  srand(time(NULL));
  for (int i=0; i < CLIENTI; i++) {
    /* code */
    int r = rand() %2;
    if (r == 0) pthread_create(&t[i], NULL, (void *)cassa2, NULL);
    else if (r==1) pthread_create(&t[i], NULL, (void *)cassa1, NULL);
    sleep(1);
  }

  for (int i=0; i < CLIENTI; i++) pthread_join(t[i], NULL);

  return 0;
}

void *cassa1(void *arg) {
  /* code */
  pthread_mutex_lock(&m1); //blocchiamo la mutex ->rosso

  int  i = rand() % 10 + 1;

  printf("\n> Sono il cliente %ld in fila alla cassa1 e voglio acquistare %d biglietti: \n", pthread_self(), i);

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

  pthread_mutex_unlock(&m2); //sblocchiamo la mutex ->verde
  pthread_exit(NULL);
}

void *cassa2(void *arg) {
  /* code */
  pthread_mutex_lock(&m2); //blocchiamo la mutex ->rosso

  int  i = rand() % 10 + 1;

  printf("\n> Sono il cliente %ld in fila alla cassa2 e voglio acquistare %d biglietti: \n", pthread_self(), i);

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
