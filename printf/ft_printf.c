/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 13:15:27 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/22 15:54:54 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		gnt(char *format, int check)
{
	char *s;
	char *temp;

	s = ft_strnew(15);
	s = "%sSdDpoOxXcCuUi";
	temp = s;
	while (*format)
	{
		while (*s)
		{
			if (*s++ == *format)
			{
				return (*format);
			}
		}
		if (check == 0)
			return ('\0');
		s = temp;
		format++;
	}
	return ('\0');
}

t_sdp		*stocktoutca(t_sdp **list, int ret)
{
	t_sdp *stock;

	stock = malloc(sizeof(t_sdp));
	stock->temp = ret;
	stock->fonction = 0;
	stock->flagminus = 0;
	stock->flagdiese = 0;
	stock->flagzero = 0;
	stock->flagplus = 0;
	stock->flagspace = 0;
	stock->precision = 0;
	stock->prec_size = 0;
	stock->size = 0;
	stock->flaglong = 0;
	stock->flaglonglong = 0;
	stock->flagmax = 0;
	stock->flagshort = 0;
	stock->flagchar = 0;
	stock->sizze = 0;
	*list = stock;
	return (stock);
}

int			checkflagada(const char *format)
{
	char *s;

	s = ft_strnew(19);
	s = "0123456789hljz-+.# ";
	while (*s)
	{
		if (*s++ == *format)
		{
			return (1);
		}
	}
	return (0);
}

int			callprint(const char *f, t_sdp *s, va_list ap, int ret)
{
	while (*f)
	{
		if (*f != '%' && ++ret)
			write(1, f++, 1);
		else
		{
			s = stocktoutca(&s, ret);
			if ((s->fonction = gnt((char*)++f, 1)))
				if ((ret = ret + cf((char*)f, ap, s)) == s->temp - 1 && ret++)
					while (checkflagada(f) && *f)
						f++;
				else
				{
					while (!gnt((char*)f, 0) && *f && *(f + 1))
						f++;
					f++;
				}
			else
				while (checkflagada(f) && *f)
					f++;
			free(s);
		}
	}
	return (ret);
}

int			ft_printf(const char *format, ...)
{
	int			ret;
	va_list		ap;
	t_sdp		*stock;

	va_start(ap, format);
	ret = 0;
	ret = callprint(format, stock, ap, ret);
	va_end(ap);
	return (ret);
}
