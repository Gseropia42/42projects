/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 17:04:17 by gseropia          #+#    #+#             */
/*   Updated: 2016/02/09 11:52:07 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sources/push_swap.h"
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
	new = malloc(sizeof(t_plist));
	if (list1 && list1->next)
	{
		new->nb = list1->next->nb;
		list1->next = NULL;
	}
	else if (list1)
	{
		new->nb = list1->nb;
		*listin = NULL;
	}
	else
	{
		free (new);
		return ;
	}
	new->next = NULL;
	if (list2)
		list2->next = new;
	else
		*listout = new;
	ft_printf("%s", c);
}

int		ft_lstpush(t_plist **relou, char **argv, int lol, int max)
{
	t_plist	*prout;
	prout = malloc(sizeof(t_plist));

	if (lol > 0)
	{
		prout->next = NULL;
		prout->nb = ft_atoi(argv[lol--]);
		if (prout->nb > max)
			max = prout->nb;
		*relou = prout;
		return(ft_lstpush(&prout->next, argv, lol,max));
	}
	prout = NULL;
	*relou = prout;
	return(max);
}

int		main(int ac, char **argv)
{
	t_plist *pilea;
	t_plist *pileb;
	int		max;
	int		ret;

	ret = 1;
	pilea = NULL;
	pileb = NULL;
	if (ac < 2)
		return (0);
	max = ft_lstpush(&pilea, argv, ac - 1, INT_MIN);
	ft_lstpush(&pileb, argv, 0, 0);
	pileprint(pilea, pileb);
	pssolver(&pilea, &pileb, max);
	ft_printf("\n");
	pileprint(pilea, pileb);
	free(pilea);
	free(pileb);
	return (0);
}
