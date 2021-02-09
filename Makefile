# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adidion <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 11:17:06 by adidion           #+#    #+#              #
#    Updated: 2021/02/09 12:51:19 by adidion          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS =	ft_conv_c.c \
		ft_conv_d.c \
		ft_conv_p.c \
		ft_conv_s.c \
		ft_conv_u.c \
		ft_conv_x.c \
		ft_printf.c \
		ft_printf_flags_1.c \
		ft_printf_flags_2.c \
		ft_printf_utils_1.c \
		ft_printf_utils_2.c \
		ft_printf_utils_3.c \
		ft_printf_utils_4.c \

OBJS = $(SRCS:.c=.o)

LINK = ar rc

all : $(NAME)

$(NAME):	$(OBJS)
	$(LINK) $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(OB)

fclean: clean
	rm -f $(NAME) $(OB)

re: fclean all

.PHONY: re bonus clean fclean all
