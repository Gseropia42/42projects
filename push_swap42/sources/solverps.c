/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solverps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:35:21 by gseropia          #+#    #+#             */
/*   Updated: 2016/03/03 14:55:30 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_checkfinish(t_plist **liste, int max)
{
	t_plist	*tt;
	t_plist *pt;

	tt = *liste;
	pt = *liste;
	while (pt && pt->next)
		pt = pt->next;
	while (tt && tt->next)
	{
		if ((tt->ro - pt->ro == 1) && (tt->nb == max) && (tt->nb != pt->nb))
		{
			ft_rrotate(liste, "rra ");
			ft_swap(liste, "sa ");
			ft_rotate(liste, "ra ");
			ft_rotate(liste, "ra ");
			return (0);
		}
		else if (tt->ro - tt->next->ro != 1)
			return (0);
		tt = tt->next;
	}
	return (1);
}

int		pssolver(t_plist **li, t_plist **lt, int max)
{
	t_plist *a;
	t_plist *b;

	b = *li;
	if ((a = *li) && a->next && ft_check(li, lt))
	{
		a = bout3chaine(li);
		if (a->next && (a->next->ro - a->ro == 1))
		{
			if (ft_swap(li, "sa"))
				return (1);
		}
		else if (b && b->nb != max)
		{
			if (check_rotate(li, max))
				return (1);
		}
		else if (b && b->next && !ft_checkfinish(li, max) && ft_check(li, lt))
		{
			if (ft_push(li, lt, "pb"))
				return (1);
		}
	}
	return (0);
}

int		pssolver2(t_plist **li, t_plist **lt, int max)
{
	t_plist	*a;

	max = find_max(lt, 0);
	a = bout3chaine(lt);
	if (a && a->next && a->next->nb != max)
	{
		max = find_max(lt, 0);
		if (ft_check(li, lt) && a && a->next &&
				(a->ro - a->next->ro == 1))
		{
			if (ft_swap(lt, "sb"))
				return (1);
		}
		else if (a && a->next && ft_check(li, lt))
		{
			if (check_rotate2(lt, max))
				return (1);
		}
	}
	if (a && ((a->next && a->next->nb == max) || (!a->next)))
		if (ft_push(lt, li, "pa"))
			return (1);
	return (0);
}
