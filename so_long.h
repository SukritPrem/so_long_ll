/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spipitku <spipitku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:35:42 by spipitku          #+#    #+#             */
/*   Updated: 2023/11/24 08:34:16 by spipitku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define KEY_A 0
# define KEY_MASK 0
# define KEY_EVENT 2
# define KEY_EXIT 17
# define KEY_D 2

# define MALLOC_ERROR_LIST_BACK 0
# define MALLOC_ERROR_PIC 1
# define MALLOC_ERROR_IMG 2

# define FIRST_CREATE 0
# define SECOND_CREATE 1

# define ERROR_OPEN_FILE 0
# define ERROR_MALLOC_LISTLINE 1
# define ERROR_NULL_STRING 2
# define ERROR_MALLOC_HEAD_LISTLINE 3

# define ERROR_CREATE_HEAD_LIST_WALL 0
# define ERROR_CREATE_CLONE_LIST_WALL 1

# define ERROR_MALLOC_MAP 0
# define ERROR_MALLOC_SUP_MAP 1
# define ERROR_MALLOC_MAP_I 2
# define KEY_S				1
# define KEY_W				13
# define KEY_ESC			53

# include "../minilibx_opengl_20191021/mlx.h"
# include "./libft/include/get_next_line.h"
# include "./libft/libft.h"
# include <unistd.h>

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_update_player
{
	int	x;
	int	y;
	int	i;
	int	j;
}	t_update_player;

typedef struct s_init_map
{
	char	**map;
	int		i;
	int		j;
}	t_init_map;

typedef struct s_line
{
	int				length_str;
	char			*line;
	struct s_line	*next;
}	t_line;

typedef struct s_list_line
{
	t_line	*head;
	t_line	*current;
	t_line	*clone;
	int		member_in_list;
}	t_list_line;

typedef struct s_map
{
	char			type;
	int				pos_x;
	int				pos_y;
	struct s_img	*picture;
	struct s_map	*next;
}	t_map;

typedef struct s_player
{
	t_map	*head;
	int		item;
	int		store_all_move;
	int		pos_i_x;
	int		pos_i_y;
	int		up;
	int		down;
	char	type;
	int		left;
	int		right;
}	t_player;

typedef struct s_list_map
{
	t_map	*head;
	t_map	*current;
	t_map	*clone;
}	t_list_map;

typedef struct s_update_item
{
	int	i;
	int	px;
	int	py;
	int	left;
	int	right;
	int	up;
	int	down;
	int	i_x;
	int	i_y;
}	t_update_item;
//typedef struct s_exit not use for real need improve after movement
typedef struct s_exit
{
	int		exit;
	t_map	*head;
}	t_exit;

typedef struct s_list_item
{
	t_map	**item;
	int		count_all_item;
	int		index;
}	t_list_item;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	int		width;
	int		height;
}	t_mlx;

typedef struct s_help_create
{
	int	i;
	int	j;
	int	width;
	int	height;
	int	width_max;
}	t_help_create;

typedef struct s_arg
{
	t_list_map	list_background;
	t_mlx		board_mlx;
	t_list_map	list_wall;
	t_player	player;
	t_list_item	item;
	t_exit		exit;
	t_list_line	*list_line;
	int			width_map;
	int			height_map;
	char		**map;
	char		**map_copy;
	char		**map_copy_2;
	int			i_x;
	int			i_y;
	int			have_dif_char;
	int			count_all_item;
	int			count_player;
	int			count_all_exit;
	int			count_map;
	int			count_item;
	int			count_exit;
}	t_arg;

typedef struct s_data
{
	t_player	*list_player;
	char		**map;
	t_list_map	*list_background;
	t_list_map	*list_wall;
	t_list_item	*list_item;
	t_exit		*list_exit;
	t_mlx		*board_mlx;
}	t_data;

// check_rectangular.c
void	check_rectangular(t_list_line *list_line);
// create_img.c
t_map	*create_list_background(int pos_x, int pos_y, char type, void *mlx);
void	*create_img_and_get_w_and_h(void *mlx, char type, int *w, int *h);
void	create_img_player(t_data *data);
t_map	*error_malloc(t_list_map *list_background, int error_case);
// free_all.c
void	free_list_line(t_list_line *list_line);
void	free_map(char ***map_main);
void	free_list_background(t_list_map *list_background, t_mlx *board_mlx);
void	free_player(t_player *player, t_mlx *board_mlx);
void	free_item(t_list_item *list_item, t_mlx *board_mlx);
// free_all_1.c
void	free_exit(t_exit *player, t_mlx *board_mlx);
// init_arg_init_data.c
void	init_data(t_data *data, t_arg *arg);
void	init_arg(t_arg *arg, t_list_line *list_line);
void	reset_value(t_arg *arg);
// init_item.c
void	init_item_1(t_arg *arg);
void	init_item(t_arg *arg);
// init_list_background_and_board_mlx.c
void	init_list_background_and_board_mlx(t_arg *arg);
void	init_board_mlx(t_arg *arg);
void	set_zero_help_create(t_help_create *help_create);
void	create_node_list_back_first(t_arg *arg, t_help_create *help_create);
void	create_node_list_back_second(t_arg *arg, t_help_create *help_create);
// init_list_background_and_board_mlx_1.c
void	init_board_mlx_win(t_arg *arg, t_help_create *help_create);

// init_list_line.c
void	init_list_line(char **argv, t_list_line *list_line);
void	error_in_list_line(int fd, t_list_line *list_line, int case_error);
void	count_str_list_head(t_list_line *list_line);
void	count_str_list_clone_head(t_list_line *list_line);
void	create_list_head(int fd, t_list_line *list_line, char **argv);
// init_list_line_1.c
void	check_ber_file(char *file_name);
// init_list_wall.c
void	init_list_wall(t_arg *arg);
void	error_create_list_wall(t_arg *arg, int case_error);
void	create_head_list_wall(t_arg *arg);
void	create_clone_list_wall(t_arg *arg);
// init_map.c
char	**init_map(t_list_line *list_line, t_arg *arg);
void	error_create_map(t_list_line *list_line, t_arg *arg, \
				int error_case, char ***map);
void	set_arg(char **map, t_arg *arg, int i, int j);
void	set_arg_w_h(char **map, int i, t_list_line *list_line, t_arg *arg);
void	set_plus_i_and_next_node(t_init_map *data, t_list_line *list_line);
// init_player.c
void	init_player(t_arg *arg);
void	create_head_list_player(t_arg *arg, int i, int j);
void	create_list_head_exit(t_arg *arg);
// key_press.c
int		key_press(int keycode, t_data *data);
void	press_w(t_data *data);
void	press_s(t_data *data);
void	press_esc(t_data *data);
// key_press_1.c
int		key_press_exit(t_data *data);
void	press_a(t_data *data);
void	press_d(t_data *data);
// main.c
void	flood_fill_check_map(t_arg *arg, int y, int x);
void	flood_fill_check_map_pec(t_arg *arg, int y, int x);
void	check_all_character(t_arg *arg);
void	check_player_find_c_e(t_arg *arg);
// render_all.c
void	render_wall(t_data *data);
void	render_background(t_data *data);
void	render_item(t_data *data);
void	render_player(t_data *data);
void	render_exit(t_data *data);
int		render(t_data *data);
// set_key_zero.c
void	set_keypress_to_left(t_data *data);
void	set_keypress_to_right(t_data *data);
void	set_keypress_to_up(t_data *data);
void	set_keypress_to_down(t_data *data);
// update_item.c
void	set_data_update_item(t_update_item *data_i, t_data *data);
void	conditon_update_item(t_update_item *d_i, t_data *data);
void	update_item(t_data *data);
// update_item_1.c
void	update_item_left(t_data *data, int i);
void	update_item_right(t_data *data, int i);
void	update_item_up(t_data *data, int i);
void	update_item_down(t_data *data, int i);
// update_player.c
void	update_player(t_data *data, int condition_left_right, \
				int condition_up_down);
#endif
