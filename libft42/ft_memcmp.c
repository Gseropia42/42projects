/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 14:40:44 by gseropia          #+#    #+#             */
/*   Updated: 2015/12/16 14:40:45 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	a;
	char	b;

	i = 0;
	while (i < n)
	{
		if (((char*)s1)[i] != ((char*)s2)[i])
		{
			a = ((char*)s1)[i];
			b = ((char*)s2)[i];
			return ((unsigned char)a - (unsigned char)b);
		}
		i++;
	}
	return (0);
}
