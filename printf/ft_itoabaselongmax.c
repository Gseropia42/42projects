/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabaselongmax.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 17:05:45 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/21 17:06:26 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	char	*remplilong(char *s1, unsigned long n, size_t size, int base)
{
	size_t			index;
	unsigned long	lol;

	index = 0;
	lol = 0;
	lol = n;
	while (size > index && size)
	{
		if ((s1[size - 1] = lol % base + '0') > 57)
			s1[size - 1] = lol % base + '0' + 7;
		lol = lol / base;
		size--;
	}
	return (s1);
}

char			*ft_itoabase_long_max(unsigned long n, int base)
{
	unsigned long	test;
	size_t			taille;
	char			*ret;

	ret = NULL;
	taille = 1;
	test = n;
	while (test / base != 0)
	{
		taille++;
		test = test / base;
	}
	ret = ft_strnew(taille);
	if (ret)
		ret = remplilong(ret, n, taille, base);
	else
		return (NULL);
	return (ret);
}
