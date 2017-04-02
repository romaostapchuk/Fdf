/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostapch <rostapch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:22:46 by rostapch          #+#    #+#             */
/*   Updated: 2017/04/02 19:49:47 by rostapch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	resize(int zoom)
{
	int		size[2];
	double	**z;
	int		xy[2];
	int		prj;

	get_size(size, 0);
	if (zoom == 1)
	{
		size[0] *= 2;
		size[1] *= 2;
		get_size(size, 1);
		z = get_tab(z, xy, prj, 0);
		tab_3d_2d(z, xy, get_projection(NULL, 0), size);
	}
	if (zoom == -1)
	{
		size[0] /= 2;
		size[1] /= 2;
		get_size(size, 1);
		z = get_tab(z, xy, prj, 0);
		tab_3d_2d(z, xy, get_projection(NULL, 0), size);
	}
}

int		key_press(int key)
{
	void	*mw[2];

	get_window(0, &mw[0], &mw[1]);
	if (key == 69)
	{
		mlx_clear_window(mw[0], mw[1]);
		resize(1);
	}
	if (key == 78)
	{
		mlx_clear_window(mw[0], mw[1]);
		resize(-1);
	}
	if (key == 53)
		exit(0);
	return (0);
}

void	progr(int argc, char **argv)
{
	int		size[2];
	int		xy[2];
	double	**z;

	size[0] = 10;
	size[1] = 1;
	if (argc == 5)
	{
		size[0] = ft_atoi(argv[3]) > 0 ? ft_atoi(argv[3]): 10;
		size[1] = ft_atoi(argv[4]) > 0 ? ft_atoi(argv[4]): 1;
	}
	get_size(size, 1);
	if (argc >= 3)
		z = read_file(argv[1], argv[2], xy);
	else
		error_exit(3);
	get_tab(z, xy, get_projection(argv[2], 1), 1);
	tab_3d_2d(z, xy, get_projection(NULL, 0), size);
}

int		main(int argc, char **argv)
{
	void	*mlx;
	void	*wnd;
	int		size[2];

	mlx = mlx_init();
	wnd = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Fdf");
	get_window(1, &mlx, &wnd);
	progr(argc, argv);
	mlx_key_hook(wnd, key_press, mlx);
	mlx_loop(mlx);
}
