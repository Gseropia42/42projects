/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:01:02 by gseropia          #+#    #+#             */
/*   Updated: 2015/11/29 15:57:19 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int index;

	if (!s1 || !s2)
		return (0);
	index = 0;
	if (n == 0)
		return (1);
	while (s1[index] != '\0' && s2[index] != '\0' && n > 1)
	{
		if (s1[index] == s2[index])
		{
			index++;
			n--;
		}
		else
			return (0);
	}
	if (s1[index] == s2[index])
		return (1);
	else
		return (0);
	return (0);
}
