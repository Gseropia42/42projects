/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   returnmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:18:43 by gseropia          #+#    #+#             */
/*   Updated: 2016/04/07 14:29:39 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char	*ft_wiwi(char *buf, char *toc)
{
	toc = ft_pimp_my_stock(buf, toc);
	toc = ft_pimp_my_stock("\n", toc);
	return (toc);
}

void	ft_printscreen(t_room *trajet, int fourmi, int space, int check)
{
	t_room *temp;

	temp = trajet;
	while (temp)
	{
		if (temp->fmi)
		{
			ft_printscreen(temp->next, fourmi, 1, check);
			if (temp->next && temp->next->fmi < check)
			{
				ft_printf("L%d-%s", ++temp->next->fmi, temp->next->name);
				if ((space && temp->next->depart != 1) &&
						temp->next->fmi < check)
					ft_putchar(' ');
			}
			return ;
		}
		temp = temp->next;
	}
}
