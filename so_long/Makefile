OBJ = main.o touls.o split.o chek_map.o get_next_line.o get_next_line_utils.o flod_fill.o\
imge_to_win.o animation.o imge_touls.o animation_touls.o\

NAME = so_long

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(MLX_FLAGS) $(OBJ) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: clean