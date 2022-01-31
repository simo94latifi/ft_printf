#include "ft_printf.h"


/*
void varfunc(int test, int num, ...)
{
	int count;
	count = test;

	va_list ap;
	va_start(ap, test);
	while(count > 0)
	{
		printf("args value is : %d \n", va_arg(ap, int));
		count--;
	}
	va_end(ap);
}
*/
int main(void)
{
	//varfunc(4,3, 2,4,4);
	int n = 42;
	char z = 'Z';
	char tab[] = "Boook";
	//ft_printf("the value of school is : %d \n", n);
	//ft_printf("%c", z);
	//ft_putnbr(1338);
	//ft_printf("value is %s", tab);
	//ft_printf(" hey i%c %d @@", z, n);
	ft_printf("add of z %p", z);
}
