/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostapch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:03:48 by rostapch          #+#    #+#             */
/*   Updated: 2017/01/17 17:03:52 by rostapch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		ft_split(char *buffs, char **line)
{
	char	*temp;
	char	*pt;

	pt = ft_strchr(buffs, '\n');
	if (pt)
	{
		temp = ft_strsub(buffs, 0, pt - buffs);
		*line = ft_strjoin(*line, temp);
		ft_strdel(&temp);
		temp = ft_strdup(pt + 1);
		ft_strclr(buffs);
		buffs = ft_strcat(buffs, temp);
		ft_strdel(&temp);
		return (1);
	}
	else
	{
		*line = ft_strjoin(*line, buffs);
		ft_strclr(buffs);
		return (0);
	}
}

int		ft_init(char *buffs[4096])
{
	int i;

	i = -1;
	while (++i < 4096)
	{
		if (!buffs[i])
			buffs[i] = ft_strnew(BUFF_SIZE);
		if (!buffs[i])
			return (0);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*buffs[4096];
	int				ret;

	if (!ft_init(buffs) || !(fd >= 0 && fd < 4096) || !(line))
		return (-1);
	if (!(*line = ft_strnew(0)))
		return (-1);
	ret = 1;
	while (ret > 0)
	{
		ft_strlen(buffs[fd]) == 0 ? ret = read(fd, buffs[fd], BUFF_SIZE) : 0;
		if (ret >= 0 && ft_split(buffs[fd], line))
			break ;
	}
	if (ret == -1)
	{
		ft_strdel(line);
		return (ret);
	}
	if (ret > 0)
		return (1);
	return (ft_strlen(*line) == 0 ? 0 : 1);
}
