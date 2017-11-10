#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>

int main(void)
{
    int processus1 = fork();
    int error;

    switch (processus1)
    {
      case 0:
        error = execl("./fils1", "fils1", "bonjour", NULL);
        if(error == -1)
        {
          perror("Error execl fils1");
          exit(-1);
        }
        break;
      case -1:
        perror("Erreur processus1 execl");
        exit(-1);
        break;
    }

    int processus2 = fork();
    int error2;

    switch (processus2)
    {
      case 0:
        error2 = execl("./fils2", "fils2", "42", NULL);
        if(error2 == -1)
        {
          perror("Error execl fils2");
          exit(-1);
        }
        break;
      case -1:
        perror("Erreur processus2 execl");
        exit(-1);
        break;
    }

    return 0;
}
