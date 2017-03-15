all:
	cc -o mlx main.c -lmlx -framework OpenGL -framework AppKit -L libft -l ft -I . -I libft