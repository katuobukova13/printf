# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qblinky <qblinky@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/10 13:19:32 by qblinky           #+#    #+#              #
#    Updated: 2020/07/26 22:43:39 by qblinky          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = 	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c\
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strncmp.c \
		ft_strlcat.c \
		ft_strlcpy.c   \
		ft_strlen.c \
		ft_strmapi.c  \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c

BSRCS =	ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstnew.c \
		ft_lstsize.c \
		ft_lstmap.c

OBJECTS = $(SRCS:.c=.o)

BOBJECTS = $(BSRCS:.c=.o)

CFLAGS=	-Wall -Wextra -Werror

CC = gcc $(CFLAGS) -c

all: $(NAME)

$(NAME):
	@$(CC) $(SRCS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

bonus:
	@$(CC) $(BSRCS)
	@ar rc $(NAME) $(BOBJECTS)
	@ranlib $(NAME)

%.o: %.c
	@$(CC) $< -o $@

clean:
	@rm -f $(OBJECTS) $(BOBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
