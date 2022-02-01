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
			if(!total || format[*counter] == '\0')
				break;
			else if (total)
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
	int res = 44025;
	int pp;
	printf ("%d",printf("%p", &tab));
	printf("\n");
	printf ("%d",ft_printf("%p", &tab));

	/*
	printf("\n%d printf \n", &pp);
	ft_printf("\n%d ft_printf \n", &pp);
	printf("\n nostro : %d \n", ciao);
	printf("\n%d printf \n", pp);
	printf("\n%p printf \n", &pp);
	*/
	//ft_printf("%x%x", res, res);
	// res = ft_printf("%s", "www");
	//printf("%d \n", );
	//printf("value int %d \n ", ft_putnbr(1337, 10));
	//printf("%d", total);putnb
	return(0);
}
