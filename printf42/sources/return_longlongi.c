/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 11:53:05 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/26 20:16:15 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	lllastcheck(char *s, t_sdp *stock, long long nbr)
{
	int		ret;
	char	temp[1];

	temp[0] = '\0';
	ret = 0;
	if (!stock->prec_size && stock->precision && !nbr)
		s = temp;
	if (stock->precision)
		while (stock->prec_size-- > ft_strlen(s))
		{
			write(1, "0", 1);
			ret++;
			if (stock->size > 0)
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

int	llcheckrelou(char *s, long long nbr, t_sdp *stock)
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
	return (ret + lllastcheck(s, stock, nbr));
}

int	lleasyflags(char *s, long long nbr, t_sdp *stock)
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
	if (stock->size > 0)
		stock->size--;
	return (ret + llcheckrelou(s, nbr, stock));
}

int	return_longlongi(va_list ap, t_sdp *stock)
{
	char		*s;
	long long	test;
	int			ret;

	ret = 0;
	test = va_arg(ap, long long);
	s = ft_longlongitoa(test);
	ret = 0;
	ret = lleasyflags(s, test, stock);
	return (ret);
}
