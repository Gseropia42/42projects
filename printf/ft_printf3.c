/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 13:57:08 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/12 17:57:59 by gseropia         ###   ########.fr       */
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
	return (0);
}

/*char ft_next_convert(const char *format)
{
	char *s;
	s = ft_strnew(13);
	s = "sSpdDiouUxXcC"
	while(*format)
*/
int return_flag(const char *apply, va_list ap)
{
	const char *temp;
	temp = NULL;
	if (*apply == '#')
		return(check_diese(++apply, ap));
	if (*apply == ' ')
		return(check_space(++apply, ap));
	if (*apply == '.')
	{
		temp  = move_to_next_ap(apply, 0);
	//	ft_putstr("YOLOLO");
		if (*temp == 's')
			return(check_precision(++apply, ap, 's'));
	}
	return (0);
}

int check_precision(const char *format, va_list ap, char conv)
{

	int i;
	int ret;
	char* stock;
	
	ret = 0;
	i = ft_atoi(format);
	if (conv == 's')
	{
		stock = (va_arg(ap, char*));
		while (i-- > 0 && *stock != '\0')
		{
			write(1, stock, 1);
			stock++;
			ret++;
		}
	}
	return (ret);
}

int check_space(const char *format, va_list ap)
{
	while (ft_is_a_flag(format))
	{
		if (*format == '#')
			return(check_diese(++format, ap));
		format++;
	}
	if (*format == 'i' || *format == 'd')
	{
		write(1, " ", 1);
		return(1 + check_my_format(format , ap));
	}
	return(check_my_format(format, ap));
}

/*int check_zero(const char *format, va_list ap)
{
}
*/
int return_char(va_list ap)
{
	int i;
	char c;
	i = va_arg(ap, int);
	c = i;
	write(1, &c, 1);
	return(1);
}

