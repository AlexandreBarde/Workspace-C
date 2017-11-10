#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>

int main()
{

  time_t t;
  t = time(NULL);
  printf("Date : %s", ctime(&t));

  printf("Login : %s\n", getenv("LOGNAME"));

  printf("UID : %i\n", getuid());

  int resFork1 = fork();

  switch(resFork1)
  {
    case 0:
      printf("Processus 1 - PID : %d\n", getpid());
      exit(3);
      break;
    case -1:
      perror("Error");
      exit(-1);
      break;
  }

  int resFork2 = fork();

  switch (resFork2)
  {
    case 0:
      printf("Processus 2 - PID : %d\n", getpid());
      int* ptrInt = NULL;
      (*ptrInt) = 0;
      exit(0);
      break;
    case -1:
      perror("Error");
      exit(-1);
      break;
  }

  int resFork3 = fork();

  switch(resFork3)
  {
    case 0:
      printf("Processus 3 - PID : %d\n", getpid());
      int test = 1/0;
      exit(0);
      break;
    case -1:
      perror("Error");
      exit(-1);
      break;
  }

  int rapport;
  pid_t pidFils;
  pidFils = wait(&rapport);

  while(pidFils != -1)
  {
    int numSig = rapport &0x7F;
    switch(numSig)
    {
      case 0:
        printf("Fin normale du processus %i qui retourne : %d\n", pidFils, WEXITSTATUS(rapport));
        break;
      default:
        printf("Fin anormale du processus %d qui retourne : %d\n", pidFils, numSig);
        break;
    }
    pidFils = wait(&rapport);
  }

  //XEXITSTATUS => status = (rapport >> 8) & 0x7F;

  //printf("PID : %d\n", getpid());

  //printf("PPID : %d\n", getppid());

}
