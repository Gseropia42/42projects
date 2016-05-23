/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 14:59:27 by gseropia          #+#    #+#             */
/*   Updated: 2016/04/04 10:44:18 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_checklist(t_room *list, int fourmi)
{
	t_room *temp;

	temp = list;
	while (temp)
	{
		if (temp->fmi < fourmi)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int		main(void)
{
	t_lemin	*n;

	if ((n = ft_check_file(0)) && ft_valid_list(n, n->fourmi) && n->fourmi)
	{
		if ((!n->tuyau || !ck_my_p(n->tuyau, n->depart)) && ft_printf("ERROR"))
			return (0);
		if (ft_tothefuture(&n) && n->trajet)
		{
			ft_printf("%s\n", n->fich);
			while (ft_checklist(n->trajet, n->trajet->fmi))
			{
				ft_printscreen(n->trajet, n->fourmi--, 0, n->trajet->fmi);
				ft_putchar('\n');
			}
		}
		else
			ft_putstr("ERROR");
	}
	else
		ft_putstr("ERROR");
	free(n);
	return (0);
}
