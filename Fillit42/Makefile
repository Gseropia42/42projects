#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tisergue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/18 14:07:55 by tisergue          #+#    #+#              #
#    Updated: 2015/12/18 14:07:59 by tisergue         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= 	fillit

SRCS	=	filltest.c ft_fillit1.c onvabrulerlamairie.c resolver.c

ICD		=	libfill.h

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -rf

all		:	$(NAME)

$(NAME)	:	
			$(CC) $(CFLAGS) -c $(SRCS)
			$(CC) -o $(NAME) $(SRCS)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all