/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 11:49:23 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/13 21:57:15 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../gnl/libft/libft.h"
#include "libftprintf.h"
int ft_printf(const char *format, ...);


int main()
{
	int e = 0;
	int d = 0;
	/*
		d = printf("Le mot est : %# d,% o,% u,%s,% %,lol\n",55,666, 345799, "Paul");
		ft_putnbr(d);
		ft_putchar('\n');
	e = ft_printf("Le mot est : %# d,% o,% u,%s,% %,lol\n",55,666, 345799, "Paul");

		ft_putnbr(e);
	*/
	d = ft_printf("le faux = %s %d %D %i %o %o %d %d %d %X %c %012d %#x %#o % 12d\n", "salut", 42, 42, 42, 42, 42, 42, 42, 15, 15, 'a', 42, 42, 42, 42);
	printf(" = %d\n", d);
	e = printf("le vrai = %s %d %D %i %o %o %d %d %d %X %c %012d %#x %#o % 12d\n", "salut", 42, 42, 42, 42, 42, 42, 42, 15, 15, 'a', 42, 42, 42, 42);
	printf(" = %d\n", e);
		return (0);
}
