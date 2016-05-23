/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:46:23 by gseropia          #+#    #+#             */
/*   Updated: 2016/03/03 10:47:02 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int ret;
	int index;
	int check;

	check = 0;
	ret = 0;
	index = 0;
	while (str[index] == ' ' || str[index] == '\n' || str[index] == '\t' ||
			str[index] == '\r' || str[index] == '\v' || str[index] == '\f')
		index++;
	if (str[index] == '+' && ft_isdigit(str[index + 1]) == 1)
		index++;
	else if (str[index] == '-' && ft_isdigit(str[++index]) == 1)
		check = 1;
	else if (ft_isdigit(str[index]) == 0)
		return (0);
	while (ft_isdigit(str[index]))
	{
		ret = ret * 10 + (str[index] - 48);
		index++;
	}
	if (check == 1)
		return (-ret);
	return (ret);
}
