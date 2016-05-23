/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:40:13 by gseropia          #+#    #+#             */
/*   Updated: 2015/11/29 15:44:40 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int index;

	if (!s1 || !s2)
		return (0);
	index = 0;
	while (s1[index] != '\0' && s2[index] != '\0')
	{
		if (s1[index] == s2[index])
			index++;
		else
			return (0);
	}
	if (s1[index] == s2[index])
		return (1);
	else
		return (0);
	return (0);
}
