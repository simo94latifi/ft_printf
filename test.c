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
	int n = 16432339;
	char z = 'Z';
	int num = -1;
	int res;
	char tab[] = "Boook";
	//ft_printf("the value of school is : %d \n", n);
	//ft_printf("value of  on ftprintf : %x  \n", n);
	//printf("value of on printf : %x  \n", n);
	//ft_putnbr(1338);
	ft_printf("value is %c", z);
	//res = ft_printf(" hey i%c %d @@ \n", z, n);
	//printf("count is : %d \n", res);
	//ft_printf("add of z %p", z);
	//ft_printf("%%%%%d", 15);
}
