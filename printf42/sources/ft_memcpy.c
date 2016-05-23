/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:32:48 by gseropia          #+#    #+#             */
/*   Updated: 2015/11/30 16:48:06 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	char		*a;
	const char	*b;

	a = ((char*)dst);
	b = (const char*)src;
	while (len > 0)
	{
		*a = *b;
		a++;
		b++;
		len--;
	}
	return (dst);
}
