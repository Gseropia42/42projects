/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 17:04:53 by gseropia          #+#    #+#             */
/*   Updated: 2016/03/17 12:02:34 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "libftprintf.h"

typedef struct	s_plist
{
	int				nb;
	int				ro;
	int				pos;
	struct s_plist	*next;
}				t_plist;

int				ft_checksize(long long data);
int				check_rotate(t_plist **lol, int max);
int				check_rotate2(t_plist **lol, int max);
int				find_max(t_plist **liste, int debut);
t_plist			*boutdechaine(t_plist	**liste);
t_plist			*bout3chaine(t_plist	**liste);
int				ft_check(t_plist **alpha, t_plist **beta);
int				tripile(t_plist **alpha, int mini, int n);
int				ft_swap(t_plist **liste, char *affi);
int				ft_push(t_plist **listin, t_plist **listout, char *affi);
int				ft_rotate(t_plist **liste, char *affi);
int				ft_rrotate(t_plist **liste, char *affi);
void			pileprint(t_plist *alpha, t_plist *beta, int check);
int				pssolver(t_plist **alpha, t_plist **beta, int max);
int				pssolver2(t_plist **alpha, t_plist **beta, int max);
#endif
