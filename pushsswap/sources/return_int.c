/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 11:53:05 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/28 04:36:44 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	lastcheck(char *s, int nbr, t_sdp *stock)
{
	char	temp[1];
	char	d;

	d = '0';
	temp[0] = '\0';
	if (!stock->prec_size && stock->precision && !nbr)
		s = temp;
	if (stock->precision)
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

int	checkrelou(char *s, int nbr, t_sdp *stock)
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
	return (lastcheck(s, nbr, stock));
}

int	easyflags(char *s, int nbr, t_sdp *stock)
{
	char	temp[1];
	char 	d;
	
	d = ' ';
	temp[0] = '\0';
	if (!stock->prec_size && stock->precision && !nbr)
		s = temp;
	if (stock->flagspace && !stock->flagplus && nbr >= 0)
	{
		stock->string = ft_freejoin(stock, ft_strsub(&d, 0, 1));
		if (stock->size)
			stock->size--;
	}
	if (stock->flagplus && nbr >= 0 && stock->size > 0)
		stock->size--;
	if (stock->size > 0 && !stock->flagminus && stock->precision)
		while (stock->size > ft_strlen(s)
				&& stock->size-- > (stock->prec_size))
			stock->string = ft_freejoin(stock, ft_strsub(&d, 0, 1));
	if (stock->size > 0 && !stock->flagminus && !stock->precision)
		while (stock->size > 0 && !stock->flagzero &&
				stock->size-- > (ft_strlen(s)))
			stock->string = ft_freejoin(stock, ft_strsub(&d, 0, 1));
	return (checkrelou(s, nbr, stock));
}

int	return_i(va_list ap, t_sdp *stock)
{
	int			test;

	if (stock->flaglonglong == 1 || stock->sizze)
		return (return_longlongi(ap, stock));
	if (stock->flagmax == 1)
		return (return_maxi(ap, stock));
	if (stock->flaglong == 1)
		return (return_longi(ap, stock));
	test = va_arg(ap, int);
	while (stock->flagshort && test > 32767)
		test = test - 32768 - 32768;
	if (stock->flagchar)
	{
		if (test < -128)
			while (test < -128)
				test = test + 256;
		else if (test > 127)
			while (test > 127)
				test = test - 256;
	}
	if (test < 0)
		stock->prec_size++;
	return (easyflags(ft_itoa(test), test, stock));
}
