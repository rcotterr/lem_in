NAME = lem-in
MINILIB = minilibx_macos/libmlx.a
SOURCES = get_next_line.c check.c read_input.c read_input_help.c lem.c create.c free.c ways_length.c ant_ways.c chose_way.c plus_one.c jams.c making_steps.c
all: $(NAME)

$(NAME): $(SOURCES) main.c
	make -C libft/
	gcc $(SOURCES) main.c -Wall -Wextra -Werror -I. libft/libft.a -o $(NAME)
clean:
	make -C libft/ clean
	rm -f minilibx_macos/mlx_shaders.o minilibx_macos/mlx_new_window.o \
	minilibx_macos/mlx_init_loop.o minilibx_macos/mlx_new_image.o \
	minilibx_macos/mlx_xpm.o minilibx_macos/mlx_int_str_to_wordtab.o
fclean: clean
	rm -f $(NAME)
	make -C minilibx_macos/ clean
	make -C libft/ fclean
re: fclean all/
test: $(SOURCES) main.c print.c
	make -C libft/
	make -C minilibx_macos/
	gcc $(SOURCES) main.c print.c -g -Wall -Wextra -I. libft/libft.a -lmlx -framework OpenGL -framework AppKit -o $(NAME)
visual: $(SOURCES) visual.c window.c drawing.c
	make -C libft/
	make -C minilibx_macos/
	gcc $(SOURCES) visual.c window.c drawing.c -g -Wall -Wextra -I. libft/libft.a -lmlx -framework OpenGL -framework AppKit -o $(NAME)
norm:
	norminette main.c visual.c lemin.h $(SOURCES)