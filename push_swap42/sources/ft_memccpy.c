/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:16:54 by gseropia          #+#    #+#             */
/*   Updated: 2015/11/29 16:07:18 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*d;
	const char	*s;

	d = ((char*)dst);
	s = ((char*)src);
	while (n > 0)
	{
		*d = *s;
		if (*d == c)
		{
			d++;
			return ((void*)d);
		}
		d++;
		s++;
		n--;
	}
	return (NULL);
}
