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

int		KeyPress(int key)
{
	if (key == 53)
		exit(0);
	return (0);
}

int		main(int argc, char **argv)
{
	void	*mlx;
	void	*wnd;

	if (ReadFile(argv[1]) < 0)
		return (-1);
	mlx = mlx_init();
	wnd = mlx_new_window(mlx, 500, 500, "Fdf");
	mlx_key_hook(wnd, KeyPress, mlx);
	mlx_loop(mlx);
}
