/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pssolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 10:44:26 by gseropia          #+#    #+#             */
/*   Updated: 2016/02/10 19:15:04 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_min(t_plist **liste, int debut)
{
	int		min;
	t_plist	*temp;

	min = 0;
	temp = *liste;
	while (temp && debut--)
		temp = temp->next;
	if (!temp)
		return (min);
	while (temp)
	{
		if (temp->nb < min)
			min = temp->nb;
		temp = temp->next;
	}
	return (min);
}

int		find_max(t_plist **liste, int debut)
{
	int		max;
	t_plist	*temp;

	temp = *liste;
	max = INT_MIN;
	while (temp && debut--)
		temp = temp->next;
	if (!temp)
		return (max);
	while (temp)
	{
		if (temp->nb > max)
			max = temp->nb;
		temp = temp->next;
	}
	return (max);
}

int		ft_check(t_plist **alpha, t_plist **beta)
{
	t_plist	*temp;
	t_plist *temp2;

	temp2 = *beta;
	temp = *alpha;
	while (temp && temp->next && temp->nb > temp->next->nb)
		temp = temp->next;
	if (!temp->next && !temp2)
		return (0);
	return (1);
}

int		pssolver(t_plist **alpha, t_plist **beta, int max)
{
	t_plist *tmpa;
	t_plist *tmpb;

	tmpa = *alpha;
	while (tmpa->nb != max)
	{
		ft_rotate(alpha, "ra");
		if (ft_check(alpha, beta))
			ft_printf(" ");
	}
	if ((tmpa = *alpha) && ft_check(alpha, beta))
		while (tmpa->next)
			ft_push(alpha, beta, "pb ");
	tmpb = *beta;
	while ((tmpb = *beta))
	{
		max = find_max(beta, 0);
		while (tmpb->nb != max)
			ft_rotate(beta, "rb ");
		ft_rotate(beta, "rb ");
		ft_push(beta, alpha, "pa");
		if (ft_check(alpha, beta))
			ft_printf(" ");
	}
	return (0);
}

void	pileprint(t_plist *alpha, t_plist *beta)
{
	t_plist *temp;

	temp = alpha;
	ft_printf("Pile a : ");
	while (temp)
	{
		ft_printf("%d ", temp->nb);
		temp = temp->next;
	}
	temp = beta;
	ft_printf("\nPile b : ");
	while (temp)
	{
		ft_printf("%d ", temp->nb);
		temp = temp->next;
	}
	write(1, "\n", 1);
}
