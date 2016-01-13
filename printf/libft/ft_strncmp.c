/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:15:11 by gseropia          #+#    #+#             */
/*   Updated: 2015/12/07 11:38:54 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int index;
	int result;

	result = 0;
	index = 0;
	if (n == 0)
		return (0);
	while (s1[index] == s2[index] && (s1[index] != '\0') && n > 1)
	{
		index++;
		n--;
	}
	result = ((unsigned char)s1[index] - (unsigned char)s2[index]);
	return (result);
}
