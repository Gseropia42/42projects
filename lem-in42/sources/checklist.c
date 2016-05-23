/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checklist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 14:01:22 by gseropia          #+#    #+#             */
/*   Updated: 2016/04/08 10:58:50 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	ck_my_p(t_tuyau *tuyau, t_room *salle)
{
	t_tuyau	*ttmp;
	t_room	*rtmp;

	ttmp = tuyau;
	rtmp = salle;
	if (ttmp)
	{
		while (rtmp)
		{
			if (!ft_strcmp(tuyau->depart, rtmp->name))
			{
				rtmp = salle;
				while (rtmp)
				{
					if (!ft_strcmp(tuyau->arrivee, rtmp->name))
						return (ck_my_p(tuyau->next, salle));
					rtmp = rtmp->next;
				}
				return (0);
			}
			rtmp = rtmp->next;
		}
		return (0);
	}
	return (1);
}

int	ft_checkendstart(t_lemin *list)
{
	int		ckstart;
	int		ckend;
	t_room	*temp;

	temp = list->depart;
	ckstart = 0;
	ckend = 0;
	while (temp)
	{
		if (temp->depart == 1)
			ckstart++;
		if (temp->depart == 2)
			ckend++;
		temp = temp->next;
	}
	if (ckstart == 1 && ckend == 1)
		return (1);
	return (0);
}

int	ft_valid_list(t_lemin *list, int fourmi)
{
	t_room *temp;
	t_room *temp2;

	temp2 = list->depart;
	if (!(temp = list->depart) || !list->depart->next || !fourmi)
		return (0);
	temp2 = temp->next;
	while (temp)
	{
		while (temp2)
		{
			if (temp->name == temp2->name)
				return (0);
			temp2 = temp2->next;
		}
		if ((temp = temp->next))
			temp2 = temp->next;
	}
	return (ft_checkendstart(list));
}
