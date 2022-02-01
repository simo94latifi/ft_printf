#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
int		ft_printf(const char *, ...);
#include <string.h>
int	ft_putchar(char c);
int count_nbr(int n);
void	ft_putnbr(int n);
int	ft_putstr(char *str);
int	get_digits(int n);
void	ft_putnbr_unsigned_int(unsigned int n);
int count_nbrx(int n);
int ft_putptrnbr(va_list ap);

int	is_string(char c, int *counter, va_list ap);
#endif
