/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:33:15 by gseropia          #+#    #+#             */
/*   Updated: 2015/11/29 15:54:41 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t len;
	size_t relen;

	len = ft_strlen(s);
	relen = len;
	if (s == NULL)
		return (NULL);
	while (len > 0)
	{
		s++;
		len--;
	}
	while (relen > 0)
	{
		if (*s == (char)c)
			return ((char*)s);
		s--;
		relen--;
	}
	if (*s == (char)c)
		return ((char*)s);
	return (NULL);
}
