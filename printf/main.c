/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 11:49:23 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/19 22:37:11 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "libftprintf.h"
//int ft_printf(const char *format, ...);


int main()
{
	int d;
	int e;

	d = ft_printf("%llx\n", 857438435943);
	e = printf("%llx\n", 857438435943);
	ft_putnbr(d);
	ft_putchar('\n');
	ft_putnbr(e);
	ft_putchar('\n');
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
