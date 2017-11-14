#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
  printf("Processus père - PID : %d\n", getpid());

  int processus = fork();

  int rapport;

  switch(processus)
  {
    case 0:
      sleep(2);
      printf("Processus fils - PID : %d\n", getpid());
      printf("Processus fils - PPID : %d\n", getppid());
      exit(0);
      break;
    case -1:
      perror("Error processus fils");
      exit(-1);

  }

  wait(&rapport);

}
