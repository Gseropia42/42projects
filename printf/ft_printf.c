/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 12:20:32 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/12 17:42:27 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int return_string(va_list ap)
{
	char *s;
	int i;

	ft_putstr(s = va_arg(ap, char*));
	i = ft_strlen(s);
	return (i);
}

int return_base(va_list ap, int base, int check, int maj)
{
	char *nbr;
	if (maj == 0)
		nbr = ft_itoabase(va_arg(ap, int), base);
	if (maj == 1)
		nbr = ft_itoabase_max(va_arg(ap, int), base);
	if (nbr[0] == '0' && check == 1)
	{
		nbr++;
		ft_putstr(nbr);
		return(ft_strlen(nbr) - 1);
	}
	ft_putstr(nbr);
	return(ft_strlen(nbr));
}

int check_my_format(const char* apply, va_list ap)
{
	if (ft_is_a_flag(apply))
		return(return_flag(apply, ap));
	if (*apply == 'c')
		return(return_char(ap));
	else if(*apply == 's')
		return(return_string(ap));
	else if (*apply == 'd' || *apply == 'i')
		return(return_base(ap, 10, 0, 0));
	else if (*apply == 'o')
		return(return_base(ap, 8, 0, 0));
	else if (*apply == 'x')
		return(return_base(ap, 16, 0, 0));
	else if (*apply == 'X')
		return(return_base(ap, 16, 0, 1));
	else if (*apply == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return(0);
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
			format = move_to_next_ap(format, 1);
		}
	}
	va_end(ap);
	return (i);
}
