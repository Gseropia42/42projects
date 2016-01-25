/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 17:22:38 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/25 16:34:57 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	char	*pl(char *s1, unsigned long n, unsigned int sz, unsigned int b)
{
	unsigned int	index;
	unsigned long	lol;

	index = 0;
	lol = n;
	while (sz > index && sz)
	{
		if ((s1[sz - 1] = lol % b + '0') > 57)
			s1[sz - 1] = lol % b + '0' + 39;
		lol = lol / b;
		sz--;
	}
	return (s1);
}

char			*ft_longbase(unsigned long n, unsigned int base)
{
	unsigned long		test;
	unsigned int		taille;
	char				*ret;

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
		ret = pl(ret, n, taille, base);
	else
		return (NULL);
	return (ret);
}
