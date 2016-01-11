#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tisergue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/11 11:37:26 by tisergue          #+#    #+#              #
#    Updated: 2016/01/11 12:29:41 by gseropia         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=		libftprintf.a

SRCS		=		ft_printf.c ft_printf2.c ft_printf3.c main.c

OBJS		=		$(SRCS:.c=.o)

FLAGS		=		-Wall -Werror -Wextra

MAKE 		=		make -C ../gnl/libft/

CC			=		gcc

RM			=		rm -rf

all			:		$(NAME)

$(NAME)		:	
					@$(MAKE)
					@$(CC) $(CFLAGS) -c $(SRCS)
					@ar rc $(NAME) $(OBJS)
					@ranlib $(NAME)
					@echo "\033[33;32m=== Compilation (ft_printf)\tDONE"

clean		:
					@$(RM) $(OBJS)
					@make clean -C ../gnl/libft/
					@echo "\033[33;32m=== Clean (ft_printf)\t\tDONE"

fclean		:		clean
					@$(RM) $(NAME)
					@make fclean -C ../gnl/libft/
					@echo "\033[33;32m=== Fclean (ft_printf)\t\tDONE"

re			:		fclean all
