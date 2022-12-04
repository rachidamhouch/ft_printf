# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/08 15:29:04 by ramhouch          #+#    #+#              #
#    Updated: 2022/10/16 23:17:48 by ramhouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
SRC = ft_putnbr.c ft_putunbr.c print_ptr.c ft_printf.c ft_putchar_fd.c ft_putstr_fd.c print_hex.c ft_strlen.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)
fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: clean all fclean re 
