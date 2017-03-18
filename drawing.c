/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostapch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 16:44:35 by rostapch          #+#    #+#             */
/*   Updated: 2017/03/16 16:44:40 by rostapch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(double *xy1, double *xy2, void *mlx, void *wnd)
{
	int x;
	int y;

	if (fabs(xy2[0] - xy1[0]) > fabs(xy2[1] - xy1[1]))
	{
		y = fmin(xy1[1], xy2[1]);
		x = fmin(xy1[0] - 1, xy2[0] - 1);
		while (++x <= fmax(xy2[0], xy1[0]))
		{
			mlx_pixel_put(mlx, wnd, x, y, 0x00FFFFFF);
			y = (xy2[1] - xy1[1]) / (xy2[0] - xy1[0]) * (x - xy1[0]) + xy1[1];
			//printf("<%d><%d>  _", x, y);
		}
	}
	else
	{
		y = fmin(xy1[1] - 1, xy2[1] - 1);
		x = fmin(xy1[0], xy2[0]);
		while (++y <= fmax(xy2[1], xy1[1]))
		{
			mlx_pixel_put(mlx, wnd, x, y, 0x00FFFFFF);
			x = (xy2[0] - xy1[0]) / (xy2[1] - xy1[1]) * (y - xy1[1]) + xy1[0];
			//printf("<%d><%d>  _", x, y);
		}
	}
			//printf("\n");
}

void	draw_field(double ***tab, int x, int y)
{
	int		i;
	int		j;
	void	*mlx;
	void	*wnd;

	get_window(0, &mlx, &wnd);
	i = -1;
	while (++i < y)
	{
		j = -1;
		while (++j < x)
		{
			if (i < y - 1)
				draw_line(tab[i][j], tab[i + 1][j], mlx, wnd);
			if (j < x - 1)
				draw_line(tab[i][j], tab[i][j + 1], mlx, wnd);
			else if (i == y - 1 && j == x - 1)
			{
				draw_line(tab[i][j], tab[i][j - 1], mlx, wnd);
				draw_line(tab[i][j], tab[i - 1][j], mlx, wnd);
			}
		}
	}
}
