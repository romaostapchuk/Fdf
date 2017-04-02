/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostapch <rostapch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 13:07:19 by rostapch          #+#    #+#             */
/*   Updated: 2017/04/02 18:07:43 by rostapch         ###   ########.fr       */
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
    Izometric[0][0] = 0.707;
    Izometric[0][1] = -0.707;
    Izometric[0][2] = 0;
    Izometric[0][3] = 0;
    Izometric[1][0] = 0.409;
    Izometric[1][1] = 0.409;
    Izometric[1][2] = -0.816;
    Izometric[1][3] = 0;
    Izometric[2][0] = 0.577;
    Izometric[2][1] = 0.577;
    Izometric[2][2] = 0.578;
    Izometric[2][3] = 0;
    Izometric[3][0] = 0;
    Izometric[3][1] = 0;
    Izometric[3][2] = 0;
    Izometric[3][3] = 1;
    return (Izometric);
}

double	**matrix(int mtrx)
{
	if (mtrx == 0)
		return (cabinet());
	else 
		return (izometric());
}
