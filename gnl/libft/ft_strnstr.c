/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:07:08 by gseropia          #+#    #+#             */
/*   Updated: 2015/12/08 16:21:44 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t len;

	if (*s2 == '\0')
		return ((char*)s1);
	len = ft_strlen(s2);
//	if ()
//		return (NULL);
	while(*s1 != '\0' && n >= len)
	{
		if (ft_strncmp(s1, s2, len) == 0)
			return ((char*)s1);
		s1++;
		n--;
	} 
	return (NULL);
}
