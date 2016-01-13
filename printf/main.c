/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 11:49:23 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/13 17:19:03 by gseropia         ###   ########.fr       */
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
	{
		d = printf("Le mot est : %# d,% o,%u,%s,%%,lol\n",55,666, 345799, "Paul");
		ft_putnbr(d);
		ft_putchar('\n');
		e = ft_printf("Le mot est : %# d,% o,%u,%s,%%,lol\n",55,666, 345799, "Paul");

		ft_putnbr(e);
	}
		return (0);
}
