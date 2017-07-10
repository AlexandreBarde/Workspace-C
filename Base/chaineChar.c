#include <stdio.h>

int main(void)
{
	char *ptr;
	char *ptr2;

	ptr2 = "lol";
	ptr = "toto";
	printf("Valeur : %c\n", ptr[0]);
	printf("Valeur : %c\n", ptr[1]);
	printf("Valeur : %c\n", ptr[2]);
	printf("Valeur : %c\n", ptr[3]);
	printf("Valeur : %c\n", ptr[4]); //Correspond à \0 => ça permet de savoir la fin de notre chaîne de caractère -- Pour le voir | cat -e
	ptr = ptr2;
	printf("Valeur : %c\n", ptr[0]);
	return (0);
}
