#include <stdio.h>
#include <unistd.h>

void ft_putnbr(int ptr);
void ft_putaddr(void *ptr);
void ft_putchar(char c);

int main(void)
{
	int a;
	int *ptr;
	
	a = 3;
	ptr = &a;
	ft_putaddr(ptr);
	*ptr = 42;	
	ft_putnbr(a);
	return 0;
}

void ft_putaddr(void *ptr)
{
	printf("%p\n", &ptr);
}

void ft_putnbr(int ptr)
{
	printf("%d\n", ptr);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}
