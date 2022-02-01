int	is_string(char c, int *counter, va_list ap)
{
	int count;

	count = 0;
	if(c == 'c')
	   count += ft_putchar(va_arg(ap, int));
	else if(c == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if(c == 'd' || c == 'i')
		ft_putnbr(va_arg(ap, int), 10);
		//count +=
	else if(c == 'u')
		ft_putnbr_unsigned_int(va_arg(ap, unsigned int));
	else if(c == 'X' || c == 'x')
		ft_putnbr_hex(va_arg(ap, unsigned long long int), c);
	if(c == '%')
		count += ft_putchar('%');
	else
		count = 0;
	*counter += 2;
	return (count);


}
