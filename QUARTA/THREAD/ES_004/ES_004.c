#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t m1, m2;

void *ping(void *arg) {
  /* code */
  while (1) {
    /* code */
    //Sezione critica
    pthread_mutex_lock(&m1); //blocchiamo la mutex ->rosso
    printf("ping\n");
    pthread_mutex_unlock(&m2); //sblocchiamo la mutex ->verde
    //fine Sezione critica
  }
}

void *pong(void *arg) {
  /* code */
  while (1) {
    /* code */
    //Sezione critica
    pthread_mutex_lock(&m2); //blocchiamo la mutex ->rosso
    printf("pong\n");
    pthread_mutex_unlock(&m1); //sblocchiamo la mutex ->verde
    // fine Sezione critica
  }
}

int main(int argc, char const *argv[]) {
  /* code */
  pthread_t t1, t2;

  pthread_mutex_unlock(&m1); //sblocchiamo la mutex ->verde
  pthread_mutex_unlock(&m2); //blocchiamo la mutex ->rosso

  pthread_create(&t1, NULL, (void*)ping, NULL);
  pthread_create(&t2, NULL, (void*)pong, NULL);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  return 0;
}
