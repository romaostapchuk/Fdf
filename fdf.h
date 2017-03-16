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
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

# define WINDOW_WIDTH 500
# define WINDOW_HEIGHT 500

typedef struct	window
{
	void		*mlx;
	void		*wnd;
}				Window;

double	**matrix(int mtrx);
void	draw_line(double *xy1, double *xy2, void *mlx, void *wnd);
int		read_file(char *file, char *projection);
void	tab_3d_2d(double **tab, int x, int y, int projection);
void	error_exit(int err);
void	get_window(int init, void **mlx, void **wnd);
void	draw_field(double ***tab, int x, int y);
