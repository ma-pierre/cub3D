/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:31:17 by mapierre          #+#    #+#             */
/*   Updated: 2024/07/12 17:50:29 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	do_frame(t_data *data)
{
	t_image	win_img;

	if (data->keys.esc == 1)
		clean_game(data);
	win_img = image_new(data->mlx, SCREEN_W, SCREEN_H);
	handle_keypress(data);
	main_raycast(data, win_img);
	display_minimap(data, win_img, -1);
	mlx_put_image_to_window(data->mlx, data->win, win_img.img, 0, 0);
	image_delete(data->mlx, win_img);
	return (0);
}

void	main_raycast(t_data *d, t_image win_img)
{
	int			x;
	int			side;
	double		wall_x;
	t_texture	*tex;

	tex = NULL;
	x = 0;
	while (x < SCREEN_W)
	{
		raycast_init_var(d, x);
		raycast_init_raydir(d);
		side = raycast_dda(d);
		wall_x = calc_wall_intersection(d, side, wall_x);
		calc_draw(d);
		tex = define_texture(d, side);
		d->tex_x = ((int)(wall_x * (double)tex->width)) % tex->width;
		if (side == 0 && d->raycast_var.ray_dir_x > 0)
			d->tex_x = tex->width - d->tex_x - 1;
		if (side == 1 && d->raycast_var.ray_dir_y < 0)
			d->tex_x = tex->width - d->tex_x - 1;
		draw_c(win_img, d, x, d->map->ceiling_color);
		draw_wall(win_img, d, x, tex);
		draw_f(win_img, d, x, d->map->floor_color);
		x++;
	}
}

int	raycast_dda(t_data *data)
{
	int	i;
	int	side;

	i = 0;
	while (i == 0)
	{
		if (data->raycast_var.side_x < data->raycast_var.side_y)
		{
			data->raycast_var.side_x += data->raycast_var.delta_dist_x;
			data->raycast_var.map_x += data->raycast_var.step_x;
			side = 0;
		}
		else
		{
			data->raycast_var.side_y += data->raycast_var.delta_dist_y;
			data->raycast_var.map_y += data->raycast_var.step_y;
			side = 1;
		}
		if (data->game_map[data->raycast_var.map_x]
			[data->raycast_var.map_y] == '1')
			i = 1;
	}
	return (side);
}

double	calc_wall_intersection(t_data *d, int side, double wall_x)
{
	if (side == 0)
		d->raycast_var.perp_wall_disst = (d->raycast_var.map_x - d->pos_x
				+ (1 - d->raycast_var.step_x) / 2) / d->raycast_var.ray_dir_x;
	else
		d->raycast_var.perp_wall_disst = (d->raycast_var.map_y - d->pos_y
				+ (1 - d->raycast_var.step_y) / 2) / d->raycast_var.ray_dir_y;
	if (side == 0)
		wall_x = d->pos_y + d->raycast_var.perp_wall_disst
			* d->raycast_var.ray_dir_y;
	else
		wall_x = d->pos_x + d->raycast_var.perp_wall_disst
			* d->raycast_var.ray_dir_x;
	wall_x -= floor((wall_x));
	return (wall_x);
}

void	calc_draw(t_data *d)
{
	d->line_height = (int)(SCREEN_H / d->raycast_var.perp_wall_disst);
	d->draw_start = -d->line_height / 2 + SCREEN_H / 2;
	d->draw_end = d->line_height / 2 + SCREEN_H / 2;
	if (d->draw_start < 0)
		d->draw_start = 0;
	if (d->draw_end >= SCREEN_H)
		d->draw_end = SCREEN_H - 1;
}
