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

int	formats(va_list ptr, char f)
{
	int	len;

	len = 0;
	if (f == 'c')
		len += ft_putchar_fd(va_arg(ptr, int), 1);
	else if (f == 's')
		len += ft_putstr_fd(va_arg(ptr, char *), 1);
	else if (f == 'p')
		len += print_ptr(va_arg(ptr, void *));
	else if (f == 'd' || f == 'i')
		len += ft_putnbr(va_arg(ptr, int));
	else if (f == 'u')
		len += ft_putunbr(va_arg(ptr, int));
	else if (f == 'x')
		len += printhex(va_arg(ptr, unsigned int), 0);
	else if (f == 'X')
		len += printhex(va_arg(ptr, unsigned int), 1);
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
			len += formats(ptr, str[i + 1]);
			i++;
		}
		else
			len += write(1, str + i, 1);
		i++;
	}
	va_end(ptr);
	return (len);
}
