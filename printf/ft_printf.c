/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 12:20:32 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/09 18:23:47 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
/*int ft_its_spaaaaace(const char *format)
{
	int i = 0;
	if ((*format + 1) > 47 && (*format + 1) < 58)
		i = (10 * i) + ft_atoi(*format++);
	while (i-- > 0)
		write(1, " ", 1);
	return(i);
}*/


int check_my_format(const char* apply, va_list ap)
{
	int i;
	char *s;
	int nbr;

	s = NULL;
	i = 0;
	char *c[] = "int";
/*	if (*apply < 58 && *apply > 47)
	{
	 i = ft_its_spaaaaace(*apply);

	}*/
	if(*apply == 's')
	{
		ft_putstr(s = va_arg(ap, char*));
		i = ft_strlen(s);
	}
	else if (*apply == 'd')
	{
		ft_putnbr(nbr = (va_arg(ap, *c)));
		while (nbr > 9)
		{
			nbr = nbr / 10;
			i++;
		}
	}
	else if(*apply == '%')
	{
		write(1, "%", 1);
		i++;
	}
	apply++;
	return (i);
}

int ft_printf(const char *format, ...)
{
	va_list ap;
	int i;
    
	i = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format++, 1);
			i++;
		}
		else
		{
			i =	i + check_my_format(++format,ap);
			format++;
		}
	}
	va_end(ap);
	return (i);
}
