/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coresolver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 14:04:40 by gseropia          #+#    #+#             */
/*   Updated: 2016/04/04 10:44:27 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room	*itsvalid(t_room *check)
{
	t_room *retour;

	retour = malloc(sizeof(t_room));
	if (!retour)
		return (NULL);
	retour->name = check->name;
	retour->depart = check->depart;
	retour->fmi = check->fmi;
	retour->next = NULL;
	return (retour);
}

int		ft_replace(t_lemin **lemin, t_tuyau *tuyau)
{
	t_tuyau	*temp;

	if (!tuyau)
		return (0);
	if (!(temp = (*lemin)->tuyau))
		return (0);
	while (temp && ft_strcmp(tuyau->depart, temp->depart)
			&& ft_strcmp(tuyau->arrivee, temp->arrivee))
		temp = temp->next;
	return (1);
}

t_room	*ft_last_block(t_room *depart, char *final)
{
	t_room *temp;

	temp = depart;
	while (temp && temp->name != final)
		temp = temp->next;
	return (itsvalid(temp));
}

t_room	*ft_trajet(t_lemin **lemin, char *d, char *f)
{
	t_tuyau *temp;
	t_room	*trajet;
	t_room	*check;

	check = (*lemin)->depart;
	if (!(temp = (*lemin)->tuyau) || !ft_strcmp(d, f))
		return (NULL);
	while ((temp && ft_strcmp(d, temp->depart) &&
		ft_strcmp(d, temp->arrivee)) || (temp && temp->pass == 1))
		temp = temp->next;
	if (temp)
		temp->pass = 1;
	while (check && ft_strcmp(check->name, d))
		check = check->next;
	if (!ft_replace(lemin, temp))
		return (NULL);
	trajet = itsvalid(check);
	if (!ft_strcmp(d, temp->depart) && ft_strcmp(f, temp->arrivee))
		trajet->next = ft_trajet(lemin, temp->arrivee, f);
	else if (!ft_strcmp(d, temp->arrivee) && ft_strcmp(f, temp->depart))
		trajet->next = ft_trajet(lemin, temp->depart, f);
	else if ((!ft_strcmp(d, temp->depart) && !ft_strcmp(f, temp->arrivee)) ||
			(!ft_strcmp(d, temp->arrivee) && !ft_strcmp(f, temp->depart)))
		trajet->next = ft_last_block((*lemin)->depart, f);
	return (trajet);
}

int		ft_tothefuture(t_lemin **lemin)
{
	t_room	*list;
	char	*dep;
	char	*final;

	list = (*lemin)->depart;
	while (list && list->depart != 1)
		list = list->next;
	dep = list->name;
	list = (*lemin)->depart;
	while (list && list->depart != 2)
		list = list->next;
	final = list->name;
	(*lemin)->trajet = ft_trajet(lemin, dep, final);
	list = (*lemin)->trajet;
	if (!list)
		return (0);
	(*lemin)->trajet->fmi = (*lemin)->fourmi;
	if (ft_strcmp(dep, list->name))
		return (0);
	while (list && list->next)
		list = list->next;
	if (ft_strcmp(final, list->name))
		return (0);
	return (1);
}
