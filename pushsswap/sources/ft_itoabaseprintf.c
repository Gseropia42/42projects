/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 17:22:38 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/26 16:34:17 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	char	*remplimoitoucaencore(char *s1, int n, size_t size, int base)
{
	size_t			index;
	unsigned int	lol;

	index = 0;
	lol = n;
	while (size > index && size)
	{
		if ((s1[size - 1] = lol % base + '0') > 57)
			s1[size - 1] = lol % base + '0' + 39;
		lol = lol / base;
		size--;
	}
	return (s1);
}

char			*ft_itoabaseprintf(unsigned int n, int base)
{
	unsigned int		test;
	size_t				taille;
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
		ret = remplimoitoucaencore(ret, n, taille, base);
	else
		return (NULL);
	return (ret);
}
