#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char ** argv)
{

  printf("Processus 1 - PID : %d - Paramètre : %s\n", getpid(), argv[1]);
  
}
