

CFLAGS= -I$(INC) -O3 -I.. 

NAME = so_long

HEADERS_LIST = so_long.h

SRC =	init_list_background_and_board_mlx_1.c main.c free_all.c free_all_1.c check_rectangular.c \
		create_img.c init_item.c init_list_background_and_board_mlx.c init_list_line.c \
		init_list_wall.c init_map.c init_player.c key_press.c render_all.c set_key_zero.c update_item.c update_player.c\
		init_arg_init_data.c key_press_1.c update_item_1.c render_all_1.c init_list_line_1.c
	 
OBJ = $(SRC:%.c=%.o)

LFLAGS = -Lminilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit -o


all: $(NAME)

$(NAME): $(OBJ) $(HEADERS_LIST)
	$(MAKE) -C libft
	$(CC) $(OBJ) ./libft/libft.a $(LFLAGS) $(NAME)


clean:
	rm -f $(NAME) $(OBJ)

fclean: clean
	make fclean -C libft

re: fclean all

.PHONY: clean fclean all re
