#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char ** argv)
{

  printf("Processus 2 - PID : %d - Paramètre : %s - Hexa : %x\n", getpid(), argv[1], atoi(argv[1]));

}
