/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freejoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 13:59:42 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/27 15:23:40 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_freejoin(t_sdp *s, char *buf)
{
	char *temp;
	temp = NULL;
	if (!s->string)
		return (ft_strdup(buf));
	
	temp = ft_strdup(s->string);
	free(s->string);
	s->string = ft_strjoin(temp, buf);
	free(temp);
	return (s->string);
}
