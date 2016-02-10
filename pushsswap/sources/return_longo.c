/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 15:22:41 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/27 19:46:51 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	lastcheck_long_base(char *s, unsigned long nbr, t_sdp *stock)
{
	char	temp[1];

	temp[0] = '\0';
	if (!stock->prec_size && stock->precision && !nbr)
		s = temp;
	temp[0] = '0';
	if (stock->precision)
		while (stock->prec_size > 0 && stock->prec_size-- > ft_strlen(s))
		{
			stock->string = ft_freejoin(stock, ft_strsub(&temp[0], 0, 1));
			if (stock->size > 0)
				stock->size--;
		}
	stock->string = ft_freejoin(stock, s);
	stock->size = stock->size - ft_strlen(s);
	temp[0] = ' ';
	if (stock->flagminus && stock->size)
		while (stock->size-- > 0)
			stock->string = ft_freejoin(stock, ft_strsub(&temp[0], 0, 1));
	return (1);
}

int	check_l_diese(t_sdp *st, unsigned long nbr)
{
	char d;

	d = '0';
	if (!nbr && st->fonction != 'p')
		return (0);
	st->string = ft_freejoin(st, ft_strsub(&d, 0, 1));
	d = 'x';
	if (st->fonction == 'x' || st->fonction == 'p')
		st->string = ft_freejoin(st, ft_strsub(&d, 0, 1));
	d = 'X';
	if (st->fonction == 'X')
		st->string = ft_freejoin(st, ft_strsub(&d, 0, 1));
	if (st->fonction == 'X' || st->fonction == 'x' || st->fonction == 'p')
		return (2);
	return (1);
}

int	checkrelou_long_base(char *s, unsigned long nbr, t_sdp *stock)
{
	char	d;
	int		ret;

	ret = 0;
	d = '0';
	if (stock->flagdiese)
		ret = check_l_diese(stock, nbr);
	if (stock->flagzero && !stock->precision && stock->size > 0 \
			&& !stock->flagminus)
		while (stock->size > 0 && stock->size-- > ft_strlen(s))
			stock->string = ft_freejoin(stock, ft_strsub(&d, 0, 1));
	return (lastcheck_long_base(s, nbr, stock));
}

int	easyflags_long_base(char *s, unsigned long nbr, t_sdp *stock)
{
	char d;

	d = ' ';
	if ((long long)stock->size < 0)
		stock->size = 0;
	if (stock->size && !stock->flagminus && !stock->flagzero)
	{
		if (stock->precision && stock->prec_size > ft_strlen(s))
			while (stock->size > 0 && stock->size-- > (stock->prec_size))
				stock->string = ft_freejoin(stock, ft_strsub(&d, 0, 1));
		else
			while (stock->size > 0 && stock->size-- > ft_strlen(s))
				stock->string = ft_freejoin(stock, ft_strsub(&d, 0, 1));
	}
	return (checkrelou_long_base(s, nbr, stock));
}

int	long_base(va_list ap, t_sdp *stock, unsigned int base, int maj)
{
	unsigned long		nbr;
	char				*s;

	nbr = va_arg(ap, unsigned long);
	if (stock->fonction == 'p')
		stock->flagdiese = 1;
	if (maj == 0)
		s = ft_longbase(nbr, base);
	else
		s = ft_itoabase_long_max(nbr, base);
	if (stock->flagdiese && (stock->fonction == 'x' ||
				stock->fonction == 'X' || stock->fonction == 'p'))
		stock->size = stock->size - 2;
	else if (stock->flagdiese && \
		(stock->fonction == 'o' || stock->fonction == 'O'))
		stock->size = stock->size - 1;
	return (easyflags_long_base(s, nbr, stock));
}
