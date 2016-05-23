/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:02:01 by gseropia          #+#    #+#             */
/*   Updated: 2015/12/15 15:19:22 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*result;
	int		index;

	if (!s || !f)
		return (NULL);
	index = 0;
	result = ft_strnew(ft_strlen(s));
	if (!result)
		return (NULL);
	while (s[index])
	{
		result[index] = f(s[index]);
		index++;
	}
	result[index] = '\0';
	return (result);
}
