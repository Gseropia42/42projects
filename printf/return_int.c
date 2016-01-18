/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 11:53:05 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/17 18:30:03 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int lastcheck(char *s, int nbr, sdp_list *stock)
{
	int ret;

	ret = 0;

	if (stock->precision)
		while (stock->prec_size-- > ft_strlen(s))
		{
			write(1, "0", 1);
			ret++;
			stock->size--;
		}
	ft_putstr(s);
	stock->size = stock->size - ft_strlen(s);
	if (stock->flagminus && stock->size)
		while(stock->size-- > 0)
		{
			write(1, " ", 1);
			ret++;
		}
	return (ret + ft_strlen(s));
}

int checkrelou(char *s, int nbr, sdp_list *stock)
{
	int ret;

	ret = 0;
	if (stock->flagplus && nbr > 0)
	{
		write(1, "+", 1);
		ret++;
	}
	if (stock->flagspace && !stock->flagplus && nbr > 0)
	{
		write(1, " ", 1);
		ret++;
	}
	if (stock->flagzero && !stock->precision && stock->size > 0 && !stock->flagminus)		
	{
		while (stock->size-- >  ft_strlen(s))
		{
			write(1 ,"0", 1);
			ret++;
		}
	}
	return (ret + lastcheck(s, nbr,stock));
}

int easyflags(char *s,int nbr, sdp_list *stock)
{
	int ret;

	ret = 0;
	if (stock->size && !stock->flagminus)
	{
		if (stock->precision)
			while (stock->size-- > (stock->prec_size + 1))
			{
				ret++;
				write(1, " ", 1);
			}
		else
			while (stock->size-- > (ft_strlen(ft_itoa(nbr)) + 1))
			{
				ret++;
				write(1, " ", 1);
			}
	}
	stock->size--;
	return (ret + checkrelou(s, nbr, stock));
}


int	return_i(va_list ap, sdp_list *stock)
{
	char *s;
	int test;
	int ret;

	ret = 0;
	test = va_arg(ap, int);
	s = ft_itoa(test);
	ret = 0;
	ret = easyflags(s, test, stock);
	return (ret);
}

