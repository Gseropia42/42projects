/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pssolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 10:44:26 by gseropia          #+#    #+#             */
/*   Updated: 2016/03/03 14:53:48 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int		ft_check(t_plist **li, t_plist **lt)
{
	t_plist	*temp;
	t_plist *temp2;

	temp2 = *lt;
	temp = *li;
	while (temp && temp->next && temp->nb > temp->next->nb)
		temp = temp->next;
	if (!temp->next && !temp2)
		return (0);
	return (1);
}

int		check_rotate(t_plist **list, int max)
{
	t_plist *a;
	int		n;

	n = 0;
	a = *list;
	while (a && a->nb != max)
	{
		n++;
		a = a->next;
	}
	a = a->next;
	while (a)
	{
		n--;
		a = a->next;
	}
	if (n > 0)
		return (ft_rotate(list, "ra"));
	else
		return (ft_rrotate(list, "rra"));
}

int		check_rotate2(t_plist **list, int max)
{
	t_plist *a;
	int		n;

	n = 0;
	a = *list;
	while (a && a->nb != max)
	{
		n++;
		a = a->next;
	}
	if (a->next)
		a = a->next;
	while (a)
	{
		n--;
		a = a->next;
	}
	if (n >= 0)
		return (ft_rotate(list, "rb"));
	else
		return (ft_rrotate(list, "rrb"));
}

void	pileprint(t_plist *li, t_plist *lt, int check)
{
	t_plist *temp;

	temp = li;
	if (check)
		ft_putchar('\n');
	ft_printf("Pile a : ");
	while (temp)
	{
		ft_printf("%d", temp->nb);
		temp = temp->next;
		if (temp)
			ft_putchar(' ');
	}
	temp = lt;
	ft_printf("\nPile b : ");
	while (temp)
	{
		ft_printf("%d ", temp->nb);
		temp = temp->next;
		if (temp)
			ft_putchar(' ');
	}
	write(1, "\n", 1);
}
