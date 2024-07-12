/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:31:15 by mapierre          #+#    #+#             */
/*   Updated: 2024/07/11 19:17:34 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_raycast_main(t_data *data)
{
	int		i;
	int		j;

	data->player_start_dir = data->map->player_direction;
	data->game_map = data->map->map;
	i = 0;
	while (data->game_map[i])
	{
		j = 0;
		while (data->game_map[i][j])
		{
			if (data->game_map[i][j] == data->player_start_dir)
			{
				data->pos_y = (double)j + 0.5;
				data->pos_x = (double)i + 0.5;
				data->game_map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}

void	raycast_init_var(t_data *d, int x)
{
	d->raycast_var.cam_x = 2 * x / (double)SCREEN_W - 1;
	d->raycast_var.ray_dir_x = d->dir_x + d->plane_x * d->raycast_var.cam_x;
	d->raycast_var.ray_dir_y = d->dir_y + d->plane_y * d->raycast_var.cam_x;
	d->raycast_var.map_x = (int)d->pos_x;
	d->raycast_var.map_y = (int)d->pos_y;
	d->raycast_var.side_x = 0;
	d->raycast_var.side_y = 0;
	d->line_height = 0;
	d->draw_start = 0;
	d->draw_end = 0;
	d->tex_x = 0;
	d->raycast_var.delta_dist_x = fabs(1 / d->raycast_var.ray_dir_x);
	d->raycast_var.delta_dist_y = fabs(1 / d->raycast_var.ray_dir_y);
	d->raycast_var.perp_wall_disst = 0;
	d->raycast_var.step_x = 0;
	d->raycast_var.step_y = 0;
}

void	raycast_init_raydir(t_data *data)
{
	if (data->raycast_var.ray_dir_x < 0)
	{
		data->raycast_var.step_x = -1;
		data->raycast_var.side_x = (data->pos_x
				- data->raycast_var.map_x) * data->raycast_var.delta_dist_x;
	}
	else
	{
		data->raycast_var.step_x = 1;
		data->raycast_var.side_x = (data->raycast_var.map_x
				+ 1.0 - data->pos_x) * data->raycast_var.delta_dist_x;
	}
	if (data->raycast_var.ray_dir_y < 0)
	{
		data->raycast_var.step_y = -1;
		data->raycast_var.side_y = (data->pos_y
				- data->raycast_var.map_y) * data->raycast_var.delta_dist_y;
	}
	else
	{
		data->raycast_var.step_y = 1;
		data->raycast_var.side_y = (data->raycast_var.map_y
				+ 1.0 - data->pos_y) * data->raycast_var.delta_dist_y;
	}
}

void	init_raycast_all(t_data *data)
{
	init_player_direction(data);
	init_texture(data);
	data->move_speed = 0.03;
	data->rot_speed = 0.01;
	data->map_width = 0;
	data->map_height = 0;
	readtab(data);
	init_keys(data);
	data->win = mlx_new_window(data->mlx, SCREEN_W, SCREEN_H, "cub3D");
}
