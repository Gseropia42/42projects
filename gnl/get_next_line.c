/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 16:27:49 by gseropia          #+#    #+#             */
/*   Updated: 2016/01/06 19:26:16 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_is_bsn(char *buf)
{
	int i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
char * ft_pimp_my_stock(char *buf, char *stock)
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
/*char *newstock(char *stock, char *line)
{
	char *temp;

	temp = ft_strdup(stock);
	free(stock);
	stock = ft_strsub(temp, (ft_is_bsn(temp) + 1), (ft_strlen(temp) - ft_is_bsn(temp) - 1));
*/
int get_next_line(int const fd, char **line)
{
	char *buf;
	int ret;
	static char *stock = NULL;

	buf = ft_strnew(BUFF_SIZE);
	if (!line || fd < 0)
		return (-1);
	if (stock && (ft_strlen(stock) > 0))
		if (ft_is_bsn(stock) >= 0)
		{
			*line = ft_strsub(stock, 0 , ft_is_bsn(stock));
			stock = ft_strsub(stock, (ft_is_bsn(stock) + 1), (ft_strlen(stock) - ft_is_bsn(stock) - 1));
			return (1);
		}
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		stock = ft_pimp_my_stock(buf, stock);
		if (ft_is_bsn(stock) >= 0)
		{
			*line = ft_strsub(stock, 0 , ft_is_bsn(stock));
			stock = ft_strsub(stock, (ft_is_bsn(stock) + 1), (ft_strlen(stock) - ft_is_bsn(stock) - 1));
			return (1);
		}
	}
	if (ret == -1)
		return (-1);
	if (ret == 0 && ft_strlen(stock))
	{
		*line = ft_strsub(stock, 0 , ft_is_bsn(stock));
		stock = ft_strsub(stock, (ft_is_bsn(stock) + 1), (ft_strlen(stock) - ft_is_bsn(stock) - 1));
		return (1);
	}
	free(stock);
	stock = NULL;
	return (0);
}
