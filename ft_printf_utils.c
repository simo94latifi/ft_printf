#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n, int base)
{
	if (n == -2147483648 && base == 10)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648, base);
	}
	else if (n < 0 && base == 10)
	{
		ft_putchar('-');
		ft_putnbr(-n, base);
	}
	else if (n < base)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr(n / base, base);
		ft_putnbr(n % base, base);
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
	if (sign == 'u')
		i = "0123456789ABCDEF";
	else if (sign == 'l')
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


void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while(str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}
