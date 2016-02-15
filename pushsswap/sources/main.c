/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 14:46:39 by gseropia          #+#    #+#             */
/*   Updated: 2016/02/15 14:35:04 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		checkmynumber(char *s)
{
	if (*s != '+' && *s != '-' && ft_isdigit(*s++) == 0)
		return (0);
	while (*s)
		if (!ft_isdigit(*s++))
			return (0);
	return (1);
}

int		ft_lstpush(t_plist **relou, char **argv, int lol)
{
	t_plist	*prout;
	char	*s;

	s = NULL;
	prout = malloc(sizeof(t_plist));
	if (lol > 0)
	{
		prout->next = NULL;
		if (checkmynumber(argv[lol]))
			prout->nb = ft_atoi(argv[lol--]);
		else
		{
			ft_printf("ENTREE INVALIDE\n");
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
				ft_printf("OH MON DIEU, %d est en double", piledeb->nb);
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
	int		ret;

	ret = 1;
	pilea = NULL;
	pileb = NULL;
	if (ac < 2)
		return (0);
	ft_lstpush(&pileb, argv, 0);
	if (ft_lstpush(&pilea, argv, ac - 1) && ft_doublon(&pilea))
	{
		max = ft_findmax(&pilea);
		pssolver(&pilea, &pileb, max);
	}
	free(pilea);
	free(pileb);
	return (0);
}
