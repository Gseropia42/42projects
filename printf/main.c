/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 11:49:23 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/17 14:36:21 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "libftprintf.h"
//int ft_printf(const char *format, ...);


int main()
{
	int d, e;

	d= ft_printf("Le mot est :% 0+ -12 .12c  %s\n", 55, "PAULO");
	e = printf("Le met est :% 0 +-12 .12c  %s\n", 55, "PAULO");
	ft_putnbr(d);
	ft_putchar('\n');
	ft_putnbr(e);
	ft_putchar('\n');
/*
	ft_putnbr(printf("Le mot est :%c\n", 55));
	ft_putnbr(printf("Le mot est :%15c\n", 55));
	ft_putnbr(printf("Le mot est :%015c\n", 55));
	ft_putnbr(printf("Le mot est :%-15c\n", 55));
	ft_putnbr(printf("Le mot est :%.0c\n", 55));
	ft_putnbr(printf("Le mot est :%.c\n", 55));
	ft_putnbr(printf("Le mot est :%#  c\n", 55));
	ft_putnbr(printf("Le mot est :%   +   c\n", 55));
	ft_putnbr(printf("Le mot est :%c\n", 55));
	ft_putnbr(printf("Le mot est :%c\n", 55));
*/	return (0);
}
