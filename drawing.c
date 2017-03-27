/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostapch <rostapch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 16:44:35 by rostapch          #+#    #+#             */
/*   Updated: 2017/03/27 20:40:48 by rostapch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	arr_max(double ***arr, int id, int x, int y)
{
	int		i;
	int		j;
	double	max;

	max = arr[0][0][id];
	i = -1;
	while (++i < y)
	{
		j = -1;
		while (++j < x)
		{
			max = fmax(max, arr[i][j][id]);
		}
	}
	return (max);
}

double	arr_min(double ***arr, int id, int x, int y)
{
	int		i;
	int		j;
	double	min;

	min = arr[0][0][id];
	i = -1;
	while (++i < y)
	{
		j = -1;
		while (++j < x)
		{
			min = fmin(min, arr[i][j][id]);
		}
	}
	return (min);
}

int		color(double *xyz1, double *xyz2, int xy[2], double *mm_z)
{
	double	zs;
	double	ze;
	double	zc;
	double	color;

	zs = fabs((xyz1[2] - mm_z[0]) / fmax(mm_z[1] - mm_z[0], 0.001));
	ze = fabs((xyz2[2] - mm_z[0]) / fmax(mm_z[1] - mm_z[0], 0.001));
	zc = fmax((fabs(xy[0] - xyz1[0]) + fabs(xy[1] - xyz1[1])) /
		fmax(fabs(xyz2[0] - xyz1[0]) + fabs(xyz2[1] - xyz1[1]), 0.001), 0);
	color = fabs((ze - zs) * zc) + fmin(zs, ze);
	if (color >= 0 && color < 0.25)
		return (ft_rgb(0, 255 * color * 4, 255));
	else if (color >= 0.25 && color < 0.5)
		return (ft_rgb(0, 255, 255 - 255 * (color - 0.25) * 4));
	else if (color >= 0.5 && color < 0.75)
		return (ft_rgb(255 * (color - 0.5), 255, 0));
	else if (color >= 0.75 && color <= 1)
		return (ft_rgb(255, 255 - 255 * (color - 0.75) * 4, 0));
	return (0);
}

void	draw_line(double *xy1, double *xy2, void *mlx, void *wnd, double *mm_z)
{
	int	p[2];

	p[1] = fmin(xy1[1], xy2[1]);
	p[0] = fmin(xy1[0], xy2[0]);
	if (fabs(xy2[0] - xy1[0]) >= fabs(xy2[1] - xy1[1]))
	{
		p[1] = min_of_2(xy1[0], xy2[0]) == 0 ? xy1[1] : xy2[1];
		while (p[0] <= fmax(xy2[0], xy1[0]))
		{
			mlx_pixel_put(mlx, wnd, p[0], p[1], color(xy1, xy2, p, mm_z));
			p[1] = (xy2[1] - xy1[1]) / (xy2[0] - xy1[0]) * (p[0] - xy1[0]) + xy1[1];
			p[0]++;
		}
	}
	else
	{
		p[0] = min_of_2(xy1[1], xy2[1]) == 0 ? xy1[0] : xy2[0];
		while (p[1] <= fmax(xy2[1], xy1[1]))
		{
			mlx_pixel_put(mlx, wnd, p[0], p[1], color(xy1, xy2, p, mm_z));
			p[0] = (xy2[0] - xy1[0]) / (xy2[1] - xy1[1]) * (p[1] - xy1[1]) + xy1[0];
			p[1]++;
		}
	}
}

void	draw_field(double ***tab, int x, int y)
{
	int		i;
	int		j;
	void	*mlx;
	void	*wnd;
	double	*mm_z;

	get_window(0, &mlx, &wnd);
	mm_z = (double*)malloc(sizeof(double) * 2);	
	mm_z[0] = arr_min(tab, 2, x, y);
	mm_z[1] = arr_max(tab, 2, x, y);
	i = -1;
	while (++i < y)
	{
		j = -1;
		while (++j < x)
		{
			if (i < y - 1)
				draw_line(tab[i][j], tab[i + 1][j], mlx, wnd, mm_z);
			if (j < x - 1)
				draw_line(tab[i][j], tab[i][j + 1], mlx, wnd, mm_z);
		}
	}
}
