/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 17:04:53 by gseropia          #+#    #+#             */
/*   Updated: 2016/02/10 16:19:51 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "libftprintf.h"

typedef struct	s_plist
{
	int				nb;
	struct s_plist	*next;
}				t_plist;

void			ft_swap(t_plist **liste, char *affi);
void			ft_push(t_plist **listin, t_plist **listout, char *affi);
void			ft_rotate(t_plist **liste, char *affi);
void			ft_rrotate(t_plist **liste, char *affi);
int				pssolver(t_plist **alpha, t_plist **beta, int max);
void			pileprint(t_plist *alpha, t_plist *beta);
#endif
