/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 17:04:17 by gseropia          #+#    #+#             */
/*   Updated: 2016/03/02 16:35:10 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int		ft_swap(t_plist **liste, char *c)
{
	int		temp;
	t_plist	*rekt;

	rekt = *liste;
	temp = 0;
	if (!rekt || !rekt->next)
		return (0);
	while (rekt->next->next)
		rekt = rekt->next;
	temp = rekt->nb;
	rekt->nb = rekt->next->nb;
	rekt->next->nb = temp;
	temp = rekt->ro;
	rekt->ro = rekt->next->ro;
	rekt->next->ro = temp;
	ft_putstr(c);
	return (1);
}

int		ft_rrotate(t_plist **liste, char *c)
{
	t_plist	*rekt;
	int		temp;
	int		tempro;

	rekt = *liste;
	if (rekt)
	{
		tempro = rekt->ro;
		temp = rekt->nb;
	}
	if (rekt && rekt->next)
	{
		while (rekt && rekt->next)
		{
			rekt->nb = rekt->next->nb;
			rekt->ro = rekt->next->ro;
			rekt = rekt->next;
		}
		rekt->nb = temp;
		rekt->ro = tempro;
		ft_putstr(c);
		return (1);
	}
	return (0);
}

int		ft_rotate(t_plist **liste, char *c)
{
	t_plist *rekt;
	t_plist *rekt2;
	t_plist *rekt3;

	rekt = *liste;
	rekt2 = *liste;
	if (rekt && rekt->next && rekt->next->next)
	{
		while (rekt && rekt->next && rekt->next->next)
			rekt = rekt->next;
		rekt3 = rekt->next;
		*liste = rekt3;
		rekt3->next = rekt2;
		rekt->next = NULL;
		ft_putstr(c);
		return (1);
	}
	return (0);
}

int		ft_pushnext(t_plist **listin, t_plist **listout, char *c)
{
	t_plist *list1;
	t_plist *list2;

	list1 = *listin;
	list2 = *listout;
	while (list1 && list1->next && list1->next->next)
		list1 = list1->next;
	while (list2 && list2->next)
		list2 = list2->next;
	if (!list2)
	{
		list2 = list1;
		list2->pos = 1;
		*listin = NULL;
		*listout = list2;
	}
	else
	{
		list2->next = list1;
		*listin = NULL;
		list2->next->pos = list2->pos + 1;
	}
	ft_putstr(c);
	return (1);
}

int		ft_push(t_plist **listin, t_plist **listout, char *c)
{
	t_plist *list1;
	t_plist *list2;

	list2 = *listout;
	if ((list1 = *listin) && list1->next)
	{
		list1 = bout3chaine(listin);
		list2 = boutdechaine(listout);
		if (!list2)
		{
			list2 = list1->next;
			list2->pos = 1;
			list1->next = NULL;
			*listout = list2;
		}
		else
		{
			list2->next = list1->next;
			list1->next = NULL;
			list2->next->pos = list2->pos + 1;
		}
		ft_putstr(c);
		return (1);
	}
	return (ft_pushnext(listin, listout, c));
}
