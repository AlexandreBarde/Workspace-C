#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void traiterSignal(int numSignal);

void afficherInfos();

typedef void (*PtrFunction) (int);

int main(void)
{

  afficherInfos();

  //char chaine[255];

  alarm(2);

  //scanf("%s\n", chaine);

  PtrFunction function;

	function = signal(SIGALRM, traiterSignal);

  if(function == SIG_ERR)
	{
		perror("Erreur");
		exit(0);
	}

  while(1)
  {
      sleep(10);
  }

  return 0;

}

void afficherInfos()
{
  time_t t;
  t = time(NULL);
  printf("Date : %s", ctime(&t));

  printf("Login : %s\n", getenv("LOGNAME"));

  printf("UID : %i\n", getuid());

  printf("PID : %i\n", getpid());
}

void traiterSignal(int numSignal)
{
	if(numSignal != SIGALRM)
	{
		perror("Erreur (2)");
		exit(-1);
	}
	puts("SIGALRM reçu");
  exit(0);
}
