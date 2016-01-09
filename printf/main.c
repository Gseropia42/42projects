/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 11:49:23 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/09 18:22:06 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../gnl/libft/libft.h"
int ft_printf(const char *format, ...);
int main()
{
	int *lol;
	int e = 0;
	int d = 0;
	lol = &d;
	{
		d = printf("Le mot est : %s %9s %8o \n", "Jean Paul", "lol" , 55);
		e = ft_printf("Le mot est : %s %s %d \n", "Jean Paul", "est un con", 56);
	//	ft_putnbr(d);
		ft_putchar('\n');
		ft_putstr(ft_itoa(55));
		ft_putchar('\n');
		ft_putendl(ft_itoabase(9, 16));
		ft_putendl(ft_itoabase(17, 18));
		ft_putendl(ft_itoabase(11, 16));
		ft_putendl(ft_itoabase(12, 16));
		ft_putendl(ft_itoabase(13, 16));
		ft_putendl(ft_itoabase(14, 16));
		ft_putendl(ft_itoabase(35, 36));
		ft_putchar('\n');
	//	ft_putnbr(e);
	}
		return (0);
}
