#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	int total;
	int *counter;
	int pos;

	pos = 0;
	counter = &pos;
	total = 0;
	while(format[*counter] != '\0')
	{
		if(format[*counter] == '%')
		{
			total += is_string(format[*counter + 1], counter, ap);
			if(total)
				continue;
		}
		total += ft_putchar(format[*counter]);
		(*counter)++;
	}
	return(total);
}


int main(void)
{

	char z = 'Z';
	char tab[] = "Simo";
	int res;
	int n = 1337;
	//res = ft_printf("hh %s%s", "www", tab);
	//printf("%d \n", );
	//printf("value int %d \n ", ft_putnbr(1337, 10));
	res = ft_printf(" hey i%c %d @@ \n %s", z, n, tab);
	printf("%d \n", res);
	return(0);

}
