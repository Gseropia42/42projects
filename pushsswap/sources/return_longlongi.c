/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 11:53:05 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/27 19:45:10 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	lllastcheck(char *s, t_sdp *stock, long long nbr)
{
	char	temp[1];

	temp[0] = '\0';
	if (!stock->prec_size && stock->precision && !nbr)
		s = temp;
	temp[0] = '0';
	if (stock->precision)
		while (stock->prec_size-- > ft_strlen(s))
		{
			stock->string = ft_freejoin(stock, ft_strsub(&temp[0], 0, 1));
			if (stock->size > 0)
				stock->size--;
		}
	stock->string = ft_freejoin(stock, s);
	temp[0] = ' ';
	stock->size = stock->size - ft_strlen(s);
	if (stock->flagminus && stock->size)
		while (stock->size-- > 0)
			stock->string = ft_freejoin(stock, ft_strsub(&temp[0], 0, 1));
	return (1);
}

int	llcheckrelou(char *s, long long nbr, t_sdp *stock)
{
	char d;

	d = '+';
	if (stock->flagplus && nbr > 0)
		stock->string = ft_freejoin(stock, ft_strsub(&d, 0, 1));
	d = ' ';
	if (stock->flagspace && !stock->flagplus && nbr > 0)
		stock->string = ft_freejoin(stock, ft_strsub(&d, 0, 1));
	d = '0';
	if (stock->flagzero && !stock->precision && stock->size > 0
			&& !stock->flagminus)
		while (stock->size-- > ft_strlen(s))
			stock->string = ft_freejoin(stock, ft_strsub(&d, 0, 1));
	return (lllastcheck(s, stock, nbr));
}

int	lleasyflags(char *s, long long nbr, t_sdp *stock)
{
	char d;

	d = ' ';
	if (stock->size && !stock->flagminus)
	{
		if (stock->precision)
			while (stock->size-- > (stock->prec_size + 1))
				stock->string = ft_freejoin(stock, ft_strsub(&d, 0, 1));
		else
			while (stock->size-- > (ft_strlen(ft_itoa(nbr)) + 1))
				stock->string = ft_freejoin(stock, ft_strsub(&d, 0, 1));
	}
	if (stock->size > 0)
		stock->size--;
	return (llcheckrelou(s, nbr, stock));
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
