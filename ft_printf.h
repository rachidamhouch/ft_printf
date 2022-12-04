/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:42:28 by ramhouch          #+#    #+#             */
/*   Updated: 2022/10/21 16:04:47 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
int		ft_putnbr(int nb);
int		ft_putstr_fd(char *s, int fd);
int		ft_putchar_fd(char c, int fd);
int		printhex(unsigned int nb, int n);
int		print_ptr(void *ptr);
int		ft_putnbr(int nb);
int		ft_putunbr(unsigned int nb);
size_t	ft_strlen(const char *s);

#endif
