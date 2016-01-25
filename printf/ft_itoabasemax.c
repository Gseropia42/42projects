/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabasemax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 17:06:35 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/25 16:36:53 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	char	*remplimoitoucaaussi(char *s1, int n, size_t size, int base)
{
	size_t			index;
	unsigned int	lol;

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

char			*ft_itoabase_max(unsigned int n, int base)
{
	unsigned int	test;
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
		ret = remplimoitoucaaussi(ret, n, taille, base);
	else
		return (NULL);
	return (ret);
}
