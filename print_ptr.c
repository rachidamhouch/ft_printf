/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:07:33 by ramhouch          #+#    #+#             */
/*   Updated: 2022/10/21 16:07:35 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printhexh(unsigned long nb, int n)
{
	char						t;
	char						*ptr;
	unsigned long				z;
	int							len;

	if (n)
		ptr = "0123456789ABCDEF";
	else
		ptr = "0123456789abcdef";
	len = 0;
	z = 1;
	while (nb / z >= 16)
		z *= 16;
	while (z > 0)
	{
		t = ptr[((nb / z) % 16)];
		len += write(1, &t, 1);
		z /= 16;
	}
	return (len);
}

int	print_ptr(void *ptr)
{
	unsigned long	n;
	int				len;

	len = 0;
	len += write(1, "0x", 2);
	n = (unsigned long)ptr;
	len += printhexh(n, 0);
	return (len);
}
