/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostapch <rostapch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 18:29:19 by rostapch          #+#    #+#             */
/*   Updated: 2017/04/02 19:49:45 by rostapch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_window(int init, void **mlx, void **wnd)
{
	static	window window1;

	if (init > 0)
	{
		window1.mlx = *mlx;
		window1.wnd = *wnd;
	}
	else
	{
		*mlx = window1.mlx ;
		*wnd = window1.wnd;
	}
}

void	get_size(int size[2], int init)
{
	static int	sz[2];

	if (init > 0 && size[0] >= 1 && size[1] >= 1)
	{
		sz[0] = size[0];
		sz[1] = size[1];
	}
	else
	{
		size[0] = sz[0];
		size[1] = sz[1];
	}
}

int		get_projection(char *projection, int init)
{
	static int prj;


	if (projection && ft_strcmp(projection, "cabinet") == 0 && init == 1)
		prj = 0;
	else if (projection && ft_strcmp(projection, "iso") == 0 && init == 1)
		prj = 1;
	return (prj);
}

void	copy_array(double ***dst, double **src, int xy[2])
{
	int		i;
	int		j;

	(*dst) = (double **)malloc(sizeof(double *) * xy[1]);
	i = -1;
	while (++i < xy[1])
		(*dst)[i] = (double *)malloc(sizeof(double) * xy[0]);
	i = -1;
	while (++i < xy[1])
	{
		j = -1;
		while (++j < xy[0])
			(*dst)[i][j] = src[i][j];
	}
}

double	**get_tab(double **z, int xy[2], int projection, int init)
{
	static	data tab;

	if (init > 0)
	{
		tab.z = z;
		tab.xy[0] = xy[0];
		tab.xy[1] = xy[1];
		tab.projection = projection;
	}
	else
	{
		xy[0] = tab.xy[0];
		xy[1] = tab.xy[1];
		copy_array(&z, tab.z, tab.xy);
		projection = tab.projection;
	}
	return (z);
}
