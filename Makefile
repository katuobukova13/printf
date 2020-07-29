# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qblinky <qblinky@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/20 21:12:33 by qblinky           #+#    #+#              #
#    Updated: 2020/07/29 23:10:09 by qblinky          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

LIBFT = ./libft
LIBA = libft.a

SRCS =	ft_printf.c \
		ft_parser.c \
		ft_print_output.c \
		ft_print_type.c \
		ft_print_c_s.c \
		ft_print_d_i.c \
		ft_print_u.c \
		ft_print_x_p.c \
		ft_print_percent.c

OBJECTS = $(SRCS:.c=.o)

HEADER = ft_printf.h

CFLAGS=	-Wall -Wextra -Werror

CC = gcc $(CFLAGS) -c

all: $(NAME)

$(NAME): $(OBJECTS)
	$(MAKE) -C $(LIBFT)
	cp $(LIBFT)/$(LIBA) $(NAME)
	$(CC) $(HEADER) $(SRCS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

%.o: %.c
	@$(CC) $< -o $@

clean:
	/bin/rm -f $(OBJECTS)
	make clean -C $(LIBFT)

fclean:     clean
	/bin/rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
