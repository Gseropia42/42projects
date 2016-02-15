/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 17:04:17 by gseropia          #+#    #+#             */
/*   Updated: 2016/02/15 15:20:07 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_swap(t_plist **liste, char *c)
{
	int		temp;
	t_plist	*rekt;

	rekt = *liste;
	temp = 0;
	if (!rekt || !rekt->next)
		return ;
	while (rekt->next->next)
		rekt = rekt->next;
	temp = rekt->nb;
	rekt->nb = rekt->next->nb;
	rekt->next->nb = temp;
	ft_printf("%s", c);
}

void	ft_rrotate(t_plist **liste, char *c)
{
	t_plist	*rekt;
	int		temp;

	rekt = *liste;
	temp = rekt->nb;
	if (rekt && rekt->next)
	{
		while (rekt && rekt->next)
		{
			rekt->nb = rekt->next->nb;
			rekt = rekt->next;
		}
		rekt->nb = temp;
	}
	ft_printf("%s", c);
}

void	ft_rotate(t_plist **liste, char *c)
{
	int		temp;
	t_plist	*rekt;

	rekt = *liste;
	if (rekt && rekt->next)
	{
		temp = rekt->nb;
		while (rekt && rekt->next)
		{
			rekt->nb = rekt->next->nb;
			rekt = rekt->next;
		}
		rekt->nb = temp;
	}
	ft_printf("%s", c);
}

void	checklist2(t_plist **listout, t_plist *new)
{
	t_plist *list2;

	list2 = *listout;
	if (list2)
		list2->next = new;
	else
		*listout = new;
}

void	ft_push(t_plist **listin, t_plist **listout, char *c)
{
	t_plist *list1;
	t_plist *list2;
	t_plist	*new;

	list1 = *listin;
	list2 = *listout;
	while (list1 && list1->next && list1->next->next)
		list1 = list1->next;
	while (list2 && list2->next)
		list2 = list2->next;
	if (!list1)
		return ;
	new = malloc(sizeof(t_plist));
	new->nb = list1->nb;
	if (list1 && list1->next)
	{
		new->nb = list1->next->nb;
		list1->next = NULL;
	}
	else if (list1)
		*listin = NULL;
	new->next = NULL;
	checklist2(listout, new);
	ft_printf("%s", c);
}
