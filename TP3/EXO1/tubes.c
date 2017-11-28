#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

void traiterFils(int descPipe[2], FILE* file);

int main(void)
{

  FILE* file = NULL;
  file = fopen("data.txt", "w");

  int descriptionPipe[2];

  int resPipe = pipe(descriptionPipe);

  if(resPipe == -1)
  {
    perror("Pipe exit");
  }

  int processus = fork();

  switch (processus)
  {
    case -1:
      perror("Erreur processus 1");
      exit(-1);
      break;
    case 0:
      traiterFils(descriptionPipe, file);
      break;
  }

  close(descriptionPipe[0]);

  char buffer[256];

  printf("Saisir quelque chose : ");

  do
  {
    fgets(buffer, sizeof(buffer), stdin); //sizeof => taille du tableau pour éviter de retaper 256
    write(descriptionPipe[1], buffer, strlen(buffer) + 1);
  }while(strcmp(buffer, "stop\n") != 0);

  wait(NULL);

  return 0;
}

void traiterFils(int descPipe[2], FILE* file)
{
  close(descPipe[1]);
  char buffer[256];
  do
  {
    read(descPipe[0], buffer, sizeof(buffer)); //Copie de descPipe[0] au buffer
    if(file != NULL)
    {
      fputs(buffer, file);
    }
  }while(strcmp(buffer, "stop\n") != 0);
  fclose(file);
  exit(0);
}
