/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 14:25:08 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/25 15:22:51 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	return_ccc(char c, t_sdp *stock)
{
	int ret;

	ret = 0;
	ft_putchar((char)c);
	stock->size--;
	if (stock->flagminus)
		while (stock->size-- > 0)
		{
			ft_putchar(' ');
			ret++;
		}
	return (ret);
}
static int valid_int(wint_t i)
{
	if (i > 255)
		return(1);
	return (0);
}

int		return_cc(va_list ap, t_sdp *stock)
{
	char	c;
	wint_t	i;
	char	print;
	int		ret;

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
		while (stock->size-- > 1)
		{
			ft_putchar(print);
			ret++;
		}
	}
	ret = ret + return_ccc(c, stock);
	return (ret + 1);
}
