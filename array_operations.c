/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostapch <rostapch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 17:57:49 by rostapch          #+#    #+#             */
/*   Updated: 2017/04/01 17:58:34 by rostapch         ###   ########.fr       */
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
