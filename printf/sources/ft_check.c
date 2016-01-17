/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 13:55:43 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/14 15:35:10 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_is_convert(char *format, int index)
{
	char *s;

	s = ft_strnew(15);
	s = "%sSpdDioOuUxXcC";
	while (*s)
	{
		if (format[index] == *s++)
			return (1);
	}
	return (0);
}

int ft_is_a_flag(const char *format)
{
	char *s;
	s = ft_strnew(10);
	s = "#0-+. hljz";
	while (*s)
	{
		if (*format == *s++)
			return (1);
	}
	return (0);
}

int test_du_zero(va_list ap)
{
	va_list ap2;
	va_copy(ap2, ap);
	if((va_arg(ap2, int)) == 0)
	{
		va_arg(ap, int);
		ft_putnbr(0);
		va_end(ap2);
		return(0);
	}
	va_end(ap2);
	return(1);
}
const char  *move_to_next_ap(const char *format, int check)
{
	char *s;
	int index;

	index = 0;
	s = ft_strnew(15);
	s = "sSpdDioOuUxXcC\%";
	while(*format)
	{
		while(index < 15)
		{
			if (*format == s[index++])
			{
				if (check == 1)
				{
					return(++format);
				}
				return(format);
			}
		}
		format++;
		index = 0;
	}
	return(format);
}
