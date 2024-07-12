/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:56:31 by mapierre          #+#    #+#             */
/*   Updated: 2024/07/12 17:51:36 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	readtab(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (data->game_map[i])
	{
		j = 0;
		while (data->game_map[i][j])
			j++;
		if (j > data->map_width)
			data->map_width = j;
		i++;
	}
	data->map_height = i;
}

void	display_minimap(t_data *data, t_image win_img, int y)
{
	int		x;
	float	scale_y;
	float	scale_x;
	int		ds;

	scale_y = (SCREEN_W * 0.2) / (float)data->map_width / 64;
	scale_x = (SCREEN_H * 0.2) / (float)data->map_height / 64;
	ds = ceil(64 * scale_x);
	while (++y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (x < data->map_width && y < data->map_height && data->game_map[y]
				&& (size_t)x < ft_strlen(data->game_map[y]))
			{
				if (data->game_map[y][x] == '0')
					draw_minimap_wall(win_img, x * ds, y * ds, ds);
				else
					draw_minimap_floor(win_img, x * ds, y * ds, ds);
			}
			x++;
		}
	}
	draw_square(win_img, data->pos_y * ds, data->pos_x * ds, ds);
}

void	draw_square(t_image img, int x, int y, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			image_put_px(img, x + i, y + j, 0xE0004E);
			j++;
		}
		i++;
	}
}

void	draw_minimap_wall(t_image img, int x, int y, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			image_put_px(img, x + i, y + j, 0x000000);
			j++;
		}
		i++;
	}
}

void	draw_minimap_floor(t_image img, int x, int y, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			image_put_px(img, x + i, y + j, 0xFFFFFF);
			j++;
		}
		i++;
	}
}
