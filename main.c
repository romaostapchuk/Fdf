#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

int	KeyPress(int key)
{
	if (key == 53)
		exit(0);
	return (0);
}

int		main(void)
{
	void *mlx;
	void *wnd;

	mlx = mlx_init();
	wnd = mlx_new_window(mlx, 400, 400, "mlx 42");
	mlx_pixel_put(mlx, wnd, 1, 1, 0x00FFFFFF);

	mlx_key_hook(wnd, KeyPress, mlx);
	mlx_loop(mlx);
}