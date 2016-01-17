/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 12:20:32 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/14 13:45:37 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int return_flags(const char *format, va_list ap)
{
	if (*format == '+')
		return(0);
	if (*format == ' ')
		return(check_space(++format, ap));
	if (*format == '#')
		return(check_diese(++format, ap));
	if (*format == '.')
		return(0);
	if (*format == '-')
		return(0);
	if (ft_isdigit(*format) && *format != '0')
		return(0);
	if (*format == '0')
		return(0);
	return(0);	
}
int check_other_formats(const char *format, va_list ap)
{
	if (*format == 'S')
		return (0);
	if (*format == 'U')
		return(return_unsigned_long(ap, 0));
	if (*format == 'u')
		return(return_unsigned(ap, 0));
	if (*format == 'D')
		return(return_long(ap, 0));
	if (*format == 'C')
		return(0);
	return(0);
}
int check_my_format(const char* format, va_list ap)
{
	if (ft_is_a_flag(format) || ft_isdigit(*format))
		return(return_flags(format, ap));
	if (*format == 'p')
		return(0);
	if (*format == 'c')
		return(return_char(ap));
	else if(*format == 's')
		return(return_string(ap));
	else if (*format == 'd' || *format == 'i')
		return(return_int(ap, 0));
	else if (*format == 'o')
		return(return_base(ap, 8, 0));
	else if (*format == 'x')
		return(return_base(ap, 16, 0));
	else if (*format == 'X')
		return(return_base_max(ap, 16, 0));
	else if (*format == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return(check_other_formats(format, ap));
}

int ft_printf(const char *format, ...)
{
	va_list ap;
	int i;
    char *temp;

	temp = NULL;
	i = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
			write(1, format++, 1);
		else
		{
			i =	i + check_my_format(++format,ap) - 1;
			while (!ft_is_convert(format))
				format++;
			format++;
		}
		i++;
	}
	va_end(ap);
	return (i);
}
