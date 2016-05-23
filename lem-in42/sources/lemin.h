/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 15:28:36 by gseropia          #+#    #+#             */
/*   Updated: 2016/04/05 14:46:37 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <fcntl.h>
# include "get_next_line.h"
# include "libftprintf.h"

typedef struct		s_tuyau
{
	int				pass;
	char			*depart;
	char			*arrivee;
	struct s_tuyau	*next;
}					t_tuyau;

typedef struct		s_room
{
	char			*name;
	int				depart;
	int				fmi;
	struct s_room	*next;
}					t_room;

typedef struct		s_lemin
{
	int				fourmi;
	char			*fich;
	struct s_tuyau	*tuyau;
	struct s_room	*depart;
	struct s_room	*trajet;
}					t_lemin;

char				*ft_wiwi(char *buf, char *toc);
char				*ft_pimp_my_stock(char *buf, char *stock);
void				ft_printscreen(t_room *t, int fou, int space, int fourm);
int					ft_tothefuture(t_lemin **lemin);
t_lemin				*ft_check_file(int fd);
int					ft_valid_list(t_lemin *list, int fourmi);
int					ck_my_p(t_tuyau *tuyau, t_room *salle);
#endif
