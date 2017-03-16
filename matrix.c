/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostapch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 13:07:19 by rostapch          #+#    #+#             */
/*   Updated: 2017/03/16 13:07:20 by rostapch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	**cabinet(void)
{
    double	**Cabinet;

    Cabinet = (double **)malloc(sizeof(double *) * 4);
    Cabinet[0] = (double *)malloc(sizeof(double) * 4);
    Cabinet[1] = (double *)malloc(sizeof(double) * 4);
    Cabinet[2] = (double *)malloc(sizeof(double) * 4);
    Cabinet[3] = (double *)malloc(sizeof(double) * 4);
    Cabinet[0][0] = 1;
    Cabinet[0][1] = 0;
    Cabinet[0][2] = 0.5;
    Cabinet[0][3] = 0;
    Cabinet[1][0] = 0;
    Cabinet[1][1] = 1;
    Cabinet[1][2] = 0.5;
    Cabinet[1][3] = 0;
    Cabinet[2][0] = 0;
    Cabinet[2][1] = 0;
    Cabinet[2][2] = 0;
    Cabinet[2][3] = 0;
    Cabinet[3][0] = 0;
    Cabinet[3][1] = 0;
    Cabinet[3][2] = 0;
    Cabinet[3][3] = 1;
    return (Cabinet);
}

double	**izometric(void)
{
    double	**Izometric;

    Izometric = (double **)malloc(sizeof(double *) * 4);
    Izometric[0] = (double *)malloc(sizeof(double) * 4);
    Izometric[1] = (double *)malloc(sizeof(double) * 4);
    Izometric[2] = (double *)malloc(sizeof(double) * 4);
    Izometric[3] = (double *)malloc(sizeof(double) * 4);
    Izometric[0][0] = cos(40 * M_PI / 180);
    Izometric[0][1] = sin(25 * M_PI / 180) * cos(25 * M_PI / 180);
    Izometric[0][2] = 0;
    Izometric[0][3] = 0;
    Izometric[1][0] = 0;
    Izometric[1][1] = cos(25 * M_PI / 180);
    Izometric[1][2] = 0;
    Izometric[1][3] = 0;
    Izometric[2][0] = sin(40 * M_PI / 180);
    Izometric[2][1] = - sin(25 * M_PI / 180) * cos(40 * M_PI / 180);
    Izometric[2][2] = 0;
    Izometric[2][3] = 0;
    Izometric[3][0] = 0;
    Izometric[3][1] = 0;
    Izometric[3][2] = 0;
    Izometric[3][3] = 1;
    return (Izometric);
}

double	**matrix(int mtrx)
{
	if (mtrx == 1)
		return (cabinet());
	else 
		return (izometric());
}
