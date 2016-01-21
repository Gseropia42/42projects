/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 11:53:05 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/21 19:22:17 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	maxlastcheck(char *s, t_sdp *stock)
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
		while (stock->size-- > 0)
		{
			write(1, " ", 1);
			ret++;
		}
	return (ret + ft_strlen(s));
}

int	maxcheckrelou(char *s, intmax_t nbr, t_sdp *stock)
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
	if (stock->flagzero && !stock->precision && stock->size > 0
			&& !stock->flagminus)
	{
		while (stock->size-- > ft_strlen(s))
		{
			write(1, "0", 1);
			ret++;
		}
	}
	return (ret + maxlastcheck(s, stock));
}

int	maxeasyflags(char *s, intmax_t nbr, t_sdp *stock)
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
	return (ret + maxcheckrelou(s, nbr, stock));
}

int	return_maxi(va_list ap, t_sdp *stock)
{
	char		*s;
	intmax_t	test;
	int			ret;

	ret = 0;
	test = va_arg(ap, intmax_t);
	s = ft_itoa(test);
	ret = 0;
	ret = maxeasyflags(s, test, stock);
	return (ret);
}
