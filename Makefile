all:
	make -C libft -f Makefile
	cc -o fdf *.c -lmlx -framework OpenGL -framework AppKit -L libft -l ft -I . -I libft