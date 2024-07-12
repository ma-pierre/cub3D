/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:07:03 by mapierre          #+#    #+#             */
/*   Updated: 2024/07/12 17:48:39 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <mlx_int.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "../mlx/mlx.h"
# include "struct.h"

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17
# define KEYPRESS	2
# define KEYRELEASE 3
# define SCREEN_W 1280
# define SCREEN_H 720
# define ERROR_ARGS "Error\nInvalid arguments."
# define INV_FILE_NOT_FOUND "Error\nFile not found."
# define INV_XPM_FILE_NOT_FOUND "Error\nXPM file not found."
# define INV_EXT "Error\nWrong extension's name."
# define INV_EXT_XPM "Error\nWrong extension's name(xpm)."
# define INVALID_POSITION "Error\nProblem with the player's position."
# define INVALID_EXIT "Error\nProblem with the exit."
# define INVALID_TEXT_COL "Error\nProblem with your textures or colors."
# define INV_UNDER_THE_MAP "Error\nSomething letf under the map."
# define MAP_NOT_CLOSED "Error\nMap border not closed here : [%d][%d]. \n"
# define ERROR_FILE_EMPTY "Error\nThe file is empty."
# define ERROR_MAP_EMPTY "Error\nThe map is empty."
# define INVALID_CHAR_MSG "Error\nInvalid character : at position [%d][%d]"
# define FAIL_INIT_STRUCT "Error\nInitialisation of the structure failed."

enum		e_scene_characters
{
	FREE_WAY = '0',
	WALL = '1',
	PLAYER_NORTH = 'N',
	PLAYER_SOUTH = 'S',
	PLAYER_EAST = 'E',
	PLAYER_WEST = 'W',
	SPACES = ' '
};

void			camera_left(t_data *d);
void			camera_right(t_data *d);
void			init_player_n_s(t_data *data);
void			init_player_direction(t_data *data);

//MOVE.c
void			move_forward(t_data *data);
void			move_back(t_data *data);
void			move_left(t_data *data);
void			move_right(t_data *data);

//HANDLE_KEY_PRESS
void			init_keys(t_data *data);
int				key_press(int keycode, t_data *data);
int				key_release(int keycode, t_data *data);
int				handle_keypress(t_data *data);

//RAYCASTING
void			main_raycast(t_data *data, t_image win_img);
void			raycast_init_var(t_data *data, int x);
void			raycast_init_raydir(t_data *data);
int				raycast_dda(t_data *data);
int				do_frame(t_data *data);
int				clean_game(t_data *data);
void			draw_c(t_image image, t_data *data, int x, int color);
void			draw_f(t_image image, t_data *data, int x, int color);
void			calc_draw(t_data *d);

//////////RAYCAST MAIN/////////////////
void			init_raycast_main(t_data *data);
void			init_raycast_all(t_data *data);
t_texture		*define_texture(t_data *d, int side);
double			calc_wall_intersection(t_data *d, int side, double wall_x);

/////////////TEXTURES////////////////
void			init_texture(t_data *data);
void			draw_wall(t_image image, t_data *data, int x, t_texture *tex);
t_image			image_new(void *mlx, size_t w, size_t h);
void			image_put_px(t_image img, int x, int y, int color);
void			image_delete(void *mlx, t_image img);

// MINIMAP 
void			display_minimap(t_data *data, t_image win_img, int y);
void			readtab(t_data *data);
void			draw_square(t_image img, int x, int y, int size);
void			draw_minimap_wall(t_image img, int x, int y, int size);
void			draw_minimap_floor(t_image img, int x, int y, int size);
int				parse_line(char *line, t_data_map *map);
int				check_data(char *filename, t_data_map *map);
int				check_xpm(char *str);

//PARSING
int				check_arg(int argc, char **argv);
int				check_cub(char *str);
int				check_elements(t_data_map *map);
int				check_walls(char **map);
int				check_map(char *filename, t_data_map *map);
int				check_top_border(char *map);
int				fill(char **copy, int x, int y);
void			get_player_directions(t_data_map *map, int *x, int *y);
char			**mapcopy(t_data_map *map);
int				checkflood(char **copy_map);
int				floodfill(t_data_map *map);
void			free_tab(char **tab);
void			ft_clean(t_data_map *map, int status);
int				count_comma(char *line);
void			handle_floor_colors(char *line, int i, t_data_map *map);
void			handle_ceiling_colors(char *line, int i, t_data_map *map);
void			handle_f_data(char *line, t_data_map *map, int i);
void			handle_c_data(char *line, t_data_map *map, int i);
void			handle_texture(char **texture, char *line, int i,
					t_data_map *map);
void			handle_no_texture(char *line, int i, t_data_map *map);
void			handle_so_texture(char *line, int i, t_data_map *map);
void			handle_we_texture(char *line, int i, t_data_map *map);
void			handle_ea_texture(char *line, int i, t_data_map *map);
void			handle_no_data(char *line, t_data_map *map, int i);
void			handle_so_data(char *line, t_data_map *map, int i);
void			handle_we_data(char *line, t_data_map *map, int i);
void			handle_ea_data(char *line, t_data_map *map, int i);
int				get_dimensions(char *filename, t_data_map *map);
int				store_map(char *filename, t_data_map *map);
int				is_white_space(char c);
int				is_player(char c);
int				is_digit(char c);
void			initialize_map(t_data_map *map);
void			start_parsing(char *filename, t_data_map *map);
int				is_valid_path(char *texture_path);
int				is_all_white_space(const char *str);
void			clean_end_white_space_lines(t_data_map *map);
char			*ft_strncpy(char *dst, char *src, int n);
int				next_is_space(char c);
int				check_empty_line(t_data_map *map);
void			turn_into_walls(t_data_map *map);
int				check_extension(char *str, char *extension);
int				open_file(char *filename, t_data_map *map);
int				process_file(t_data_map *map);
int				close_and_finalize(t_data_map *map);
int				handle_map_start(t_data_map *map);
int				handle_line_errors(char *line, t_data_map *map);
int				verify_border_and_cleanup(t_data_map *map, char *line);
void			get_rgb_values(char **c_v, int *rgb, char *line,
					t_data_map *map);
void			handle_error(char *line, t_data_map *map, char **c_v,
					char *str);
void			apply_color_to_rgb(int index, int *color, int *rgb);
void			tex_path_error(char *line, t_data_map *map, char *new_path);
void			skip_lines(int fd, int skip);
int				read_and_store_map(t_data_map *map, int line_index);

#endif
