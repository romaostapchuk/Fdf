/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostapch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:22:22 by rostapch          #+#    #+#             */
/*   Updated: 2017/03/15 14:22:26 by rostapch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "math.h"
#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

void	DrawLine(double *xy1, double *xy2, void *mlx, void *wnd);
int		ReadFile(char *file);
