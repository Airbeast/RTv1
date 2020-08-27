/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeast <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 20:16:40 by chbeast           #+#    #+#             */
/*   Updated: 2019/09/26 05:35:19 by chbeast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*rread(const int fd, char *frombuf)
{
	int		readed;
	char	buf[BUFF_SIZE + 1];
	char	*liberate1;

	if (fd < 0 || read(fd, buf, 0) < 0 || BUFF_SIZE < 1)
		return (0);
	if (frombuf == NULL)
		frombuf = ft_strnew(1);
	while (!(ft_strchr(frombuf, '\n')))
	{
		if ((readed = read(fd, buf, BUFF_SIZE)) < 0)
			return (0);
		buf[readed] = '\0';
		liberate1 = frombuf;
		frombuf = ft_strjoin(frombuf, buf);
		free(liberate1);
		if (frombuf[0] == '\0' || readed == 0)
			break ;
	}
	return (frombuf);
}

int		get_next_line(const int fd, char **line)
{
	static char	*frombuf[10240];
	char		*newline;
	char		*liberate;

	if (fd < 0 || !(frombuf[fd] = rread(fd, frombuf[fd])) || fd > 10240)
		return (-1);
	if ((newline = ft_strchr(frombuf[fd], '\n')) > 0)
	{
		if (!(*line = ft_strndup(frombuf[fd], newline - frombuf[fd])))
			return (-1);
		liberate = frombuf[fd];
		frombuf[fd] = ft_strdup(newline + 1);
		free(liberate);
		return (1);
	}
	else
	{
		if (!(*line = ft_strdup(frombuf[fd])))
			return (-1);
		free(frombuf[fd]);
		frombuf[fd] = NULL;
		if (*line[0] == '\0')
			return (0);
		return (1);
	}
}
