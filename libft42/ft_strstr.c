/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 14:44:12 by gseropia          #+#    #+#             */
/*   Updated: 2015/12/16 14:44:14 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (s2[i] != '\0')
		i++;
	while (j < i && s1[k])
	{
		if (s2[j] == s1[k])
			j++;
		else
		{
			k = k - j;
			j = 0;
		}
		k++;
	}
	if (i != j)
		return (NULL);
	return ((char*)(s1 + (k - i)));
}
