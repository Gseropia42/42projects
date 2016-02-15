/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:33:03 by gseropia          #+#    #+#             */
/*   Updated: 2015/12/14 16:06:25 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *lol;

	lol = (void*)malloc(sizeof(void) * size + 1);
	if (!lol)
		return (NULL);
	ft_bzero(lol, size + 1);
	return (lol);
}
