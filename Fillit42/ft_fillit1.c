/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:25:17 by gseropia          #+#    #+#             */
/*   Updated: 2015/12/07 20:06:38 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfill.h"

void	faimoishell(char *result, int *piece, int ecart, int a)
{
	int i;
	int div;

	i = 0;
	div = 0;
	result[a] = piece[4] + 65;
	i++;
	while (i < 4)
	{
		div = piece[i] / 4;
		result[piece[i] + a + (div * ecart)] = piece[4] + 65;
		i++;
	}
}

int		checkdiese(char *str, int i, int j)
{
	int n;

	n = 0;
	if (str[i - 1] == '#' && j > 1)
		n++;
	if (str[i + 1] == '#')
		n++;
	if (str[i + 5] == '#' && j < 15)
		n++;
	if (str[i - 5] == '#' && j > 5)
		n++;
	return (n);
}

int		ckbloc(char *str, int i)
{
	int check;
	int j;
	int ckline;
	int face;

	j = 0;
	ckline = 0;
	check = 0;
	face = 0;
	while (j++ < 20)
		if (str[i] == '\n')
		{
			i++;
			ckline++;
			if (j == 0 || (j % 5) != 0)
				return (0);
		}
		else if (str[i++] == '#')
		{
			face = face + checkdiese(str, i - 1, j);
			check++;
		}
	if (ckline == 4 && check == 4 && face > 5)
		return (1);
	return (0);
}

int		checkall(char *str)
{
	int result;
	int i;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] != '#' && str[i] != '.' && str[i] != '\n')
			return (0);
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (ckbloc(str, i) == 0 || (str[i + 20] != '\n' && str[i + 20] != '\0'))
			return (0);
		else
		{
			result++;
			i = i + 21;
		}
	}
	return (result);
}
