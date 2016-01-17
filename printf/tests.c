/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 14:08:17 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/16 19:45:35 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int check_size(char *format, char fctn)
{
	int taille;

	taille = 0;
	while (*format != fctn)
	{
		if (ft_isdigit(*format) && *format != '0')
		{
			taille = ft_atoi(format);
			while (ft_isdigit(*format))
				format++;
		}
	}
	return (taille);
}

int search_prec(char *format, char c)
{
	if (ft_isdigit(*format))
		return(ft_atoi(format));
	return (-1);
}

int after_zero(char *format)
{
	while (!get_next_type(format))
	{
		if (ft_isdigit(*format) && *format != '0')
		{
			while (ft_isdigit(*format))
			{
				format++;
				return(format);
			}
			format++;
		}
	}
	return (format);
}

int search_zero(char *format, char c)
{
	while (*format != c)
	{
		if (ft_isdigit(*format) && *format != '0')
			return(ft_atoi(format));
		format++;
	}
	return (0);
}
int test_zero(va_list ap)
{
	va_list ap2;
	int i;

	va_copy(ap2, ap);
	i = va_arg(ap2, int);
	if (i == 0)
	{
		va_end(ap2);
		return(1);
	}
	va_end(ap2);
	return (0);
}
int	test_done(char *format, char c)
{
	while (*format != '%')
	{
		if (*format-- == c)
			return(1);
	}
	return (0);
}
