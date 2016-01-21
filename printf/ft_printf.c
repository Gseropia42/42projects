/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 13:15:27 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/21 20:57:21 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		get_next_type(char *format)
{
	char *s;

	s = ft_strnew(15);
	s = "%sSdDpoOxXcCuUi";
	while (*s)
	{
		if (*s++ == *format)
			return (*format);
	}
	return ('\0');
}

char		gnt(char *format)
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
				return (*format);
		}
		s = temp;
		format++;
	}
	return ('\0');
}

t_sdp	*stocktoutca(t_sdp **list)
{
	t_sdp *stock;

	stock = malloc(sizeof(t_sdp));
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
			return (1);
	}
	return (0);
}

int			ft_printf(const char *format, ...)
{
	int			ret;
	int			temp;
	va_list		ap;
	char		fctn;
	t_sdp		*stock;

	va_start(ap, format);
	ret = 0;
	temp = ret;
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format++, 1);
			ret++;
		}
		else
		{
			temp = ret;
			stock = stocktoutca(&stock);
			if ((stock->fonction = gnt((char*)++format)))
			{
				ret = ret + check_format((char*)format, ap, stock);
				if (ret == temp - 1)
				{
					ret++;
					while (checkflagada(format) && *format)
						format++;
				}
				else
				{
					while (!get_next_type((char*)format) && *format)
						format++;
					format++;
				}
				if (*format == '\0')
					return (ret);
			}
			else
				while (checkflagada(format) && *format)
					format++;
			free(stock);
		}

	}
	va_end(ap);
	return (ret);
}
