/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:29:11 by gseropia          #+#    #+#             */
/*   Updated: 2016/02/09 11:40:28 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_itolol(unsigned int lol, unsigned int mask)
{
	unsigned char ret1;
	unsigned char ret2;
	unsigned char ret3;
	unsigned char ret4;
	unsigned char octet;

	ret4 = (lol << 26) >> 26;
	ret3 = ((lol >> 6) << 26) >> 26;
	ret2 = ((lol >> 12) << 26) >> 26;
	ret1 = ((lol >> 18) << 29) >> 29;
	octet = (mask >> 24) | ret1;
	write(1, &octet, 1);
	octet = ((mask << 8) >> 24) | ret2;
	write(1, &octet, 1);
	octet = ((mask << 16) >> 24) | ret3;
	write(1, &octet, 1);
	octet = ((mask << 24) >> 24) | ret4;
	write(1, &octet, 1);
}

void	ft_itoiii(unsigned int lol)
{
	unsigned int	mask;
	unsigned char	ret1;
	unsigned char	ret2;
	unsigned char	ret3;
	unsigned char	octet;

	mask = 14712960;
	ret1 = (lol << 26) >> 26;
	ret2 = ((lol >> 6) << 26) >> 26;
	ret3 = ((lol >> 12) << 28) >> 28;
	octet = (mask >> 16) | ret3;
	write(1, &octet, 1);
	octet = (mask << 16) >> 24 | ret2;
	write(1, &octet, 1);
	octet = (mask << 24) >> 24 | ret1;
	write(1, &octet, 1);
}

void	ft_itoii(unsigned int lol)
{
	unsigned int	mask;
	unsigned char	ret1;
	unsigned char	ret2;
	unsigned char	octet;

	mask = 49280;
	ret1 = (lol << 26) >> 26;
	ret2 = ((lol >> 6) << 27) >> 27;
	octet = (mask >> 8) | ret2;
	write(1, &octet, 1);
	octet = (mask << 24) >> 24 | ret1;
	write(1, &octet, 1);
}

int		read_wchar(wchar_t *temp)
{
	unsigned int	i;
	char			*s;
	int				ret;

	ret = 0;
	s = NULL;
	i = 0;
	while (*temp)
	{
		i = *temp;
		s = ft_itoabase(i, 2);
		if (ft_strlen(s) < 8 && (ret = ret + 1))
			ft_putchar(*temp);
		else if (ft_strlen(s) > 7 && ft_strlen(s) < 12 && (ret = ret + 2))
			ft_itoii(i);
		else if (ft_strlen(s) > 11 && ft_strlen(s) < 17 && (ret = ret + 3))
			ft_itoiii(i);
		else
		{
			ret = ret + 4;
			ft_itolol(i, 4034953344);
		}
		temp++;
	}
	return (ret);
}

int		read_achar(wint_t j)
{
	char			*s;
	unsigned int	i;
	int				ret;
	unsigned char	a;

	ret = 0;
	i = j;
	a = i;
	s = ft_itoabase(i, 2);
	if (ft_strlen(s) < 8 && (ret = ret + 1))
		write(1, &a, 1);
	else if (ft_strlen(s) > 7 && ft_strlen(s) < 12 && (ret = ret + 2))
		ft_itoii(i);
	else if (ft_strlen(s) > 11 && ft_strlen(s) < 17 && (ret = ret + 3))
		ft_itoiii(i);
	else
	{
		ret = ret + 4;
		ft_itolol(i, 4034953344);
	}
	return (ret);
}
