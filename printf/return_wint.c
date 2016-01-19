/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 14:25:08 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/19 16:33:41 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int return_C(va_list ap , sdp_list *stock)
{
	char c;
	wint_t i;
	char print;
	int ret;

	ret = 0;
	print = ' ';
	if (stock->fonction == '%')
		c = '%';
	else
	{
		i = va_arg(ap, wint_t);
		c = i;
	}
	if (stock->flagzero && !stock->flagminus)
	{
		print = '0';
		while (stock->size-- > 1)
		{
			ft_putchar(print);
			ret++;
		}
	}
	ft_putchar((char)c);
	stock->size--;
	if (stock->flagminus)
		while (stock->size-- > 0)
		{
			ft_putchar(' ');
			ret++;
		}
	return (ret + 1);
}
