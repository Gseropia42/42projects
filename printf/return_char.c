/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 14:25:08 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/21 20:57:05 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	return_cs(char c, t_sdp *stock)
{
	int ret;

	ret = 1;
	ft_putchar(c);
	stock->size--;
	if (stock->flagminus)
		while (stock->size-- > 0)
		{
			ft_putchar(' ');
			ret++;
		}
	return (ret);
}

int	return_c(va_list ap, t_sdp *stock)
{
	char	c;
	int		i;
	char	print;
	int		ret;

	ret = 0;
	print = ' ';
	if (stock->flaglong == 1)
		return (return_cc(ap, stock));
	if (stock->fonction == '%')
		c = '%';
	else
	{
		i = va_arg(ap, int);
		c = i;
	}
	if (stock->flagzero && !stock->flagminus)
		print = '0';
	while (stock->size > 1 && !stock->flagminus)
	{
		stock->size--;
		ft_putchar(print);
		ret++;
	}
	return (ret + return_cs(c, stock));
}
