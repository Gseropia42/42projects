/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 11:49:23 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/08 16:55:03 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_printf(const char *format, ...);
int main()
{
	int d = 0;
	{
		d = printf("Le mot est : %s %s \n", "Jean Paul", "est un con");
		ft_printf("Le mot est : %s %s \n", "Jean Paul", "est un con");
		ft_putnbr(d);
	}
		return (0);
}
