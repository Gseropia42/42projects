/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 11:35:06 by gseropia          #+#    #+#             */
/*   Updated: 2015/11/30 17:58:20 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*result;
	size_t	index;
	size_t	indexfin;
	size_t	ir;

	if (!s)
		return (NULL);
	indexfin = ft_strlen(s) - 1;
	index = 0;
	ir = 0;
	while (s[index] == ' ' || s[index] == '\t' || s[index] == '\n')
		index++;
	if (index == ft_strlen(s))
		return (result = ft_strnew(0));
	while (s[indexfin] == ' ' || s[indexfin] == '\t' || s[indexfin] == '\n')
		indexfin--;
	result = ft_strnew(indexfin - index + 1);
	if (!result)
		return (NULL);
	while (index <= indexfin)
		result[ir++] = s[index++];
	result[ir] = '\0';
	return (result);
}
