/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostapch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:21:21 by rostapch          #+#    #+#             */
/*   Updated: 2017/03/15 14:21:22 by rostapch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		*MatrixVector3(int x, int y, int z, int **mtrx)
{
	int i;
	int j;
	int xyz[4];
	int ret[4]

	xyz = {x, y, z, 1};
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			ret[i] += mtrx[i][j] * xyz[j];
		}
	}
	return (ret);
}

void	Tab_3d_2d(int **tab, int x, int y)
{

}

void	DrawLine(double *xy1, double *xy2, void *mlx, void *wnd)
{
	double x;
	double y;

	if (fabs(xy2[0] - xy1[0]) > fabs(xy2[1] - xy1[1]))
	{
		y = fmin(xy1[1], xy2[1]);
		x = fmin(xy1[0] - 1, xy2[0] - 1);
		while (++x <= fmax(xy2[0], xy1[0]))
		{
			mlx_pixel_put(mlx, wnd, x, y, 0x00FFFFFF);
			y = (xy2[1] - xy1[1]) / (xy2[0] - xy1[0]) * (x - xy1[0]) + xy1[1];
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
		}
	}
}
