/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:31:07 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/27 14:32:04 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*result;
	unsigned int	index;

	if (!s)
		return (NULL);
	index = 0;
	result = ft_strnew(len);
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (len > 0 && s[start + index])
	{
		result[index] = s[start + index];
		index++;
		len--;
	}
	result[index] = '\0';
	return (result);
}
