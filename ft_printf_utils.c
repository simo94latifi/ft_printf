#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return(1);
}

int	ft_putstr(char *str)
{
	int	i;
	int	total;

	total = 0;
	i = 0;
	while(str[i] != '\0')
	{
		total += ft_putchar(str[i]);
		i++;
	}
	return (total);
}

void	ft_putnbr(int n)
{

	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n < 10)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
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
	int a;

	total = 0;
	if(c == 'c')
		total += ft_putchar(va_arg(ap, int));
	else if(c == 's')
		total += ft_putstr(va_arg(ap, char *));
	else if(c == 'd' || c == 'i')
	{
		a = (va_arg(ap, int));
		ft_putnbr(a);
		total += count_nbr(a);
	}
	else if(c == 'u')
		ft_putnbr_unsigned_int(va_arg(ap, unsigned int));
	else if(c == 'p')
		total += ft_putptrnbr(ap);
	else if(c == 'X' || c == 'x')
	{
		a = va_arg(ap, unsigned long long int);
		ft_putnbr_hex(a, c);
		total += count_nbrx(a);
	}
	else if(c == '%')
		total += ft_putchar('%');
	*counter += 2;
	return (total);
}

int ft_putptrnbr(va_list ap)
{
	unsigned long int add = va_arg(ap, unsigned long int);
	ft_putchar('0');
	ft_putchar('x');
	ft_putnbr_hex(add, 'x');
	return (count_nbrx(add) + 2);
}

int count_nbr(int n)
{
	unsigned int i;

	i = 0;
	if (n < 0)
		i++;
	while(n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int count_nbrx(int n)
{
	unsigned int i;

	i = 0;
	while(n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}
