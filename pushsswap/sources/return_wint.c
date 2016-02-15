/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 14:25:08 by gseropia          #+#    #+#             */
/*   Updated: 2016/02/09 11:38:24 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			return_ccc(t_sdp *stock)
{
	int ret;

	ret = 0;
	stock->size--;
	if (stock->flagminus)
		while (stock->size-- > 0)
		{
			ft_putchar(' ');
			ret++;
		}
	return (ret);
}

int			return_cc(va_list ap, t_sdp *stock)
{
	wint_t	i;
	char	c;
	char	print;
	int		ret;

	i = 0;
	c = 0;
	ret = 0;
	print = ' ';
	i = va_arg(ap, wint_t);
	if (ft_strlen(ft_itoabase(i, 2)) < 8)
		c = i;
	if (stock->flagzero && !stock->flagminus)
	{
		print = '0';
		while (stock->size-- > 1 && ++ret)
			ft_putchar(print);
	}
	ret = ret + read_achar(i);
	ret = ret + return_ccc(stock);
	return (ret);
}
