/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onfaitdeschecks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 13:32:56 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/31 20:48:48 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*move_format(char *format)
{
	if ((*format == 'l' && *(format + 1) == 'l') ||
			(*format == 'h' && *(format + 1) == 'h'))
		return (format + 2);
	if (ft_isdigit(*format) && *format != '0')
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
	return (++format);
}

int		affichage(va_list ap, t_sdp *stock)
{
	if (stock->fonction == 'C')
		return (return_cc(ap, stock));
	if (stock->fonction == 'D')
		return (return_longi(ap, stock));
	if (stock->fonction == 's' || stock->fonction == 'S')
		return (return_s(ap, stock));
	if (stock->fonction == 'd' || stock->fonction == 'i')
		return (return_i(ap, stock));
	if (stock->fonction == 'c' || stock->fonction == '%')
		return (return_c(ap, stock));
	if (stock->fonction == 'o' || stock->fonction == 'O')
		return (return_base(ap, stock, 8, 0));
	if (stock->fonction == 'x' || stock->fonction == 'p')
		return (return_base(ap, stock, 16, 0));
	if (stock->fonction == 'X')
		return (return_base(ap, stock, 16, 1));
	if (stock->fonction == 'U')
		return (long_base(ap, stock, 10, 0));
	if (stock->fonction == 'u' || stock->fonction == 'b')
		return (return_base(ap, stock, 10, 0));
	if (stock->fonction == '\0')
		return (0);
	else
		return (return_c(ap, stock));
}

void	more_checks(char *format, t_sdp *stock)
{
	if (*format == 'h' && *(format + 1) == 'h')
		stock->flagchar = 1;
	else if (*format == 'l' && *(format + 1) == 'l')
		stock->flaglonglong = 1;
	else if (*format == 'h')
		stock->flagshort = 1;
	else if (*format == '.')
	{
		stock->precision = 1;
		stock->prec_size = ft_atoi(++format);
	}
	else if (*format == 'l')
		stock->flaglong = 1;
	else if (*format == 'j')
		stock->flagmax = 1;
	else if (*format == 'z')
		stock->sizze = 1;
	else if (*format == '0')
		stock->flagzero = 1;
}

int		valid_string(wchar_t *string)
{
	while (*string)
		if (*string++ > 127)
			return (1);
	return (0);
}

int		cf(char *format, va_list ap, t_sdp *stock)
{
	while (*format != stock->fonction)
	{
		if (ft_isdigit(*format) && *format != '0')
			stock->size = ft_atoi(format);
		else if (*format == '#')
			stock->flagdiese = 1;
		else if (*format == '+')
			stock->flagplus = 1;
		else if (*format == ' ')
			stock->flagspace = 1;
		else if (*format == '-')
			stock->flagminus = 1;
		else if (*format == 'h' || *format == 'l' || *format == '0' ||
				*format == 'z' || *format == 'j' || *format == '.')
			more_checks(format, stock);
		else
			return (-1);
		format = move_format(format);
	}
	if (stock->fonction == '%' && !gnt(format, 1))
		return (-1);
	return (affichage(ap, stock));
}
