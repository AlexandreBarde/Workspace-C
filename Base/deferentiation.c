#include <stdio.h>

int main(void)
{
	int a;
	int b;
	char c;
	char d;
	int *ptrC;	
	int *ptrB;

	a = 3;
	b = 42;
	c = '3';
	d = '4';
	ptrB = &a + 1; //+4 : Car c'est un pointeur d'entier, et le programme sait qu'un entier vaut 4 octets
	ptrC = &c + 1; //+1 : Car c'est un pointeur de caractère, et le programme sait qu'un char vaut 1 octet	

	printf("Adresse de a : %p\n", &a);
	printf("Adresse de b : %p\n", &b);
	printf("Valeur de a : %d\n", a);
	printf("Valeur de b : %d\n", b); 
	printf("Adresse de c : %p\n", &c);
	printf("Adresse de d : %p\n", &d);
	printf("Valeur de c : %c\n", c);
	printf("Valeur de d : %c\n", d);
	printf("Adresse de b : %p\n", ptrB);
	printf("Adresse de d : %p\n", ptrC);
	printf("Valeur de d : %c\n", *ptrC);	
	return (0);

}
