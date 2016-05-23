/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 17:00:30 by gseropia          #+#    #+#             */
/*   Updated: 2015/12/14 16:03:49 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*temp;

	temp = (void*)malloc((sizeof(char) * len));
	temp = ft_memcpy(temp, src, len);
	dst = ft_memcpy(dst, temp, len);
	return (dst);
}
