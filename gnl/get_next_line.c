/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 16:27:49 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/07 16:21:43 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_pimp_my_stock(char *buf, char *stock)
{
	char *temp;

	temp = NULL;
	if (!stock)
		return (ft_strdup(buf));
	temp = ft_strdup(stock);
	free(stock);
	stock = ft_strjoin(temp, buf);
	free(temp);
	return (stock);
}

char	*newstock(char *stock, char **line)
{
	char *temp;

	temp = ft_strdup(stock);
	free(stock);
	*line = ft_strsub(temp, 0, ft_return_pos(temp, '\n'));
	stock = ft_strsub(temp, (ft_return_pos(temp, '\n') + 1), \
			(ft_strlen(temp) - ft_return_pos(temp, '\n') - 1));
	free(temp);
	return (stock);
}

int		read_my_file(int const fd, char **stock, char **line)
{
	int		ret;
	char	*buf;

	ret = 0;
	buf = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		*stock = ft_pimp_my_stock(buf, *stock);
		if (ft_return_pos(*stock, '\n') >= 0)
		{
			*stock = newstock(*stock, line);
			return (1);
		}
	}
	free(buf);
	return (ret);
}

char	*stockfree(char **stock, char **line)
{
	*line = ft_strdup(*stock);
	free(*stock);
	*stock = NULL;
	return (*stock);
}

int		get_next_line(int const fd, char **line)
{
	int			ret;
	static char *stock = NULL;

	if (!line || fd < 0)
		return (-1);
	if (stock && ft_strlen(stock) && ft_return_pos(stock, '\n') >= 0)
	{
		stock = newstock(stock, line);
		return (1);
	}
	if ((ret = read_my_file(fd, &stock, line)) == 1)
		return (1);
	if (ret == -1)
		return (-1);
	if (stock && ft_strlen(stock))
	{
		if (ft_return_pos(stock, '\n') < 0)
			stock = stockfree(&stock, line);
		else
			stock = newstock(stock, line);
		return (1);
	}
	return (0);
}
