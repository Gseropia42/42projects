/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 14:40:01 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/21 19:23:47 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	return_s_spaceflag(char *string, t_sdp *stock)
{
	int ret;

	ret = 0;
	if (stock->precision && stock->prec_size < ft_strlen(string))
	{
		while (stock->size-- > stock->prec_size)
		{
			write(1, " ", 1);
			ret++;
		}
	}
	else
	{
		while (stock->size-- > ft_strlen(string))
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

int	return_text(char *string, t_sdp *stock)
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
		ft_putstr(string);
		ret = ft_strlen(string);
		stock->size = stock->size - ret;
	}
	return (ret);
}

int	return_s_zeroflag(char *string, t_sdp *stock)
{
	int ret;

	ret = 0;
	if (stock->precision && stock->prec_size < ft_strlen(string))
	{
		while (stock->size-- > stock->prec_size)
		{
			write(1, "0", 1);
			ret++;
		}
	}
	else
	{
		while (stock->size-- > ft_strlen(string))
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

	s = va_arg(ap, char*);
	if (s == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	if (stock->flagzero && !stock->flagminus && stock->size)
		return (return_s_zeroflag(s, stock) + return_text(s, stock));
	if (stock->flagminus && stock->size)
		return (return_text(s, stock) + return_s_minusflag(s, stock));
	if (stock->size)
		return (return_s_spaceflag(s, stock) + return_text(s, stock));
	else
		return (return_text(s, stock));
	return (0);
}
