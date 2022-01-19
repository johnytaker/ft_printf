# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/24 14:54:18 by iugolin           #+#    #+#              #
#    Updated: 2021/12/24 15:20:14 by iugolin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
HEADER = ft_printf.h
RM = @rm -f
SRCS =		ft_strlen.c     \
			ft_itoa.c       \
			ft_putchar_fd.c \
			ft_putstr_fd.c  \
			ft_putnbr_fd.c  \
			ft_printf.c     \
			ft_printf_utils.c \
			ft_printf_utils_2.c \
			ft_uitoa_base.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(NAME): $(OBJS) $(HEADER)
	ar -rcs $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
