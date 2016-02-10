/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 15:22:41 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/28 04:36:52 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		lastcheck_base(char *s, int nbr, t_sdp *stock)
{
	char	temp[1];
	char	d;

	d = '0';
	temp[0] = '\0';
	if (!stock->prec_size && stock->precision && !nbr)
		s = temp;
	if (stock->precision)
		while (stock->prec_size > 0 && stock->prec_size-- > ft_strlen(s))
		{
			stock->string = ft_freejoin(stock, ft_strsub(&d, 0, 1));
			if (stock->size > 0)
				stock->size--;
		}
	stock->string = ft_freejoin(stock, s);
	stock->size = stock->size - ft_strlen(s);
	temp[0] = ' ';
	if (stock->flagminus && stock->size)
		while (stock->size-- > 0)
		{
			d = ' ';
			stock->string = ft_freejoin(stock, ft_strsub(&d, 0, 1));
		}
	return (1);
}

void	check_diese(t_sdp *st, int nbr)
{
	char d;

	d = '0';
	if (!nbr && st->fonction != 'p')
		return ;
	st->string = ft_freejoin(st, ft_strsub(&d, 0, 1));
	d = 'x';
	if (st->fonction == 'x' || st->fonction == 'p')
		st->string = ft_freejoin(st, ft_strsub(&d, 0, 1));
	d = 'X';
	if (st->fonction == 'X')
		st->string = ft_freejoin(st, ft_strsub(&d, 0, 1));
}

int		checkrelou_base(char *s, int nbr, t_sdp *stock)
{
	char d;

	d = '0';
	if (stock->flagdiese)
		check_diese(stock, nbr);
	if (stock->flagzero && !stock->precision && stock->size > 0 \
			&& !stock->flagminus)
		while (stock->size > 0 && stock->size-- > ft_strlen(s))
			stock->string = ft_freejoin(stock, ft_strsub(&d, 0, 1));
	return (lastcheck_base(s, nbr, stock));
}

int		easyflags_base(char *s, int nbr, t_sdp *stock)
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
	return (checkrelou_base(s, nbr, stock));
}

int		return_base(va_list ap, t_sdp *stock, int base, int maj)
{
	unsigned int		nbr;
	char				*s;

	if (stock->flaglonglong || stock->sizze || stock->fonction == 'p')
		return (llong_base(ap, stock, base, maj));
	if (stock->flaglong || stock->fonction == 'O')
		return (long_base(ap, stock, base, maj));
	if (stock->flagmax)
		return (maxbase(ap, stock, base, maj));
	nbr = va_arg(ap, unsigned int);
	while (stock->flagshort && nbr > 65535)
		nbr = nbr - 65536;
	while (stock->flagchar && (nbr > 255))
		nbr = nbr + 256;
	if (maj == 0)
		s = ft_itoabaseprintf(nbr, base);
	else
		s = ft_itoabase_max(nbr, base);
	if (nbr == 0 && stock->precision == 1 && stock->prec_size == 0 && stock->size > 0)
		stock->lol++;
	if (stock->flagdiese && (stock->fonction == 'x' ||
				stock->fonction == 'X'))
		stock->size = stock->size - 2;
	else if (stock->flagdiese &&
			(stock->fonction == 'o' || stock->fonction == 'O'))
		stock->size = stock->size - 1;
	return (easyflags_base(s, nbr, stock));
}
