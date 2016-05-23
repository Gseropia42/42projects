/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checklemin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 15:19:51 by gseropia          #+#    #+#             */
/*   Updated: 2016/04/08 11:03:18 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_valid_pipe(char *line, t_room *list)
{
	char	**tab;
	int		check;
	t_room	*temp;

	temp = list;
	check = 0;
	if ((tab = ft_strsplit(line, ' ')) && tab[0] && !tab[1])
		tab = ft_strsplit(tab[0], '-');
	else
		return (0);
	if (tab && tab[0] && tab[1] && !tab[2])
		while (temp && check != 2)
		{
			if (!ft_strcmp(temp->name, *tab))
			{
				check++;
				temp = list;
				tab++;
			}
			else
				temp = temp->next;
		}
	if (check == 2)
		return (1);
	return (0);
}

t_tuyau	*ft_check_pipe(char **loul, int fd, t_room *list, char **fich)
{
	t_tuyau *pipe;
	char	**tab;

	if (ft_valid_pipe(*loul, list))
	{
		pipe = malloc(sizeof(t_tuyau));
		tab = ft_strsplit(*loul, ' ');
		tab = ft_strsplit(tab[0], '-');
		*fich = ft_pimp_my_stock(*loul, *fich);
		*fich = ft_pimp_my_stock("\n", *fich);
		pipe->pass = 0;
		pipe->depart = tab[0];
		pipe->arrivee = tab[1];
		if (get_next_line(fd, loul))
			pipe->next = ft_check_pipe(loul, fd, list, fich);
		else
			pipe->next = NULL;
		return (pipe);
	}
	return (NULL);
}

int		ft_valid_line(char *line, int depart)
{
	char	**tab;
	int		lol;

	lol = 0;
	if (!line)
		return (0);
	tab = ft_strsplit(line, ' ');
	if (!tab[0])
		return (0);
	if (depart == 0 && (!ft_strcmp(tab[0], "##start") ||
				!ft_strcmp(tab[0], "##end")))
		return (1);
	if (tab[0][0] == '#')
		return (2);
	if (tab && tab[0] && tab[1] && tab[2] && (ft_atoi(tab[1])
			|| tab[1][0] == '0') &&
			(ft_atoi(tab[2]) || tab[2][0] == '0') && !tab[3])
		return (1);
	else
		return (0);
}

t_room	*ft_check_salle(char **loul, int fd, int depart, char **fich)
{
	t_room	*salle;
	char	**tab;
	int		ret;

	ret = get_next_line(fd, loul);
	if (ret == 1 && ft_valid_line(*loul, depart) == 1 &&
			(*fich = ft_wiwi(*loul, *fich)))
	{
		if (!(tab = ft_strsplit(*loul, ' ')))
			return (NULL);
		if (!ft_strcmp(tab[0], "##start") && depart == 0)
			return (ft_check_salle(loul, fd, 1, fich));
		if (!ft_strcmp(tab[0], "##end") && depart == 0)
			return (ft_check_salle(loul, fd, 2, fich));
		salle = malloc(sizeof(t_room));
		salle->name = tab[0];
		salle->fmi = 0;
		salle->depart = depart;
		salle->next = ft_check_salle(loul, fd, 0, fich);
		return (salle);
	}
	else if (ret == 1 && ft_valid_line(*loul, depart) == 2)
		return (ft_check_salle(loul, fd, depart, fich));
	return (NULL);
}

t_lemin	*ft_check_file(int fd)
{
	char	*line;
	int		fourmi;
	t_lemin	*noraj;

	noraj = malloc(sizeof(t_lemin));
	line = NULL;
	fourmi = 0;
	if (fd > -1)
	{
		if (get_next_line(fd, &line) != 1 || (fourmi = ft_atoi(line)) < 1)
			return (0);
		noraj->fourmi = ft_atoi(line);
		noraj->fich = ft_pimp_my_stock("\n", line);
		noraj->depart = ft_check_salle(&line, fd, 0, &noraj->fich);
		noraj->tuyau = ft_check_pipe(&line, fd, noraj->depart, &noraj->fich);
		noraj->trajet = NULL;
	}
	return (noraj);
}
