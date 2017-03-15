/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostapch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:21:13 by rostapch          #+#    #+#             */
/*   Updated: 2017/03/15 14:21:15 by rostapch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fill(char *str, int *tab_row)
{
	char **arr;
	int i;
	int j;

	i = -1;
	j = -1;
	arr = ft_strsplit(str, ' ');
	while (arr[++i])
		if (ft_strlen(arr[i]) > 0)
			tab_row[++j] = ft_atoi(arr[i]);
}

void	ft_fill_int_tab(int x, int y, int fd, char *file)
{
	char	*line;
	int		z[y][x];
	int		i;

	fd = open(file, O_RDONLY);
	i = 0;
	while (ft_get_next_line(fd, &line) > 0)
	{
		ft_fill(line, z[i]);
		i++;
	}
	Tab_3d_2d(z, x, y);
}

int		ft_words(char *str)
{
	int i;
	int wrd;

	i = 0;
	wrd = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] > 32 && str[i + 1] <= 32)
			wrd++;
		i++;
	}
	return (wrd);
}

int		ReadFile(char *file)
{
	int		fd;
	char	*line;
	int		y;
	int		x;

	y = 0;
	x = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (-1);
	}
	while (ft_get_next_line(fd, &line) > 0)
	{
		x = fmax(x, ft_words(line));
		y++;
	}
	ft_fill_int_tab(x, y, fd, file);
	close(fd);
	return (0);
}
