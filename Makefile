# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sperez-s <sperez-s@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/21 17:42:35 by sperez-s          #+#    #+#              #
#    Updated: 2021/10/30 12:11:44 by sperez-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OBJS = $(SRC:.c=.o)

SRC =	ft_atoi.c		\
		ft_bzero.c		\
		ft_calloc.c		\
		ft_isalnum.c	\
		ft_isalpha.c	\
		ft_isascii.c	\
		ft_isdigit.c	\
		ft_isprint.c	\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_memcpy.c		\
		ft_memmove.c	\
		ft_memset.c		\
		ft_split.c		\
		ft_stdrup.c		\
		ft_strchr.c		\
		ft_strjoin.c	\
		ft_strlen.c		\
		ft_strncmp.c	\
		ft_strlcat.c	\
		ft_strlcpy.c	\
		ft_strncpy.c	\
		ft_strnstr.c	\
		ft_strrchr.c	\
		ft_strtrim.c	\
		ft_substr.c		\
		ft_tolower.c	\
		ft_toupper.c

HEADER = libft.h

CFLAGS = -Wextra -Wall -Werror

CC = gcc

$(NAME): $(OBJS) $(HEADER)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all


.PHONY: all clean fclean re





