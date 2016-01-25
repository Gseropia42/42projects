/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 15:22:41 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/25 19:04:09 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	lastcheck_base(char *s, int nbr, t_sdp *stock)
{
	int		ret;
	char	temp[1];

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

int	check_diese(t_sdp *stock, int nbr)
{
	if (stock->fonction == 'o' || stock->fonction == 'O')
	{	
		if (stock->precision && stock->prec_size)
			return (0);
		write(1, "0", 1);
		if (!nbr)
		{
			stock->flagdiese = -1;
			return(1);
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

int	checkrelou_base(char *s, int nbr, t_sdp *stock)
{
	int ret;

	ret = 0;
	if (stock->flagdiese)
		ret = check_diese(stock, nbr);
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

int	easyflags_base(char *s, int nbr, t_sdp *stock)
{
	int ret;
	char	temp[1];

	temp[0] = '\0';
	ret = 0;
	if (!stock->prec_size && stock->precision && !nbr)
			s = temp;
	if (stock->size && !stock->flagminus && !stock->flagzero)
	{
		if (stock->precision && stock->prec_size > ft_strlen(s))
			while (stock->size-- > (stock->prec_size))
			{
				ret++;
				write(1, " ", 1);
			}
		else
			while (stock->size > 0 && stock->size-- > ft_strlen(s))
			{
				ret++;
				write(1, " ", 1);
			}
	}
	return (ret + checkrelou_base(s, nbr, stock));
}

int	return_base(va_list ap, t_sdp *stock, int base, int maj)
{
	unsigned	int nbr;
	char			*s;
	
	if (stock->flaglonglong || stock->sizze)
		return (return_llong_base(ap, stock, base, maj));
	if (stock->flaglong || stock->fonction == 'O')
		return (return_long_base(ap, stock, base, maj));
	if (stock->flagmax)
		return (return_maxbase(ap, stock, base, maj));
	nbr = va_arg(ap, unsigned int);
	while (stock->flagshort && nbr > 65535)
		nbr = nbr - 65536;
	while (stock->flagchar && (nbr > 255))
		nbr = nbr + 256;
	if (maj == 0)
		s = ft_itoabaseprintf(nbr, base);
	else
		s = ft_itoabase_max(nbr, base);
	if (stock->flagdiese && (stock->fonction == 'x' || stock->fonction == 'X'))
		stock->size = stock->size - 2;
	else if (stock->flagdiese && (stock->fonction == 'o' || stock->fonction == 'O'))
		stock->size = stock->size - 1;
	return (easyflags_base(s, nbr, stock));
}
