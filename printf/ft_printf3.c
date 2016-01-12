/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 13:57:08 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/12 13:12:03 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_is_a_flag(const char *format)
{
	char *s;
	s = ft_strnew(9);
	s = "#0-+ i.hljz";
	while (*s)
	{
		if (*format == *s++)
			return (1);
	}
//	free(s);
	return (0);
}

int check_space(const char *format, va_list ap)
{
	while (ft_is_a_flag(format))
	{
		if (*format == '#')
			return(check_diese(++format, ap));
		format++;
		//if (*format
	}
	if (*format == 'i' || *format == 'd')
	{
		write(1, " ", 1);
		return(1 + check_my_format(format , ap));
	}
	return(check_my_format(format, ap));
}
