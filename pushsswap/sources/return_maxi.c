/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 11:53:05 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/28 03:51:37 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	maxlastcheck(char *s, intmax_t nbr, t_sdp *stock)
{
	char	temp[1];
	char	d;

	d = '0';
	temp[0] = '\0';
	if (!stock->prec_size && stock->precision && !nbr)
		s = temp;
	else if (stock->precision)
		while (stock->prec_size-- > ft_strlen(s) && stock->prec_size > 0)
		{
			stock->string = ft_freejoin(stock, ft_strsub(&d, 0, 1));
			if (stock->size > 0)
				stock->size--;
		}
	stock->string = ft_freejoin(stock, s);
	stock->size = stock->size - ft_strlen(s);
	if (stock->flagminus && stock->size > 0)
		while (stock->size-- > 0)
		{
			d = ' ';
			stock->string = ft_freejoin(stock, ft_strsub(&d, 0, 1));
		}
	return (1);
}

int	maxcheckrelou(char *s, intmax_t nbr, t_sdp *stock)
{
	char	d;

	d = '+';
	if (stock->flagplus && nbr >= 0)
		stock->string = ft_freejoin(stock, ft_strsub(&d, 0, 1));
	if (nbr < 0)
	{
		stock->string = ft_freejoin(stock, ft_strsub(s++, 0, 1));
		if (stock->size > 0)
			stock->size--;
		if (stock->prec_size > 0)
			stock->prec_size--;
	}
	if (stock->flagzero && stock->size > 0 && !stock->flagminus)
	{
		while (!stock->precision && stock->size-- > ft_strlen(s))
		{
			d = '0';
			stock->string = ft_freejoin(stock, ft_strsub(&d, 0, 1));
			if (stock->prec_size > 0)
				stock->prec_size--;
		}
	}
	return (maxlastcheck(s, nbr, stock));
}

int	maxeasyflags(char *s, intmax_t nbr, t_sdp *stock)
{
	char	temp[1];

	temp[0] = '\0';
	if (!stock->prec_size && stock->precision && !nbr)
		s = temp;
	temp[0] = ' ';
	if (stock->flagspace && !stock->flagplus && nbr >= 0)
	{
		stock->string = ft_freejoin(stock, ft_strsub(&temp[0], 0, 1));
		if (stock->size)
			stock->size--;
	}
	if (stock->flagplus && nbr >= 0 && stock->size > 0)
		stock->size--;
	if (stock->size > 0 && !stock->flagminus && stock->precision)
		while (stock->size > ft_strlen(s)
				&& stock->size-- > (stock->prec_size))
			stock->string = ft_freejoin(stock, ft_strsub(&temp[0], 0, 1));
	if (stock->size > 0 && !stock->flagminus && !stock->precision)
		while (stock->size > 0 && !stock->flagzero &&
				stock->size-- > (ft_strlen(s)))
			stock->string = ft_freejoin(stock, ft_strsub(&temp[0], 0, 1));
	return (maxcheckrelou(s, nbr, stock));
}

int	return_maxi(va_list ap, t_sdp *stock)
{
	intmax_t		test;

	test = va_arg(ap, intmax_t);
	return (maxeasyflags(ft_maxtoa(test), test, stock));
}
