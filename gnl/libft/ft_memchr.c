/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 22:37:04 by gseropia          #+#    #+#             */
/*   Updated: 2015/11/29 16:08:43 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char *source;

	source = (char*)s;
	while (n > 0)
	{
		if (*source == (char)c)
			return ((void*)source);
		n--;
		source++;
	}
	return (NULL);
}
