/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 11:29:21 by gseropia          #+#    #+#             */
/*   Updated: 2015/12/07 11:22:00 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*result;
	unsigned int	index;

	if (!s1 || !s2)
		return (NULL);
	index = 0;
	result = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!result)
		return (NULL);
	while (s1[index])
	{
		result[index] = s1[index];
		index++;
	}
	index = 0;
	while (s2[index])
	{
		result[index + ft_strlen(s1)] = s2[index];
		index++;
	}
	result[index + ft_strlen(s1)] = '\0';
	return (result);
}
