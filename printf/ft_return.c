/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 13:16:36 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/13 16:34:38 by gseropia         ###   ########.fr       */
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

int return_base(va_list ap, int base)
{
	char *nbr;
//	if (maj == 0)
//		nbr = ft_itoabase(va_arg(ap, int), base);
//	if (maj == 1)
//		nbr = ft_itoabase_max(va_arg(ap, int), base);
	nbr = ft_itoabase(va_arg(ap,int), base);
	ft_putstr(nbr);
	return(ft_strlen(nbr));
}

int return_base_max(va_list ap, int base)
{
	char *nbr;

	nbr = ft_itoabase_max(va_arg(ap, int), base);
	ft_putstr(nbr);
	return(ft_strlen(nbr));
}
int return_char(va_list ap)
{
	int i;
	char c;
	i = va_arg(ap, int);
	c = i;
	write(1, &c, 1);
	return(1);
}

int return_int(va_list ap)
{
	char *nbr;

	nbr = ft_itoa(va_arg(ap, int));
	ft_putstr(nbr);
	return(ft_strlen(nbr));
}

int return_unsigned(va_list ap)
{
	char *nbr;

	nbr = ft_itoa(va_arg(ap, unsigned int));
	ft_putstr(nbr);
	return(ft_strlen(nbr));
}

int return_unsigned_long(va_list ap)
{
	char *nbr;
	nbr = ft_itoa(va_arg(ap, unsigned long));
	ft_putstr(nbr);
	return(ft_strlen(nbr));
}

int return_long(va_list ap)
{
	char *nbr;
	nbr = ft_itoa(va_arg(ap, long));
	ft_putstr(nbr);
	return(ft_strlen(nbr));
}
