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

int		min_of_2(double a, double b)
{
	if (a <= b)
		return (0);
	return (1);
}

void	draw_line(double *xy1, double *xy2, void *mlx, void *wnd)
{
	int	x;
	int	y;

	y = fmin(xy1[1], xy2[1]);
	x = fmin(xy1[0], xy2[0]);
	if (fabs(xy2[0] - xy1[0]) >= fabs(xy2[1] - xy1[1]))
	{
		y = min_of_2(xy1[0], xy2[0]) == 0 ? xy1[1] : xy2[1];
		while (x <= fmax(xy2[0], xy1[0]))
		{
			mlx_pixel_put(mlx, wnd, x, y, 0x00FFFFFF);
			y = (xy2[1] - xy1[1]) / (xy2[0] - xy1[0]) * (x - xy1[0]) + xy1[1];
			x++;
		}
	}
	else
	{
		x = min_of_2(xy1[1], xy2[1]) == 0 ? xy1[0] : xy2[0];
		while (y <= fmax(xy2[1], xy1[1]))
		{
			mlx_pixel_put(mlx, wnd, x, y, 0x00FFFFFF);
			x = (xy2[0] - xy1[0]) / (xy2[1] - xy1[1]) * (y - xy1[1]) + xy1[0];
			y++;
		}
	}
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
		}
	}
}
