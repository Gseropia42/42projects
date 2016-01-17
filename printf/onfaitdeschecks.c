/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onfaitdeschecks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 13:32:56 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/17 14:24:23 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char *move_format(char *format)
{
	if (*format == '+' || *format == '-' || *format == ' ' || *format == '#' || *format == '0')
		return (++format);
	if (ft_isdigit(*format))
	{
		while (ft_isdigit(*format))
			format++;
		return (format);
	}
	if (*format == '.')
	{
		format++;
		while (ft_isdigit(*format))
			format++;
		return (format);
	}
	return (format);
}
int affichage(va_list ap, sdp_list *stock)
{
	if (stock->fonction == 's')
		return(return_s(ap, stock));
	if (stock->fonction == 'd' || stock->fonction == 'i')
		return(return_i(ap, stock));
	if (stock->fonction == 'c')
		return(return_c(ap, stock));
	return(0);
}
int	check_format(char *format, va_list ap, sdp_list *stock)
{
	while (*format != stock->fonction)
	{
		if (ft_isdigit(*format) && *format != '0')
			stock->size = ft_atoi(format);
		else if (*format == '+')
			stock->flagplus = 1;
		else if (*format == '#')
			stock->flagdiese = 1;
		else if (*format == ' ')
			stock->flagspace = 1;
		else if (*format == '0')
			stock->flagzero = 1;
		else if (*format == '.')
		{
			stock->precision = 1;
			stock->prec_size = ft_atoi(++format);
		}
		else if (*format == '-')
			stock->flagminus = 1;
		format = move_format(format);
	}
	return(affichage(ap,stock));
}
