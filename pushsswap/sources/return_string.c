/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 14:40:01 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/28 04:11:46 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	return_s_spaceflag(t_sdp *stock, long long tai)
{
	char d;

	d = ' ';
	if (stock->precision && stock->prec_size < tai)
		while (stock->size-- > stock->prec_size)
			stock->string = ft_freejoin(stock, ft_strsub(&d, 0, 1));
	else
		while (stock->size-- > tai)
		{
			d = ' ';
			stock->string = ft_freejoin(stock, ft_strsub(&d, 0, 1));
		}
	return (1);
}

int	return_s_minusflag(t_sdp *stock)
{
	char d;

	d = ' ';
	while (stock->size-- > 0)
		stock->string = ft_freejoin(stock, ft_strsub(&d, 0, 1));
	return (1);
}

int	return_text(char *string, t_sdp *stock)
{
	int ret;

	ret = 0;
	if (stock->precision)
		while (stock->prec_size-- > 0 && *string)
		{
			stock->string = ft_freejoin(stock, ft_strsub(string++, 0, 1));
			stock->size--;
		}
	else
	{
		if (string)
		{
			stock->string = ft_freejoin(stock, string);
			ret = ft_strlen(string);
		}
		else
		{
			stock->string = ft_freejoin(stock, "(null)");
			ret = 6;
		}
		stock->size = stock->size - ret;
	}
	return (1);
}

int	return_s_zeroflag(t_sdp *stock, long long tai)
{
	char d;

	d = '0';
	if (stock->precision && stock->prec_size < tai)
		while (stock->size > 0 && stock->size-- > stock->prec_size)
			stock->string = ft_freejoin(stock, ft_strsub(&d, 0, 1));
	else
		while (stock->size > 0 && stock->size-- > tai)
			stock->string = ft_freejoin(stock, ft_strsub(&d, 0, 1));
	return (1);
}

int	return_s(va_list ap, t_sdp *stock)
{
	char	*s;
	size_t	t;

	t = 0;
	s = NULL;
	if (stock->flaglong || stock->fonction == 'S')
		return (return_long_s(ap, stock));
	if ((s = va_arg(ap, char*)))
		t = ft_strlen(s);
	else if (stock->precision == 0)
		t = 6;
	if (stock->flagzero && !stock->flagminus && stock->size)
		return (return_s_zeroflag(stock, t) + return_text(s, stock));
	if (stock->flagminus && stock->size)
		return (return_text(s, stock) + return_s_minusflag(stock));
	if (stock->size)
		return (return_s_spaceflag(stock, t) + return_text(s, stock));
	else
		return (return_text(s, stock));
	return (0);
}
