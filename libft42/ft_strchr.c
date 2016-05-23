/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 14:42:09 by gseropia          #+#    #+#             */
/*   Updated: 2015/12/16 14:42:10 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = (char*)s;
	while (tmp[i])
	{
		if ((char)tmp[i] == (char)c)
			return (tmp + i);
		i++;
	}
	if (c == '\0')
		return (tmp + i);
	return (NULL);
}
