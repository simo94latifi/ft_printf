#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return(1);
}

int	ft_putstr(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while(str[i] != '\0')
	{
		count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}

int	ft_putnbr(int n, int base)
{
	int count;

	count = 0;
	if (n == -2147483648 && base == 10)
	{
		count += ft_putchar('-');
		count += ft_putchar('2');
		ft_putnbr(147483648, base);
	}
	else if (n < 0 && base == 10)
	{
		count += ft_putchar('-');
		ft_putnbr(-n, base);
	}
	else if (n < base)
		count += ft_putchar(n + '0');
	else
	{
		ft_putnbr(n / base, base);
		ft_putnbr(n % base, base);
	}
	return (count);
}
int	get_digits(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	ft_putnbr_unsigned_int(unsigned int n)
{

	if (n < 0)
	{
		n = (4294967295 + n);
		ft_putnbr_unsigned_int(n);
	}
	else if (n < 10)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr_unsigned_int(n / 10);
		ft_putnbr_unsigned_int(n % 10);
	}
}

void	ft_putnbr_hex(unsigned long long int n, char sign)
{
	char *i;
	if (sign == 'X')
		i = "0123456789ABCDEF";
	else if (sign == 'x')
		i = "0123456789abcdef";

	if (n < 16)
	{
		ft_putchar(i[n]);
		return ;
	}
	else
		ft_putnbr_hex(n / 16, sign);
		ft_putnbr_hex(n % 16, sign);
}

int	is_string(char c, int *counter, va_list ap)
{
	int total;

	total = 0;
	if(c == 'c')
		total += ft_putchar(va_arg(ap, int));
	else if(c == 's')
		total += ft_putstr(va_arg(ap, char *));
	else if(c == 'd' || c == 'i')
		ft_putnbr(va_arg(ap, int), 10);
	else if(c == 'u')
		ft_putnbr_unsigned_int(va_arg(ap, unsigned int));
	else if(c == 'X' || c == 'x')
		ft_putnbr_hex(va_arg(ap, unsigned long long int), c);
	else if(c == '%')
		total += ft_putchar('%');
	*counter += 2;
	return (total);
}
