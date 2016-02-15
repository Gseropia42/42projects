/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 15:22:41 by gseropia          #+#    #+#             */
/*   Updated: 2016/02/09 11:38:58 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	lastcheck_base(char *s, int nbr, t_sdp *st)
{
	int		ret;
	char	temp[1];

	temp[0] = '\0';
	ret = 0;
	if (((!st->prec_size && st->precision) || st->flagdiese == -1)
			&& !nbr)
		s = temp;
	if (st->precision)
		while (st->prec_size > 0 && st->prec_size-- > ft_strlen(s))
		{
			write(1, "0", 1);
			ret++;
			if (st->size > 0)
				st->size--;
		}
	ft_putstr(s);
	st->size = st->size - ft_strlen(s);
	if (st->flagminus && st->size)
		while (st->size && st->size-- > 0)
		{
			write(1, " ", 1);
			ret++;
		}
	return (ret + ft_strlen(s));
}

int	check_diese(t_sdp *st, int nbr)
{
	if (st->fonction == 'o' || st->fonction == 'O')
	{
		if (st->precision && st->prec_size)
			return (0);
		write(1, "0", 1);
		if (!nbr)
		{
			st->flagdiese = -1;
			return (1);
		}
	}
	if (!nbr)
		return (0);
	if (st->fonction == 'x')
		write(1, "0x", 2);
	if (st->fonction == 'X')
		write(1, "0X", 2);
	if (st->fonction == 'X' || st->fonction == 'x')
		return (2);
	return (1);
}

int	checkrelou_base(char *s, int nbr, t_sdp *st)
{
	int ret;

	ret = 0;
	if (st->flagdiese)
		ret = check_diese(st, nbr);
	if (st->flagzero && !st->precision && st->size > 0 \
			&& !st->flagminus)
	{
		while (st->size && st->size-- > ft_strlen(s))
		{
			write(1, "0", 1);
			ret++;
		}
	}
	return (ret + lastcheck_base(s, nbr, st));
}

int	easyflags_base(char *s, int nbr, t_sdp *st)
{
	int		ret;
	char	temp[1];

	temp[0] = '\0';
	ret = 0;
	if (!st->prec_size && st->precision && !nbr)
		s = temp;
	if (st->size && !st->flagminus && !st->flagzero)
	{
		if (st->precision && st->prec_size > ft_strlen(s))
			while (st->size > 0 && st->size-- > (st->prec_size))
			{
				ret++;
				write(1, " ", 1);
			}
		else
			while (st->size > 0 && st->size-- > ft_strlen(s))
			{
				ret++;
				write(1, " ", 1);
			}
	}
	return (ret + checkrelou_base(s, nbr, st));
}

int	return_base(va_list ap, t_sdp *st, int base, int maj)
{
	unsigned int	nbr;
	char			*s;

	if (st->fonction == 'b')
		base = 2;
	if (st->flaglonglong || st->sizze || st->fonction == 'p')
		return (llong_base(ap, st, base, maj));
	if (st->flaglong || st->fonction == 'O')
		return (long_base(ap, st, base, maj));
	if (st->flagmax)
		return (maxbase(ap, st, base, maj));
	nbr = va_arg(ap, unsigned int);
	while (st->flagshort && nbr > 65535)
		nbr = nbr - 65536;
	while (st->flagchar && (nbr > 255))
		nbr = nbr + 256;
	if (maj == 0)
		s = ft_itoabaseprintf(nbr, base);
	else
		s = ft_itoabase_max(nbr, base);
	if (st->flagdiese && (st->fonction == 'x' || st->fonction == 'X'))
		st->size = st->size - 2;
	else if (st->flagdiese && (st->fonction == 'o' || st->fonction == 'O'))
		st->size = st->size - 1;
	return (easyflags_base(s, nbr, st));
}
