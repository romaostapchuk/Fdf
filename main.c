/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostapch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:22:46 by rostapch          #+#    #+#             */
/*   Updated: 2017/03/15 14:22:49 by rostapch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_window(int init, void **mlx, void **wnd)
{
	static	Window window1;

	if (init > 0)
	{
		window1.mlx = *mlx;
		window1.wnd = *wnd;
	}
	else
	{
		*mlx = window1.mlx ;
		*wnd = window1.wnd;
	}
}

int		key_press(int key)
{
	if (key == 53)
		exit(0);
	return (0);
}

int		main(int argc, char **argv)
{
	void	*mlx;
	void	*wnd;

	mlx = mlx_init();
	wnd = mlx_new_window(mlx, 2 * WINDOW_WIDTH, 2 * WINDOW_HEIGHT, "Fdf");
	get_window(1, &mlx, &wnd);
	if (read_file(argv[1], argv[2]) < 0)
		return (-1);
	mlx_key_hook(wnd, key_press, mlx);
	mlx_loop(mlx);
}
