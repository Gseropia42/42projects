/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctionsps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 13:51:26 by gseropia          #+#    #+#             */
/*   Updated: 2016/03/03 14:56:06 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		tripile(t_plist **alpha, int mini, int n)
{
	t_plist *list;

	list = *alpha;
	while (list)
	{
		if (list->nb < mini && list->ro == 0)
			mini = list->nb;
		list = list->next;
	}
	list = *alpha;
	while (list && list->nb != mini)
		list = list->next;
	list->ro = n;
	list = *alpha;
	while (list)
	{
		if (list->ro == 0)
			return (1 + tripile(alpha, INT_MAX, n + 1));
		list = list->next;
	}
	return (1);
}

t_plist	*boutdechaine(t_plist **liste)
{
	t_plist *temp;

	temp = *liste;
	if (!temp)
		return (NULL);
	while (temp && temp->next)
		temp = temp->next;
	return (temp);
}

int		ft_checksize(long long data)
{
	if (data > INT_MAX || data < INT_MIN)
		return (0);
	return (1);
}

t_plist	*bout3chaine(t_plist **liste)
{
	t_plist *temp;

	temp = *liste;
	if (!temp)
		return (NULL);
	while (temp && temp->next && temp->next->next)
		temp = temp->next;
	return (temp);
}
