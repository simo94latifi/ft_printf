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
				continue;
			}
			else if(format[counter + 1] == 'p')
			{
				/* add p */
			}
			else if(format[counter + 1] == 'd' || format[counter + 1] == 'i')
			{
				ft_putnbr(va_arg(ap, int), 10);
				counter += 2;
				continue;
			}
			else if(format[counter + 1] == 'u')
			{
				ft_putnbr_unsigned_int(va_arg(ap, unsigned int));
				counter += 2;
			}
			else if(format[counter + 1] == 'x')
			{
				ft_putnbr_hex(va_arg(ap, unsigned long long int), 'l');
				counter += 2;
			}
			else if(format[counter + 1] == 'X')
			{
				ft_putnbr_hex(va_arg(ap, unsigned long long int), 'u');
				counter += 2;
			}
			if(format[counter + 1] == '%')
			{
				ft_putchar('%');
				counter += 2;
				continue;
			}

		}
		ft_putchar(format[counter]);
		counter++;
	}

	return(0);
}


