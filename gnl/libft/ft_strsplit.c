/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:38:02 by gseropia          #+#    #+#             */
/*   Updated: 2015/12/15 15:17:58 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		countwords(char const *s, char c)
{
	int count;
	int index;

	index = 0;
	count = 0;
	while (s[index])
	{
		if (s[index] == c)
			index++;
		else
		{
			count++;
			while (s[index] != c && s[index])
				index++;
		}
	}
	return (count);
}

static	char	*ft_capasse(int taille, int debut, const char *s, char *res)
{
	int index;

	index = 0;
	while (taille > 0)
	{
		res[index] = s[debut];
		debut++;
		index++;
		taille--;
	}
	res[index] = '\0';
	return (res);
}

static	char	**ft_venez_par_ici(char const *s, char **p, int nb, char c)
{
	int debut;
	int taille;
	int index;

	debut = 0;
	taille = 0;
	index = 0;
	while (s[index])
	{
		if (s[index] == c)
			index++;
		else
		{
			debut = index;
			while (s[index] && s[index++] != c)
				taille++;
			p[nb] = ft_strnew(taille);
			p[nb] = ft_capasse(taille, debut, s, p[nb]);
			nb++;
			taille = 0;
		}
	}
	p[nb] = ft_strnew(0);
	p[nb] = NULL;
	return (p);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**phrase;
	int		countword;

	countword = 0;
	if (!s)
		return (NULL);
	countword = countwords(s, c);
	phrase = (char**)malloc(sizeof(char*) * (countword + 1));
	if (!phrase)
		return (NULL);
	phrase = ft_venez_par_ici(s, phrase, 0, c);
	return (phrase);
}
