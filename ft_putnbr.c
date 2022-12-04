/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:24:26 by ramhouch          #+#    #+#             */
/*   Updated: 2022/10/14 22:33:06 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	char	t;
	long	nbr;
	int		z;
	int		len;

	nbr = nb;
	len = 0;
	if (nbr < 0)
	{
		len += write(1, "-", 1);
		nbr *= -1;
	}
	z = 1;
	while (nbr / z >= 10)
		z *= 10;
	while (z > 0)
	{
		t = ((nbr / z) % 10) + '0';
		len += write(1, &t, 1);
		z /= 10;
	}
	return (len);
}
