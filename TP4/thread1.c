#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef void (*ptrfunc)(char);

void *traitTH1(void *num)
{
  puts("Bonjour je suis le Thread 1 !");
  int val;
  val = *( (int *) num);
  printf("Nombre : %d\n", val);
  printf("Nombre mult : %d\n", val*2);
  pthread_exit(&val);
}

void *traitTH2(char *phrase)
{
  puts("Bonjour je suis le Thread 2 !");
  printf("%s\n", phrase);
  pthread_exit(&phrase);
}

int main(void)
{
  int nbre = 1234;
  char phrase[256] = "Bonjour je suis une phrase";
  pthread_t idThread1, idThread2;
  puts("Avant thread");

  if(pthread_create(&idThread1, NULL, traitTH1, &nbre) != 0)
  {
    perror("Echec pthread_create");
  }

  if(pthread_join(idThread1, NULL))
  {
    perror("Echec pthread_join");
  }

  if(pthread_create(&idThread2, NULL, traitTH2, (void*) phrase) != 0)
  {
    perror("Echec pthread_create 2");
  }

  if(pthread_join(idThread2, NULL))
  {
    perror("Echec pthread_join 2");
  }

  puts("Après thread");
  return 0;
}
