/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 14:46:39 by gseropia          #+#    #+#             */
/*   Updated: 2016/03/03 14:31:43 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		checkmynumber(char *s)
{
	if (*s != '+' && *s != '-' && ft_isdigit(*s) == 0)
		return (0);
	if (*s == '+' || *s == '-')
		s++;
	if (!ft_checksize(ft_longlongatoi(s)))
		return (0);
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

int		ft_lstpush(t_plist **relou, char **argv, int lol)
{
	t_plist	*prout;

	prout = malloc(sizeof(t_plist));
	if (lol > 0)
	{
		prout->ro = 0;
		prout->pos = 1;
		prout->next = NULL;
		if (checkmynumber(argv[lol]))
			prout->nb = ft_atoi(argv[lol--]);
		else
		{
			ft_printf("Error\n");
			return (0);
		}
		*relou = prout;
		return (ft_lstpush(&prout->next, argv, lol));
	}
	prout = NULL;
	*relou = prout;
	return (1);
}

int		ft_findmax(t_plist **pile)
{
	int		max;
	t_plist *pile1;

	pile1 = *pile;
	max = INT_MIN;
	while (pile1)
	{
		if (pile1->nb > max)
			max = pile1->nb;
		pile1 = pile1->next;
	}
	return (max);
}

int		ft_doublon(t_plist **pile)
{
	t_plist *piledeb;
	t_plist *pilefor;

	piledeb = *pile;
	pilefor = *pile;
	while (piledeb)
	{
		pilefor = piledeb->next;
		while (pilefor)
		{
			if (pilefor->nb == piledeb->nb)
			{
				ft_printf("Error\n");
				return (0);
			}
			pilefor = pilefor->next;
		}
		piledeb = piledeb->next;
	}
	return (1);
}

int		main(int ac, char **argv)
{
	t_plist *pilea;
	t_plist *pileb;
	int		max;

	pilea = NULL;
	pileb = NULL;
	if (ac < 2)
		return (0);
	ft_lstpush(&pileb, argv, 0);
	if (ft_lstpush(&pilea, argv, ac - 1) && ft_doublon(&pilea))
	{
		tripile(&pilea, INT_MAX, 1);
		pileprint(pilea, pileb, 0);
		max = ft_findmax(&pilea);
		while (pssolver(&pilea, &pileb, max))
			if (ft_check(&pilea, &pileb))
				ft_putchar(' ');
		while (pssolver2(&pilea, &pileb, max))
			if (ft_check(&pilea, &pileb))
				ft_putchar(' ');
		pileprint(pilea, pileb, 1);
	}
	free(pilea);
	free(pileb);
	return (0);
}
