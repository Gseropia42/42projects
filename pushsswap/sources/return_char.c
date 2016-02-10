/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 14:25:08 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/28 04:10:12 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	return_cs(char c, t_sdp *stock)
{
	char d;

	d = ' ';
	stock->string = ft_freejoin(stock, ft_strsub(&c, 0, 1));
	stock->size--;
	if (stock->flagminus)
		while (stock->size-- > 0)
			ft_freejoin(stock, ft_strsub(&d, 0, 1));
	return (1);
}

int	return_c(va_list ap, t_sdp *stock)
{
	char	c;
	int		i;
	char	print;
	int		ret;

	ret = 0;
	print = ' ';
//	if (stock->flaglong == 1)
//		return (return_cc(ap, stock));
	if (stock->fonction == 'c')
	{
		i = va_arg(ap, int);
		c = i;
	}
	else
		c = stock->fonction;
	if (c == 0)
		stock->lol++;
	if (stock->flagzero && !stock->flagminus)
		print = '0';
	while (stock->size > 1 && !stock->flagminus)
	{
		stock->size--;
		stock->string = ft_freejoin(stock, ft_strsub(&print, 0, 1));
	}
	return (ret + return_cs(c, stock));
}
