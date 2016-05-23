/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:33:03 by gseropia          #+#    #+#             */
/*   Updated: 2015/11/29 16:09:24 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *lol;

	lol = (void*)malloc(sizeof(size_t) * size);
	if (!lol)
		return (NULL);
	ft_bzero(lol, size);
	return (lol);
}
