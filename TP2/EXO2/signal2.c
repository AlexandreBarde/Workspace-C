#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{

  if(argc != 2)
  {
    perror("wesh wesh !");
    exit(-1);
  }

  time_t t;
	t = time(NULL);
	printf("Date : %s", ctime(&t));

	printf("Login : %s\n", getenv("LOGNAME"));

	printf("UID : %i\n", getuid());

  printf("PID : %i\n", getpid());

  kill(atoi(argv[1]), SIGUSR1);

  return 0;
}
