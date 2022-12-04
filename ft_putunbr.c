/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:32:21 by ramhouch          #+#    #+#             */
/*   Updated: 2022/10/14 22:35:07 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int nb)
{
	char			t;
	unsigned int	z;
	int				len;

	len = 0;
	z = 1;
	while (nb / z >= 10)
		z *= 10;
	while (z > 0)
	{
		t = ((nb / z) % 10) + '0';
		len += write(1, &t, 1);
		z /= 10;
	}
	return (len);
}
