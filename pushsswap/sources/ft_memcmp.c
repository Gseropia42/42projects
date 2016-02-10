/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:57:40 by gseropia          #+#    #+#             */
/*   Updated: 2015/12/08 15:54:31 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*ex1;
	const char	*ex2;
	size_t		i;
	int			result;

	i = 0;
	ex1 = (const char*)s1;
	ex2 = (const char*)s2;
	if (n == 0)
		return (0);
	while (n > 1 && ex1[i] == ex2[i])
	{
		i++;
		n--;
	}
	result = ((unsigned char)ex1[i] - (unsigned char)ex2[i]);
	return (result);
}
