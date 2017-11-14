#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
  int processus1 = fork();


  int i = 0;
  int i2 = 26;

  switch(processus1)
  {
    case 0:
      for (;i <= 25; i++)
      {
        printf("%i\n", i);
      }
      exit(1);
      break;
    case -1:
      perror("Error processus 1");
      exit(-1);
  }

int rapport;

wait(&rapport);

int processus2 = fork();

  switch(processus2)
  {
    case 0:
      for (; i2 <= 50; i2++)
      {
        printf("%i\n", i2);
      }
      exit(2);
      break;
    case -1:
      perror("Error processus 2");
      exit(-1);
  }

  sleep(7);


}
