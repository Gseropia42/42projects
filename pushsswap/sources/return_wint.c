/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 14:25:08 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/28 00:42:05 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			return_ccc(char c, t_sdp *stock)
{
	int ret;
	char d;

	d = '0';
	ret = 0;
	stock->string = ft_freejoin(stock, ft_strsub(&c, 0, 1));
	stock->size--;
	if (stock->flagminus)
		while (stock->size-- > 0)
		stock->string = ft_freejoin(stock, ft_strsub(&d, 0, 1));
	return (ret);
}

static int	valid_int(wint_t i)
{
	if (i > 255)
		return (1);
	return (0);
}

int			return_cc(va_list ap, t_sdp *stock)
{
	char	c;
	wint_t	i;
	char	print;
	int		ret;

	i = 0;
	ret = 0;
	print = ' ';
	if (stock->fonction == '%')
		c = '%';
	else
	{
		i = va_arg(ap, wint_t);
		c = i;
	}
	if (valid_int(i))
		return (-10);
	if (stock->flagzero && !stock->flagminus)
	{
		print = '0';
		while (stock->size-- > 1 && ++ret)
			stock->string = ft_freejoin(stock, ft_strsub(&print, 0, 1));
	}
	ret = ret + return_ccc(c, stock);
	return (ret + 1);
}
