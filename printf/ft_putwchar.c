/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:29:11 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/25 14:11:19 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putw(wchar_t c)
{
	c = 227;
	write(1, &c, 1);
}

void	ft_putwchar(wchar_t *c)
{
	int i;

	i = 0;
	while (c[i] != '\0')
		write(1, &c[i++], 1);
}

int		ft_wcharlen(wchar_t *c)
{
	int i;

	i = 0;
	while (*c++)
		i++;
	return (i);
}


