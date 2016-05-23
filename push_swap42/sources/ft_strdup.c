/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:20:06 by gseropia          #+#    #+#             */
/*   Updated: 2015/12/11 14:35:11 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	taille;

	taille = ft_strlen(s1);
	copy = (char *)malloc((taille + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	ft_strcpy(copy, s1);
	return (copy);
}
