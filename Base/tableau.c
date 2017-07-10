#include <stdio.h>

int main(void)
{
	int tab[10];
	int tab2[10];
	int *tabPtr[2];

	tabPtr[0] = tab;
	tabPtr[1] = tab2;

	*(tabPtr[1] + 3) = 42;	
	tabPtr[0][3] = 42;

	printf("%d\n", tab[3]);
	 printf("%d\n", tab2[3]);

}

