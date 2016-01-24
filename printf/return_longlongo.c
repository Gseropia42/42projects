/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 15:22:41 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/24 20:13:26 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	lastcheck_long_long_base(char *s, unsigned long long nbr, t_sdp *stock)
{
	int 	ret;
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

int	check_l_l_diese(t_sdp *stock, unsigned long long nbr)
{
	if (!nbr && stock->fonction != 'p')
		return (0);
	write(1, "0", 1);
	if (stock->fonction == 'x' || stock->fonction == 'p')
		write(1, "x", 1);
	if (stock->fonction == 'X')
		write(1, "X", 1);
	if (stock->fonction == 'X' || stock->fonction == 'x' || stock->fonction == 'p')
		return (2);
	return (1);
}

int	checkrelou_long_long_base(char *s, unsigned long long nbr, t_sdp *stock)
{
	int ret;

	ret = 0;
	if (stock->flagdiese)
		ret = check_l_l_diese(stock, nbr);
	if (stock->flagzero && !stock->precision && stock->size > 0 \
			&& !stock->flagminus)
	{
		while (stock->size-- > ft_strlen(s))
		{
			write(1, "0", 1);
			ret++;
		}
	}
	return (ret + lastcheck_long_long_base(s, nbr, stock));
}

int	easyflags_long_long_base(char *s, unsigned long long nbr, t_sdp *stock)
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
	return (ret + checkrelou_long_long_base(s, nbr, stock));
}

int	return_llong_base(va_list ap, t_sdp *stock, unsigned int base, int maj)
{
	unsigned long long	nbr;
	char				*s;

	nbr = va_arg(ap, unsigned long long);
	if (stock->fonction == 'p')
		stock->flagdiese = 1;
	if (maj == 0)
		s = ft_longlongbase(nbr, base);
	else
		s = ft_itoabase_long_long_max(nbr, base);
	if (stock->flagdiese && (stock->fonction == 'x' ||
				stock->fonction == 'X' || stock->fonction == 'p'))
		stock->size = stock->size - 2;
	else if (stock->flagdiese && \
		(stock->fonction == 'o' || stock->fonction == 'O'))
		stock->size = stock->size - 1;
	return (easyflags_long_long_base(s, nbr, stock));
}
