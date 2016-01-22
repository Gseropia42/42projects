/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 11:49:23 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/22 15:08:09 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "libftprintf.h"
//int ft_printf(const char *format, ...);


int main()
{
/*	int d;
	int e;
	void *f;

	q
	q*/
	 ft_printf("%jx\n", 4294967296);
//	e = printf("%jx\n", 4294967296);
//	ft_putnbr(d);
//	ft_putchar('\n');
//	ft_putnbr(e);
	
//	void *f;
//	unsigned int d = 1488526296;
	ft_putchar('\n');
//	d =	printf("o%.2..s", "t");
	ft_printf("m%.2..s", "t");
	ft_printf("m%5%\n");
//	d = printf("o%5%\n");
	ft_putchar('\n');
//	ft_putnbr(d);
	ft_putchar('\n');
//	ft_putnbr(e);
	ft_putchar('\n');
//	printf("%#lx\n" , d);
//	printf("%p\n" , f);
/*
	printf("Le mot est :%ld\n", 555555555555555555555);
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
