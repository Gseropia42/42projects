/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:31:59 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/30 17:16:40 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *jj;

	jj = (char*)malloc(sizeof(char) * (size + 1));
	if (!jj)
		return (NULL);
	ft_bzero(jj, size + 1);
	return (jj);
}
