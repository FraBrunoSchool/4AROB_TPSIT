#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t m;

void *ping(void *arg) {
  /* code */
  while (1) {
    /* code */
    //Sezione critica
    printf("ping\n");
    //fine Sezione critica
  }
}

void *pong(void *arg) {
  /* code */
  while (1) {
    /* code */
    //Sezione critica
    printf("pong\n");
    // fine Sezione critica
  }
}

int main(int argc, char const *argv[]) {
  /* code */
  pthread_t t1, t2;

  pthread_mutex_unlock(&m); //sblocchiamo la mutex ->verde

  pthread_create(&t1, NULL, (void*)ping, NULL);
  pthread_create(&t2, NULL, (void*)pong, NULL);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  return 0;
}
