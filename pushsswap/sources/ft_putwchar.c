/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:29:11 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/27 18:27:54 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
/*
void	ft_putw(wchar_t c)
{
	c = 227;
	write(1, &c, 1);
}
*/
void	ft_putwchar(wchar_t *c)
{
	int i;

	i = 0;
	while (c)
		write(1, c++, sizeof(wchar_t));
}

int		ft_wcharlen(wchar_t *c)
{
	int i;

	i = sizeof(c);
	return (i);
}
