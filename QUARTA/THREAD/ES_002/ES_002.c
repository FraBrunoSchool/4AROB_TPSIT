#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void stampaMsg(void *arg);

int main(int argc, char const *argv[]) {
  /* code */
  pthread_t t[10];

  printf("Padre: creo 10 thread\n");
  for (int i=0; i<10; i++) {
    /* code */
    //funzione creazione thread
    pthread_create(&t[i], NULL, (void *)stampaMsg, (void *) &i);
  }

  printf("Padre: attendo la terminazione\n");
  int *ret;
  for (int i=0; i<10; i++) {
    /* code */
    //funzione creazione thread
    pthread_join(t[i], (void**)&ret);
    printf("Restituzione pthread_exit: %d\n", *ret);
  }
  printf("Padre: thread sono terminati, chiudo applicazione\n");
  return 0;
}

void stampaMsg(void *arg) {
  /* code */
  int tId=pthread_self();
  int dato= *((int*)arg);
  int *dato_din=(int*)malloc(sizeof(int));
  *dato_din=*((int*)arg);
  printf("Sono il thread %u. Parametro passato: %d. Parametro passato din: %d\n", tId, dato, *dato_din);
  pthread_exit(&dato_din);
}
