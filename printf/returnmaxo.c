/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 15:22:41 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/21 19:24:50 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	lastcheck_max_base(char *s, uintmax_t nbr, t_sdp *stock)
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

int	check_max_diese(t_sdp *stock)
{
	write(1, "0", 1);
	if (stock->fonction == 'x')
		write(1, "x", 1);
	if (stock->fonction == 'X')
		write(1, "X", 1);
	if (stock->fonction == 'X' || stock->fonction == 'x')
		return (2);
	return (1);
}

int	checkrelou_max_base(char *s, uintmax_t nbr, t_sdp *stock)
{
	int ret;

	ret = 0;
	if (stock->flagdiese && nbr)
	{
		ret = check_max_diese(stock);
		stock->size = stock->size - ret;
	}
	if (stock->flagzero && !stock->precision && stock->size > 0 \
			&& !stock->flagminus)
	{
		while (stock->size-- > ft_strlen(s))
		{
			write(1, "0", 1);
			ret++;
		}
	}
	return (ret + lastcheck_max_base(s, nbr, stock));
}

int	easyflags_max_base(char *s, uintmax_t nbr, t_sdp *stock)
{
	int ret;

	ret = 0;
	if (stock->size && !stock->flagminus && !stock->flagzero)
	{
		if (stock->precision && stock->prec_size > ft_strlen(s))
			while (stock->size-- > (stock->prec_size))
			{
				ret++;
				write(1, " ", 1);
			}
		else
			while (stock->size-- > ft_strlen(s))
			{
				ret++;
				write(1, " ", 1);
			}
	}
	return (ret + checkrelou_max_base(s, nbr, stock));
}

int	return_maxbase(va_list ap, t_sdp *stock, unsigned int base, int maj)
{
	unsigned long	nbr;
	char			*s;

	nbr = va_arg(ap, uintmax_t);
	if (maj == 0)
		s = ft_longbase(nbr, base);
	else
		s = ft_itoabase_long_max(nbr, base);
	if (stock->flagdiese && (stock->fonction == 'x' || stock->fonction == 'X'))
		stock->size = stock->size - 2;
	else if (stock->flagdiese &&
		(stock->fonction == 'o' || stock->fonction == 'O'))
		stock->size = stock->size - 1;
	return (easyflags_max_base(s, nbr, stock));
}
