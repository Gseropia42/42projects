/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 14:44:03 by gseropia          #+#    #+#             */
/*   Updated: 2015/12/16 14:44:05 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = (char*)s;
	while (tmp[i])
		i++;
	if (c == '\0')
		return (tmp + i);
	i--;
	while (tmp[i])
	{
		if ((char)tmp[i] == (char)c)
			return (tmp + i);
		i--;
	}
	return (NULL);
}
