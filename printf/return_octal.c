/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 15:22:41 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/18 13:50:13 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	lastcheck_base(char *s, int nbr, sdp_list *stock)
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

int	check_diese(sdp_list *stock)
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

int	checkrelou_base(char *s, int nbr, sdp_list *stock)
{
	int ret;

	ret = 0;
	if (stock->flagdiese && nbr)
	{
		ret = check_diese(stock);
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
	return (ret + lastcheck_base(s, nbr, stock));
}

int	easyflags_base(char *s, int nbr, sdp_list *stock)
{
	int ret;

	ret = 0;
	if (stock->size && !stock->flagminus)
	{
		if (stock->precision)
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
	return (ret + checkrelou_base(s, nbr, stock));
}

int	return_base(va_list ap, sdp_list *stock, int base, int maj)
{
	unsigned	int nbr;
	char			*s;

	nbr = va_arg(ap, unsigned int);
	if (maj == 0)
		s = ft_itoabaseprintf(nbr, base);
	else
		s = ft_itoabase_max(nbr, base);
	if (stock->flagdiese && (stock->fonction == 'x' || stock->fonction == 'X'))
		stock->size = stock->size - 2;
	else if (stock->flagdiese && \
		(stock->fonction == 'o' || stock->fonction == 'O'))
		stock->size = stock->size - 1;
	return (easyflags_base(s, nbr, stock));
}