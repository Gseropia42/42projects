/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 11:49:23 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/25 19:03:36 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "libftprintf.h"
int ft_printf(const char *format, ...);


int main()
{
	int d = 65536;
	int e;
//	wchar_t lol[12] = L"!!!!!!!!!!!";
//	e =printf("printf =%hhu, %hhu\n", -55, UCHAR_MAX + 42);
//	d = ft_printf("lemien =%hhu, %hhu\n", -55, UCHAR_MAX + 42);
//	e =printf("printf ==%.4S\n", L"ÊM-^HM-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B" );
//	d = ft_printf("lemien ==%.4S\n",L"ÊM-^HM-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B" );
//	e = printf("printf =%o, %ho, %hho\n", -42, -42,-42);
//	d = ft_printf("lemien =%o, %ho, %hho\n", -42, -42, -42);
/*	e = printf("le  printf = %hd\n", 63000);
	e = printf("le  printf = %hd\n", 1270);
	e = printf("le  printf = %hd\n", 32767);
	e = printf("le  printf = %hd\n", 25500);
	e = printf("le  printf = %hd\n", 32);
	e = printf("le  printf = %hd\n", 368);
	e = printf("le  printf = %hd\n", 45);
	e = printf("le  printf = %hd\n", 1);
	e = printf("le  printf = %hd\n", 0);
*///	e = printf("le  printf = %hd\n", 2);
//	d = ft_printf("M%hhd - %hhd\n", SHRT_MAX - 42, SHRT_MAX - 4200);
//	e =printf("O%hhd - %hhd\n", SHRT_MAX - 42, SHRT_MAX - 4200);
	e =printf("o%#.o\n", 42);
	d =ft_printf("m%#.o\n", 42);
	printf("mon retour : %d, retourprintf : %d\n", d , e);
	return (0);
}
