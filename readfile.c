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

void	ft_fill(char *str, double *tab_row)
{
	char	**arr;
	int		i;
	int		j;

	i = -1;
	j = -1;
	arr = ft_strsplit(str, ' ');
	while (arr[++i])
		if (ft_strlen(arr[i]) > 0)
			tab_row[++j] = ft_atoi(arr[i]);
}

void	ft_fill_int_tab(int *xy, int fd, char *file, int prj)
{
	char	*line;
	double	**z;
	int		i;

	z = (double **)malloc(sizeof(double *) * xy[1]);
	i = -1;
	while (++i < xy[1])
		z[i] = (double *)malloc(sizeof(double) * xy[0]);
	fd = open(file, O_RDONLY);
	i = 0;
	while (ft_get_next_line(fd, &line) > 0)
	{
		ft_fill(line, z[i]);
		i++;
	}
	tab_3d_2d(z, xy, prj);
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

int		read_file(char *file, char *projection)
{
	int		fd;
	char	*line;
	int		*xy;

	xy = (int*)malloc(sizeof(int) * 2);
	xy[1] = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_exit(-1);
	while (ft_get_next_line(fd, &line) > 0)
	{
		xy[0] = fmax(xy[0], ft_words(line));
		xy[1]++;
	}
	if (ft_strcmp(projection, "cabinet") == 0)
		ft_fill_int_tab(xy, fd, file, 1);
	else if (ft_strcmp(projection, "iso") == 0)
		ft_fill_int_tab(xy, fd, file, 2);
	else
		error_exit(2);
	close(fd);
	return (0);
}
