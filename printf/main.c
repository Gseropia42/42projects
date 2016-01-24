/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 11:49:23 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/24 20:19:22 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "libftprintf.h"
int ft_printf(const char *format, ...);


int main()
{
	int d;
	int e;
	void *lol;
	
	lol =NULL;
	e = printf("le  printf =% 05d\n", 0);
	d = ft_printf("mon printf =% 05d\n", 0);
/*	e = printf("le  printf = %hd\n", 63000);
	e = printf("le  printf = %hd\n", 1270);
	e = printf("le  printf = %hd\n", 32767);
	e = printf("le  printf = %hd\n", 25500);
	e = printf("le  printf = %hd\n", 32);
	e = printf("le  printf = %hd\n", 368);
	e = printf("le  printf = %hd\n", 45);
	e = printf("le  printf = %hd\n", 1);
	e = printf("le  printf = %hd\n", 0);
	e = printf("le  printf = %hd\n", 2);
*/	printf("mon retour : %d, retourprintf : %d\n", d , e);
	return (0);
}
