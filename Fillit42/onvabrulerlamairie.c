/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onvabrulerlamairie.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 10:29:47 by gseropia          #+#    #+#             */
/*   Updated: 2015/12/07 20:09:33 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfill.h"

int		*rempliadresse(int *piece, char *str, int i, int count)
{
	int diese;
	int ecart;

	diese = 0;
	ecart = 0;
	piece = (int*)malloc(sizeof(int) * 5);
	while (diese < 4)
	{
		if (str[i] == '#' && diese != 0)
		{
			piece[diese] = i - ecart;
			diese++;
		}
		if (str[i] == '#' && diese == 0)
		{
			piece[diese] = 0;
			diese++;
			ecart = i;
		}
		i++;
	}
	piece[4] = count;
	return (piece);
}

void	ft_putstr(char *string)
{
	int i;

	i = 0;
	while (string[i] != '\0')
	{
		write(1, &string[i], 1);
		i++;
	}
}

int		**yoloswag(char *str, int nbtet)
{
	int	**tablo;
	int	*piece;
	int	i;
	int	numpiece;

	piece = NULL;
	i = 0;
	numpiece = 0;
	tablo = (int**)malloc(sizeof(int*) * nbtet + 1);
	tablo[nbtet] = NULL;
	while (nbtet > 0)
	{
		tablo[numpiece] = rempliadresse(piece, str, i, numpiece);
		numpiece++;
		nbtet--;
		i = i + 21;
	}
	return (tablo);
}
