#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	int *counter;
	int total;
	va_list ap;
	va_start(ap, format);

	*counter = 0;
	total = 0;
	while(format[*counter] != '\0')
	{
		if(format[*counter] == '%')
		{
			if(is_string(format[*counter + 1], counter, ap))
			{
				total += is_string(format[*counter + 1], counter, ap);
				continue;
			}
		}
		total += ft_putchar(format[*counter]);
		(*counter)++;
	}

	return(0);
}


int main(void)
{
	int n = 712466;
	char z = 'Z';
	//char tab[5] = "simo";
	ft_printf("hey %s the num is %X %%%d \n", "tab", n, n);
	return(0);

}
