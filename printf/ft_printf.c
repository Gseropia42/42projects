/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 13:15:27 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/17 14:19:21 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


char	get_next_type(char *format)
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

char gnt(char *format)
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
sdp_list *stocktoutca(sdp_list **list)
{
	sdp_list *stock;
	stock = malloc(sizeof(sdp_list));
	stock->fonction = 'd';
	stock->flagminus = 0;
	stock->flagdiese = 0;
	stock->flagzero = 0;
	stock->flagplus = 0;
	stock->flagspace = 0;
	stock->precision = 0;
	stock->prec_size = 0;
	stock->size = 0;
	*list = stock;
	return(stock);
}

int		ft_printf(const char *format, ...)
{
	int			ret;
	va_list		ap;
	char		fctn;
	sdp_list	*stock;

	va_start(ap , format);
	ret = 0;
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format++, 1);
			ret++;
		}
		else
		{
			stock = stocktoutca(&stock);
			stock->fonction = gnt((char*)++format);
			if (!(stock->fonction))
				return (-1);
			ret = ret + check_format((char*)format, ap, stock);
			while (!get_next_type((char*)format))
				format++;
			format++;
		free(stock);
		}
	}
	va_end(ap);
	return (ret);
}
