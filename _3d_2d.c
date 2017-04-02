/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _3d_2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostapch <rostapch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:21:21 by rostapch          #+#    #+#             */
/*   Updated: 2017/04/02 17:45:58 by rostapch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		min_of_2(double a, double b)
{
	if (a <= b)
		return (0);
	return (1);
}

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
    		(*xy)[i][j] = (double *)malloc(sizeof(double) * 3);
	}
}

void	tab_3d_2d(double **tab, int xy[2], int projection, int size[2])
{
	double	***xy_field;
	double	xyz[4];
	int		i;
	int		j;
	
	init_xy(&xy_field, xy[0], xy[1]);
	i = -1;
	while (++i < xy[1])
	{
		j = -1;
		while (++j < xy[0])
		{
			xyz[0] = j * size[0];
			xyz[1] = i * size[0];
			xyz[2] = tab[i][j] * size[1];
			xyz[3] = 1;
			malloc(0);
			matrix_vector3(xyz, matrix(projection));
			xy_field[i][j][0] = xyz[0];
			xy_field[i][j][1] = xyz[1];
			xy_field[i][j][2] = tab[i][j];
		}
	}
	draw_field(xy_field, xy[0], xy[1]);
}
