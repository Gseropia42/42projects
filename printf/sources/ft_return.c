/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 13:16:36 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/17 18:11:33 by gseropia         ###   ########.fr       */
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

int return_base(va_list ap, int base, size_t size)
{
	char *nbr;
	int taille;
	int ret;

	ret = 0;
	nbr = ft_itoabase(va_arg(ap, unsigned int), base);
	taille = ft_strlen(nbr);
	while (size-- > taille)
	{
		write(1, "0", 1);
		ret++;
	}
	ft_putstr(nbr);
	return(ft_strlen(nbr) + ret);
}

int return_base_max(va_list ap, int base, size_t size)
{
	char *nbr;
	int taille;
	int ret;
	
	ret = 0;
	nbr = ft_itoabase_max(va_arg(ap, unsigned int), base);
	taille = ft_strlen(nbr);
	while (size-- > taille)
	{
		write(1, "0", 1);
		ret++;
	}
	ft_putstr(nbr);
	return(ft_strlen(nbr) + ret);
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

int return_int(va_list ap, size_t size)
{
	char *nbr;
	int taille;
	int ret;

	ret = 0;
	nbr = ft_itoa(va_arg(ap,int));
	taille = ft_strlen(nbr);
	while (size-- > taille)
	{
		write(1, "0", 1);
		ret++;
	}
	ft_putstr(nbr);
	return(ft_strlen(nbr) + ret);
}

int return_unsigned(va_list ap, size_t size)
{
	char *nbr;
	int taille;
	int ret;

	ret = 0;
	nbr = ft_itoa(va_arg(ap,unsigned int));
	taille = ft_strlen(nbr);
	while (size-- > taille)
	{
		write(1, "0", 1);
		ret++;
	}
	ft_putstr(nbr);
	return(ft_strlen(nbr));
}

int return_unsigned_long(va_list ap, size_t size)
{
	char *nbr;
	int taille;
	int ret;

	ret = 0;
	nbr = ft_itoa(va_arg(ap,unsigned long));
	taille = ft_strlen(nbr);
	while (size-- > taille)
	{
		write(1, "0", 1);
		ret++;
	}
	ft_putstr(nbr);
	return(ft_strlen(nbr));
}

int return_long(va_list ap, size_t size)
{
	char *nbr;
	size_t temp;
	int taille;
	int ret;

	ret = 0;
	temp = size;
	nbr = ft_itoa(va_arg(ap, long));
	taille = ft_strlen(nbr);
	while (size-- > taille)
	{
		write(1, "0", 1);
		ret++;
	}
	ft_putstr(nbr);
	return(ft_strlen(nbr));
}
