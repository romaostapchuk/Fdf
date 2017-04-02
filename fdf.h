/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostapch <rostapch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:22:22 by rostapch          #+#    #+#             */
/*   Updated: 2017/04/02 19:23:25 by rostapch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DFD_H_
# define _DFD_H_

#include "mlx.h"
#include "math.h"
#include "libft.h"
#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 1000

typedef struct	wndw
{
	void		*mlx;
	void		*wnd;
}				window;

typedef struct	dt
{
	double		**z;
	int			xy[2];
	int			projection;
}				data;

double	**matrix(int mtrx);
void	draw_line(double *xy1, double *xy2, void **mw, double *mm_z);
double	**read_file(char *file, char *projection, int xy[2]);
void	tab_3d_2d(double **tab, int *xy, int projection, int size[2]);
void	error_exit(int err);
void	get_window(int init, void **mlx, void **wnd);
void	draw_field(double ***tab, int x, int y);
int		min_of_2(double a, double b);
double	arr_max(double ***arr, int id, int x, int y);
double	arr_min(double ***arr, int id, int x, int y);
void	get_window(int init, void **mlx, void **wnd);
void	get_size(int size[2], int init);
int		get_projection(char *projection, int init);
double	**get_tab(double **Z, int xy[2], int projection, int init);
#endif
