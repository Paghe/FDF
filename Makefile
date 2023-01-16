FLAGS = -fsanitize=address -g -Wall -Wextra -Werror

NAME = fdf
SRC = main.c \
		get_next_line.c \
		get_next_line_utils.c \
		src/read_map.c \
		src/draw_lines.c \
		src/utils.c \
		src/projection.c \

OBJ = 	$(SRC:.c=.o)
LIBFT = ./libft/libft.a
all: $(NAME)

%.o: %.c
	gcc $(FLAGS) -c $^ -o $@

$(NAME): $(OBJ) fdf.h
	make -C libft
	cc $(LINKFLAGS) $(OBJ) $(LIBFT) $(FLAGS) MLX42/libmlx42.a MLX42/libglfw3.a -framework Cocoa -framework OpenGL -framework IOKit -o $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C libft
fclean:
	make clean
	rm -f $(NAME)

re: fclean all