#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tisergue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/11 11:37:26 by tisergue          #+#    #+#              #
#    Updated: 2016/01/14 13:41:49 by gseropia         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=		libftprintf.a

SRCS		=		*.c libft/*.c

OBJS		=		$(SRCS:.c=.o)

FLAGS		=		-Wall -Werror -Wextra

MAKE 		=		make -C libft

CC			=		gcc

RM			=		rm -rf

all			:		$(NAME)

$(NAME)		:	
					@$(MAKE)
					@$(CC) -c $(SRCS)
					@ar rc $(NAME) $(OBJS)
					@ranlib $(NAME)
					@echo "\033[33;32m=== Compilation (ft_printf)\tDONE"

clean		:
					@$(RM) $(OBJS)
					@make clean -C libft/
					@echo "\033[33;32m=== Clean (ft_printf)\t\tDONE"

fclean		:		clean
					@$(RM) $(NAME)
					@make fclean -C libft/
					@echo "\033[33;32m=== Fclean (ft_printf)\t\tDONE"

re			:		fclean all
