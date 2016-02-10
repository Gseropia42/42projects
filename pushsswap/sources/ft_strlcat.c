/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:16:27 by gseropia          #+#    #+#             */
/*   Updated: 2015/11/29 16:01:19 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t srclen;
	size_t destlen;
	size_t index;

	index = 0;
	srclen = ft_strlen(src);
	destlen = ft_strlen(dest);
	if (n < destlen)
		return (srclen + n);
	while (n - destlen - 1 > 0)
	{
		dest[index + destlen] = src[index];
		index++;
		n--;
	}
	if (n > 0)
		dest[index + destlen] = '\0';
	return (destlen + srclen);
}
