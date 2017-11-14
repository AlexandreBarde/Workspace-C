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

    char* argument[] = {"fils2", "42", NULL};

    switch (processus2)
    {
      case 0:
        //error2 = execl("./fils2", "fils2", "42", NULL);
        error2 = execvp("./fils2", argument);
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
