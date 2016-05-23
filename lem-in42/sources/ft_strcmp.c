/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:54:42 by gseropia          #+#    #+#             */
/*   Updated: 2015/11/26 17:20:59 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int index;
	int result;

	result = 0;
	index = 0;
	while (s1[index] == s2[index] && (s1[index] != '\0'))
		index++;
	result = ((unsigned char)s1[index] - (unsigned char)s2[index]);
	return (result);
}
