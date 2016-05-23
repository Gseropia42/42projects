/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfill.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:04:24 by gseropia          #+#    #+#             */
/*   Updated: 2015/12/09 16:35:58 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFILL_H
# define LIBFILL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define BUF_SIZE 555

void	fillblank(char *result, int *piece, int ecart, int a);
void	faimoishell(char *result, int *piece, int ecart, int a);
int		checkposition(int *piece, char *result, int ecart, int a);
int		solverresult(char *result, int **tablo, int ecart, int a);
void	ft_putstr(char *string);
char	*mallocresult(int i, char *grid);
void	weshwesh(int **tablo, int v);
int		*rempliadresse(int *piece, char *str, int i, int count);
int		**yoloswag(char *str, int v);
int		checkdiese(char *str, int i, int j);
int		ckbloc(char *str, int i);
int		checkall(char *str);
#endif
