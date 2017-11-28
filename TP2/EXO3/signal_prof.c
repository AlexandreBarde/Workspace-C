#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <setjmp.h>

jmp_buf ptRep;

int main(void)
{

  char message[256];

  //signal

  int nbEssais = 0;

  int ret = setjmp(ptRep);

  nbEssais ++;

  if(ret == 12)
  {
    if(nbEssais > 2)
    {
      exit(0);
    }
  }

  printf("Saisir quelque chose\n");

  alarm(5);

  fgets(message, 256, stdin);


}


void traiterSignal()
{
  sigrelse(SIGALRM);
  longjmp(ptRep, 12);
}
