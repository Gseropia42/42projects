/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 14:40:01 by gseropia          #+#    #+#             */
/*   Updated: 2016/02/09 11:37:55 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	return_l_s_spaceflag(t_sdp *stock, long long taille)
{
	int ret;

	ret = 0;
	if (stock->precision && stock->prec_size < taille)
	{
		while (stock->size-- > stock->prec_size)
		{
			write(1, " ", 1);
			ret++;
		}
	}
	else
	{
		while (stock->size-- > taille)
		{
			write(1, " ", 1);
			ret++;
		}
	}
	return (ret);
}

int	return_l_s_minusflag(t_sdp *stock)
{
	int ret;

	ret = 0;
	while (stock->size-- > 0)
	{
		write(1, " ", 1);
		ret++;
	}
	return (ret);
}

int	return_l_text(wchar_t *string, t_sdp *stock)
{
	int ret;

	ret = 0;
	if (stock->precision)
	{
		ret = read_wchar(string);
		stock->size = stock->size - ret;
	}
	else
	{
		if (!string)
		{
			ft_putstr("(null)");
			ret = 6;
		}
		else
			ret = read_wchar(string);
		stock->size = stock->size - ret;
	}
	return (ret);
}

int	return_l_s_zeroflag(t_sdp *stock, long long taille)
{
	int ret;

	ret = 0;
	if (stock->precision && stock->prec_size < taille)
	{
		while (stock->size-- > stock->prec_size)
		{
			write(1, "0", 1);
			ret++;
		}
	}
	else
	{
		while (stock->size-- > taille)
		{
			write(1, "0", 1);
			ret++;
		}
	}
	return (ret);
}

int	return_long_s(va_list ap, t_sdp *stock)
{
	wchar_t	*s;
	size_t	t;
	wchar_t	*temp;

	t = 0;
	if ((s = va_arg(ap, wchar_t *)))
	{
		temp = s;
		while (*temp++)
			t++;
	}
	else if (stock->precision == 0)
		t = 6;
	if (stock->flagzero && !stock->flagminus && stock->size)
		return (return_l_s_zeroflag(stock, t) + return_l_text(s, stock));
	if (stock->flagminus && stock->size)
		return (return_l_text(s, stock) + return_l_s_minusflag(stock));
	if (stock->size)
		return (return_l_s_spaceflag(stock, t) + return_l_text(s, stock));
	else
		return (return_l_text(s, stock));
	return (0);
}
