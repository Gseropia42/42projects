/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 11:49:23 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/17 18:15:52 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "libftprintf.h"
//int ft_printf(const char *format, ...);


int main()
{
	int d, e;

	d= ft_printf("Le mot est :% 0+ -12 .12o  %s\n", 55, "PAULO");
	e = printf("Le met est :% 0 +-12 .12o  %s\n", 55, "PAULO");
	ft_putnbr(d);
	ft_putchar('\n');
	ft_putnbr(e);
	ft_putchar('\n');
/*
	printf("Le mot est :%o\n", 55);
	printf("Le mot est :%#o\n", 55);
	printf("Le mot est :%  o\n", 55);
	printf("Le mot est :%12 -o\n", 55);
	printf("Le mot est :%12 +o\n", 55);
	printf("Le mot est :%12  0o\n", 55);
	printf("Le mot est :%12 #0o\n", 55);
	printf("Le mot est :%.12  #o\n", 55);
	printf("Le mot est :%.12 16o\n", 55);
	printf("Le mot est :%#.6  12 x\n", 55);
	printf("Le mot est :%o\n", 55);
*/	return (0);
}
