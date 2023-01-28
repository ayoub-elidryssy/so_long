OBJ = mandatory/mand_so_long.o touls.o split.o mandatory/check_map1.o get_next_line.o get_next_line_utils.o\
mandatory/check_map2.o mandatory/imge_to_win.o mandatory/imge_touls.o\

BONUS_OBJ = so_long.o touls.o split.o check_map1.o get_next_line.o get_next_line_utils.o check_map2.o\
imge_to_win.o animation1.o imge_touls.o animation2.o\

NAME = so_long

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(MLX_FLAGS) $(OBJ) -o $(NAME)

bonus : $(BONUS_OBJ)
	touch bonus
	$(CC) $(MLX_FLAGS) $(BONUS_OBJ) -o $(NAME)

clean :
	rm -f $(OBJ) $(BONUS_OBJ)

fclean : clean
	rm -f $(NAME) bonus

re : fclean all

.PHONY: clean