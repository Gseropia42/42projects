/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 17:09:35 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/12 17:57:56 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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

int check_diese(const char *format, va_list ap)
{
	if (!test_du_zero(ap) == 1)
		return(check_my_format(format, ap));
	while (ft_is_a_flag(format))
		format++;
	if (*format == 'o')
	{
		write(1, "0", 1);
		return(1 + return_base(ap, 8, 1, 0));
	}
	else if (*format == 'X')
	{
		write(1, "0X", 2);
		return(2 + return_base(ap, 16, 1, 1));
	}
	else if (*format == 'x')
	{
		write(1, "0x", 2);
		return(2 + return_base(ap, 16, 1, 0));
	}
	return(check_my_format(format, ap));
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
