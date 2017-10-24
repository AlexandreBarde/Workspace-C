#include <math.h>
#include <stdio.h>

int main()
{
  int a = 0, b = 0;

  printf("a : %d b : %d\n", a, b);

  puts("Calculatrice\n\n");
  puts("Valeur de a : \n");
  scanf("%d", &a);
  puts("Valeur de b : \n");
  scanf("%d", &b);
  printf("Valeur de a + b : %d\n", a+b);

  return 0;
}
