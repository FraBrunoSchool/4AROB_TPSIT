#include <stdio.h>
#include <pthread.h>

void *uno(void *arg);
void due(void *arg);

int main(int argc, char const *argv[]) {
  /* code */
  pthread_t t1, t2;
  printf("Padre: creo 2 thread\n");

  //funzione creazione thread
  pthread_create(&t1, NULL, (void * )uno, NULL);
  pthread_create(&t2, NULL, (void * )&due, NULL);
  printf("Padre: attendo la terminazione\n");
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  printf("Padre: thread sono terminati, chiudo applicazione\n");
  return 0;
}

void *uno(void *arg) {
  /* code */
  printf("Sono il thread che esegue la funzione 1\n");

  pthread_exit(0);
}

void due(void *arg) {
  /* code */
  printf("Sono il thread che esegue la funzione 2\n");

  pthread_exit(0);
}
