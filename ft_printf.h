#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
void	ft_putchar(char c);
void	ft_putnbr(int n, int base);
void	ft_putstr(char *str);
void	ft_putnbr_unsigned_int(unsigned int n);
void	ft_putnbr_hex(unsigned long long int n, char sign);
int		ft_printf(const char *, ...);
#endif
