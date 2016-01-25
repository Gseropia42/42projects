/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 15:22:41 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/25 12:18:02 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	lastcheck_long_base(char *s, unsigned long nbr, t_sdp *stock)
{
	int ret;
	char temp[1];

	temp[0] = '\0';
	ret = 0;
	if (((!stock->prec_size && stock->precision) || stock->flagdiese == -1) && !nbr)
		s = temp;
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

int	check_l_diese(t_sdp *stock, int nbr)
{
	if (stock->fonction == 'o' || stock->fonction == 'O')
	{
		write(1, "0", 1);
		if (!nbr)
		{
			stock->flagdiese = -1;
			return (1);
		}
	}
	if (!nbr)
		return (0);

	if (stock->fonction == 'x')
		write(1, "0x", 2);
	if (stock->fonction == 'X')
		write(1, "0X", 2);
	if (stock->fonction == 'X' || stock->fonction == 'x')
		return (2);
	return (1);
}

int	checkrelou_long_base(char *s, unsigned long nbr, t_sdp *stock)
{
	int ret;

	ret = 0;
	if (stock->flagdiese)
		ret = check_l_diese(stock, nbr);
	if (stock->flagzero && !stock->precision && stock->size > 0 \
			&& !stock->flagminus)
	{
		while (stock->size-- > ft_strlen(s))
		{
			write(1, "0", 1);
			ret++;
		}
	}
	return (ret + lastcheck_long_base(s, nbr, stock));
}

int	easyflags_long_base(char *s, unsigned long nbr, t_sdp *stock)
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
			while (stock->size-- > ft_strlen(s) && stock->size > 0)
			{
				ret++;
				write(1, " ", 1);
			}
	}
	return (ret + checkrelou_long_base(s, nbr, stock));
}

int	return_long_base(va_list ap, t_sdp *stock, unsigned int base, int maj)
{
	unsigned long	nbr;
	char			*s;

	nbr = va_arg(ap, unsigned long);
	if (maj == 0)
		s = ft_longbase(nbr, base);
	else
		s = ft_itoabase_long_max(nbr, base);
	if (stock->flagdiese && (stock->fonction == 'x' || stock->fonction == 'X'))
		stock->size = stock->size - 2;
	else if (stock->flagdiese && \
		(stock->fonction == 'o' || stock->fonction == 'O'))
		stock->size = stock->size - 1;
	return (easyflags_long_base(s, nbr, stock));
}
