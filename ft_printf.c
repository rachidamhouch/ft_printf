/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 23:01:27 by ramhouch          #+#    #+#             */
/*   Updated: 2022/10/21 16:03:43 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printu(unsigned long nb, int n, int p, unsigned long base)
{
	char						t;
	char						*ptr;
	unsigned long				z;
	int							len;

	len = 0;
	ptr = "0123456789abcdef";
	if (p)
		len += write(1, "0x", 2);
	if (n)
		ptr = "0123456789ABCDEF";
	z = 1;
	while (nb / z >= base)
		z *= base;
	while (z > 0)
	{
		t = ptr[((nb / z) % base)];
		len += write(1, &t, 1);
		z /= base;
	}
	return (len);
}

int	putstr(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[len])
		write(1, s + len++, 1);
	return (len);
}

int	ft_putnbr(int nb)
{
	long	nbr;
	int		len;

	nbr = nb;
	len = 0;
	if (nbr < 0)
	{
		len += write(1, "-", 1);
		nbr *= -1;
	}
	len += printu(nbr, 0, 0, 10);
	return (len);
}

int	formats(va_list ptr, char f)
{
	int		len;
	char	a;

	len = 0;
	if (f == 'c')
	{
		a = va_arg(ptr, int);
		len += write(1, &a, 1);
	}
	else if (f == 's')
		len += putstr(va_arg(ptr, char *));
	else if (f == 'p')
		len += printu((unsigned long )va_arg(ptr, void *), 0, 1, 16);
	else if (f == 'd' || f == 'i')
		len += ft_putnbr(va_arg(ptr, int));
	else if (f == 'u')
		len += printu((unsigned int)va_arg(ptr, int), 0, 0, 10);
	else if (f == 'x')
		len += printu(va_arg(ptr, unsigned int), 0, 0, 16);
	else if (f == 'X')
		len += printu(va_arg(ptr, unsigned int), 1, 0, 16);
	else if (f == '%')
		len += write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	ptr;
	int		len;

	i = 0;
	len = 0;
	va_start(ptr, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!str[i + 1])
				break ;
			len += formats(ptr, str[i++ + 1]);
			i++;
		}
		else
			len += write(1, str + i++, 1);
	}
	va_end(ptr);
	return (len);
}
