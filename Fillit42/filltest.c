/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filltest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:38:52 by gseropia          #+#    #+#             */
/*   Updated: 2015/12/09 16:39:59 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfill.h"

void	ft_pute_error(void)
{
	write(2, "error\n", 6);
	exit(EXIT_FAILURE);
}

int		main(int ac, char **av)
{
	int		fd;
	int		ret;
	int		nbpiece;
	int		**tablo;
	char	buf[BUF_SIZE + 1];

	tablo = NULL;
	if (ac == 2 && av[1])
	{
		fd = open(av[1], O_RDONLY);
		ret = read(fd, buf, BUF_SIZE);
		nbpiece = checkall(buf);
		if (nbpiece != 0 && nbpiece < 27 && ((ret + 1) % 21) == 0)
			tablo = yoloswag(buf, nbpiece);
		else
			ft_pute_error();
		if (tablo)
			weshwesh(tablo, nbpiece);
		close(fd);
		free(tablo);
	}
	else
		ft_pute_error();
	return (0);
}
