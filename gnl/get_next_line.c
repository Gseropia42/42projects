/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gseropia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 15:37:49 by gseropia          #+#    #+#             */
/*   Updated: 2015/12/17 16:32:05 by gseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char *ft_pimp_my_buffer(const char *buffer, char *ret)
{
	char *temp;

	temp = ft_strdup(ret);
	if (temp)
	{
		free(ret);
		ret = ft_strjoin(temp, buffer);
		free(temp);
	}
	return (ret);
}
char **bimlestock(char **stock, int fd)
{
	char *buf;
	char *finalbuf;
	int ret;
	
	ret = 0;
	finalbuf = NULL;
	buf = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
//		ft_putnbr(ret);
		buf[ret] = '\0';
		if (!buf)
			return (NULL);
		if (!finalbuf)
		{
			finalbuf = ft_strdup(buf);
//			ft_putstr(buf);
	
		}
		else
		{
			finalbuf = ft_pimp_my_buffer(buf, finalbuf);
	//		ft_putendl(finalbuf);
		}
	}
	free(buf);
	stock = ft_specialsplit(finalbuf, '\n');
	if (!stock)
		return(NULL);
//		ft_putendl("trololol");
	if (finalbuf)
		free(finalbuf);
	return (stock);
}	

int get_next_line(int const fd, char **line)
{
	static char **stock;
	static int index;

	if (fd < 0 || !line)
		return (-1);
	if (!stock)
	{
		index = 0;
		stock = bimlestock(stock, fd);
		if (!stock)
			return (-1);
	//	ft_putendl("coucou");
	}
	if (stock[index])
	{
		*line = stock[index];
		index++;
	//	ft_putendl("par la");
		return (1);
	}
	else 
		*line = *stock;
		free(stock);
		stock = NULL;
		return (0);
}

int main(int agc, char **argv)
{
	char *line;
	line = NULL;
	if (agc != 2)
		ft_putstr("lol tocard");
	int fd;
	int i;
	i= 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_putstr("lol tocard");
	while ((i = get_next_line((int const)fd, &line)) > 0)
	{
		ft_putendl(line);
		free(line);
	}
	close(fd);
	return (0);
}
