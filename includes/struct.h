/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:15:37 by mapierre          #+#    #+#             */
/*   Updated: 2024/07/12 16:06:51 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_data_map
{
	char			*north_texture;
	char			*south_texture;
	char			*west_texture;
	char			*east_texture;
	unsigned int	ceiling_color;
	unsigned int	floor_color;
	int				is_north_set;
	int				is_south_set;
	int				is_west_set;
	int				is_east_set;
	int				is_ceiling_set;
	int				is_floor_set;
	int				count_elements;
	char			**map;
	int				map_width;
	int				map_height;
	int				map_start;
	char			player_direction;
	int				fd;
	int				countline;
}					t_data_map;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_length;
	int		endian;
}			t_texture;

typedef struct t_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

typedef struct s_key
{
	int	s;
	int	w;
	int	d;
	int	a;
	int	esc;
	int	l_arrow;
	int	r_arrow;
}			t_key;

typedef struct s_raycast
{
	double	cam_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_x;
	double	side_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_disst;
	int		step_x;
	int		step_y;
}				t_raycast;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_data
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		move_speed;
	double		rot_speed;
	char		**game_map;
	int			map_width;
	int			map_height;
	char		player_start_dir;
	t_key		keys;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			tex_x;
	int			ds;
	void		*mlx;
	void		*win;
	t_data_map	*map;
	t_raycast	raycast_var;
	t_texture	s_tex[4];
	int			*bufftext[4];
}				t_data;

#endif
