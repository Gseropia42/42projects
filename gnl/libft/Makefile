# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gseropia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 11:48:48 by gseropia          #+#    #+#              #
#    Updated: 2016/01/09 17:39:02 by gseropia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isascii.c ft_isalpha.c ft_isdigit.c \
      ft_isprint.c ft_memalloc.c ft_memcpy.c ft_lstnew.c ft_memchr.c ft_itoa.c \
	  ft_memdel.c ft_memccpy.c ft_memcmp.c ft_putchar.c ft_memmove.c \
	  ft_putchar_fd.c ft_memset.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
	  ft_putstr_fd.c ft_putstr.c ft_putnbr_fd.c ft_strclr.c ft_strchr.c \
	  ft_strcat.c ft_strdel.c ft_strcmp.c ft_strcpy.c ft_strdup.c ft_striter.c \
	  ft_strequ.c ft_striteri.c ft_strlen.c ft_strjoin.c ft_strlcat.c \
	  ft_strmap.c ft_strmapi.c ft_strncmp.c ft_strncat.c ft_strncpy.c \
	  ft_strnew.c ft_strnequ.c ft_strnstr.c ft_strrchr.c ft_strstr.c \
	  ft_strsub.c ft_tolower.c ft_toupper.c ft_strtrim.c ft_strsplit.c \
	  ft_lstnew.c ft_lstadd.c ft_lstiter.c ft_specialsplit.c ft_return_pos.c \
	  ft_itoabase.c

all : $(NAME)

OBJ = $(SRC:.c=.o)

$(NAME) :
	gcc $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
