/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 10:49:31 by gseropia          #+#    #+#             */
/*   Updated: 2015/12/07 20:07:39 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfill.h"

void		fillblank(char *result, int *piece, int ecart, int a)
{
	int i;
	int div;

	i = 0;
	div = 0;
	result[a] = 46;
	i++;
	while (i < 4)
	{
		div = piece[i] / 4;
		result[piece[i] + a + (div * ecart)] = 46;
		i++;
	}
}

int			checkposition(int *piece, char *result, int ecart, int a)
{
	int i;
	int div;

	div = 0;
	i = 0;
	if (result[a] != '.')
		return (0);
	i++;
	while (i < 4)
	{
		div = piece[i] / 4;
		if (result[piece[i] + a + (div * ecart)] != '.')
			return (0);
		i++;
	}
	return (1);
}

int			solverresult(char *res, int **tab, int ecart, int k)
{
	int succes;
	int index;

	index = 0;
	succes = 0;
	if (tab[k])
	{
		while (res[index])
		{
			if (checkposition(tab[k], res, ecart, index))
			{
				faimoishell(res, tab[k], ecart, index);
				succes = solverresult(res, tab, ecart, k + 1);
				if (succes == 1)
					return (1);
				fillblank(res, tab[k], ecart, index);
			}
			index++;
		}
		return (0);
	}
	return (1);
}

char		*mallocresult(int i, char *grid)
{
	size_t	size;
	size_t	index;
	int		j;

	j = 0;
	index = 0;
	size = (i * (i + 1)) + 1;
	grid = (char*)malloc(sizeof(char) * size);
	grid[0] = '.';
	while (index < size)
	{
		if (j == i)
		{
			grid[index++] = '\n';
			j = 0;
		}
		else
		{
			grid[index++] = '.';
			j++;
		}
	}
	grid[size - 1] = '\0';
	return (grid);
}

void		weshwesh(int **tablo, int v)
{
	int		i;
	int		success;
	char	*result;
	int		ecart;

	ecart = 0;
	result = NULL;
	success = 0;
	i = 2;
	while (v * 4 > (i * i))
		i++;
	while (success == 0)
	{
		ecart = i - 4;
		result = mallocresult(i, result);
		success = solverresult(result, tablo, ecart, 0);
		if (success == 0)
		{
			free(result);
			i++;
		}
		if (success == 1)
			ft_putstr(result);
	}
}
