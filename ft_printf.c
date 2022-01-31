#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	int counter;
	va_list ap;
	va_start(ap, format);

	counter = 0;
	while(format[counter] != '\0')
	{
		if(format[counter] == '%')
		{
			if(format[counter + 1] == 'c')
			{
				ft_putchar(va_arg(ap, int));
				counter += 2;
				continue;
			}
			else if(format[counter + 1] == 's')
			{
				ft_putstr(va_arg(ap, char *));
				counter += 2;
			}
			else if(format[counter + 1] == 'p')
			{
				/* add p */
			}
			else if(format[counter + 1] == 'd')
			{
				ft_putnbr(va_arg(ap, int), 10);
				counter += 2;
			}
		}
		ft_putchar(format[counter]);
		counter++;
	}

	return(0);
}


