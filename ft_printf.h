#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
int		ft_printf(const char *, ...);

int	ft_putchar(char c);
void	ft_putnbr(int n, int base);
int	ft_putstr(char *str);
int	get_digits(int n);
void	ft_putnbr_unsigned_int(unsigned int n);

int	is_string(char c, int *counter, va_list ap);
#endif
