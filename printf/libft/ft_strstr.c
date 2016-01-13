/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:39:03 by gseropia          #+#    #+#             */
/*   Updated: 2015/12/07 12:36:56 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	const char	*temp;
	int			result;

	result = 0;
	temp = s1;
	while (*s1)
	{
		result = ft_strncmp(s1, s2, ft_strlen(s2));
		if (result == 0)
			return ((char*)s1);
		s1++;
	}
	if (*s2 == '\0')
		return ((char*)s1);
	return (NULL);
}
