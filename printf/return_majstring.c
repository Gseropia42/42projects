/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 14:40:01 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/23 11:11:07 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	return_l_s_spaceflag(wchar_t *string, t_sdp *stock, int taille)
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

int	return_l_s_minusflag(wchar_t *string, t_sdp *stock)
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
		while (stock->prec_size-- > 0 && *string)
		{
			write(1, string++, 1);
			ret++;
			stock->size--;
		}
	}
	else
	{
		while (*string)
		{
			write(1, string++, 1);
			ret++;
		}
		stock->size = stock->size - ret;
	}
	return (ret);
}

int	return_l_s_zeroflag(wchar_t *string, t_sdp *stock, int taille)
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
	int		t;
	wchar_t	*temp;

	t = 0;
	s = va_arg(ap, wchar_t *);
	temp = s;
	while (*temp++)
		t++;
	if (s == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	if (stock->flagzero && !stock->flagminus && stock->size)
		return (return_l_s_zeroflag(s, stock, t) + return_l_text(s, stock));
	if (stock->flagminus && stock->size)
		return (return_l_text(s, stock) + return_l_s_minusflag(s, stock));
	if (stock->size)
		return (return_l_s_spaceflag(s, stock, t) + return_l_text(s, stock));
	else
		return (return_l_text(s, stock));
	return (0);
}
