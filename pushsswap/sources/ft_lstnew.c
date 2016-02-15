/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:38:14 by gseropia          #+#    #+#             */
/*   Updated: 2015/12/08 19:04:51 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

struct s_list	*ft_lstnew(void const *content, size_t content_size)
{
	struct s_list	*newelem;

	newelem = (t_list*)malloc(sizeof(t_list));
	if (!newelem)
		return (NULL);
	newelem->content = (void*)malloc(content_size);
	if (!newelem->content)
	{
		free(newelem);
		return (NULL);
	}
	if (content == NULL)
	{
		newelem->content = NULL;
		newelem->content_size = 0;
		newelem->next = NULL;
		return (newelem);
	}
	newelem->content = ft_memmove(newelem->content, content, content_size);
	newelem->content_size = content_size;
	newelem->next = NULL;
	return (newelem);
}
