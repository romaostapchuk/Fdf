all:
	cc -o fdf main.c drawline.c readfile.c -lmlx -framework OpenGL -framework AppKit -L libft -l ft -I . -I libft