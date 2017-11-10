#include <stdio.h>
#include <stdlib.h>

void kifkif(int* a);

int main(int argc, char** argv)
{
	int a = 2;
	printf("a = %d\n", a);
	kifkif(&a);
	return a;
}

void kifkif(int* a)
{
	*a = 4;
	
}

