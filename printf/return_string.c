/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 14:40:01 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/25 14:44:14 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	return_s_spaceflag(char *string, t_sdp *stock, int tai)
{
	int ret;

	ret = 0;
	if (stock->precision && stock->prec_size < tai)
	{
		while (stock->size-- > stock->prec_size)
		{
			write(1, " ", 1);
			ret++;
		}
	}
	else
	{
		while (stock->size-- > tai)
		{
			write(1, " ", 1);
			ret++;
		}
	}
	return (ret);
}

int	return_s_minusflag(char *string, t_sdp *stock)
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

int	return_text(char *string, t_sdp *stock, int tai)
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
		if (string)
		{
			ft_putstr(string);
			ret = tai;
		}
		else
		{
			ft_putstr("(null)");
			ret = 6;
		}
		stock->size = stock->size - ret;
	}
	return (ret);
}

int	return_s_zeroflag(char *string, t_sdp *stock, int tai)
{
	int ret;

	ret = 0;
	if (stock->precision && stock->prec_size < tai)
	{
		while (stock->size > 0 && stock->size-- > stock->prec_size)
		{
			write(1, "0", 1);
			ret++;
		}
	}
	else
	{
		while (stock->size > 0 && stock->size-- > tai)
		{
			write(1, "0", 1);
			ret++;
		}
	}
	return (ret);
}

int	return_s(va_list ap, t_sdp *stock)
{
	char *s;
	int t;

	t = 0;
	s = NULL;
	if (stock->flaglong || stock->fonction == 'S')
		return(return_long_s(ap ,stock));
	if ((s = va_arg(ap, char*)))
		t = ft_strlen(s);
	else if (stock->precision == 0)
		t = 6;
	if (stock->flagzero && !stock->flagminus && stock->size)
		return (return_s_zeroflag(s, stock, t) + return_text(s, stock, t));
	if (stock->flagminus && stock->size)
		return (return_text(s, stock, t) + return_s_minusflag(s, stock));
	if (stock->size)
		return (return_s_spaceflag(s, stock, t) + return_text(s, stock, t));
	else
		return (return_text(s, stock, t));
	return (0);
}
