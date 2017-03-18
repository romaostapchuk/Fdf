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

void	matrix_vector3(double xyz[4], double **mtrx)
{
	int		i;
	int		j;
	double	ret[4];

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			ret[i] += mtrx[i][j] * xyz[j];
		}
	}
	xyz[0] = ret[0] / ret[3];
	xyz[1] = ret[1] / ret[3];
}

void	init_xy(double ****xy, int x, int y)
{
	int i;
	int j;

	(*xy) = (double ***)malloc(sizeof(double **) * y);
	i = -1;
	while (++i < y)
	{
    	(*xy)[i] = (double **)malloc(sizeof(double *) * x);
    	j = -1;
    	while (++j < x)
    		(*xy)[i][j] = (double *)malloc(sizeof(double) * 2);
	}
}

void	tab_3d_2d(double **tab, int x, int y, int projection)
{
	double	***xy;
	double	xyz[4];
	int		i;
	int		j;
	
	init_xy(&xy, x, y);
	i = -1;
	while (++i < y)
	{
		j = -1;
		while (++j < x)
		{
			xyz[0] = j * 10;
			xyz[1] = i * 10;
			xyz[2] = tab[i][j];
			xyz[3] = 1;
			malloc(0);
			matrix_vector3(xyz, matrix(projection));
			xy[i][j][0] = xyz[0] + WINDOW_WIDTH;
			xy[i][j][1] = xyz[1] + WINDOW_HEIGHT;
		}
	}
	draw_field(xy, x, y);
}
