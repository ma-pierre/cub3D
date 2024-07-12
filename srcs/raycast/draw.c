/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:30:17 by mapierre          #+#    #+#             */
/*   Updated: 2024/07/11 19:17:34 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_c(t_image image, t_data *data, int x, int color)
{
	int		y1;
	int		y2;

	y1 = 0;
	y2 = data->draw_start;
	if (x < 0 || x >= SCREEN_W)
		return ;
	if (y1 < 0)
		y1 = 0;
	if (y2 >= SCREEN_H)
		y2 = SCREEN_H - 1;
	while (y1 <= y2)
	{
		image_put_px(image, x, y1, color);
		y1++;
	}
}

void	draw_f(t_image image, t_data *data, int x, int color)
{
	int		y1;
	int		y2;

	y1 = data->draw_end;
	y2 = SCREEN_H;
	if (x < 0 || x >= SCREEN_W)
		return ;
	if (y1 < 0)
		y1 = 0;
	if (y2 >= SCREEN_H)
	{
		y2 = SCREEN_H - 1;
	}
	while (y1 < y2)
	{
		image_put_px(image, x, y1, color);
		y1++;
	}
}

void	draw_wall(t_image image, t_data *data, int x, t_texture *tex)
{
	int				y;
	int				tex_y;
	unsigned int	color;
	double			step;
	double			tex_pos;

	y = data->draw_start;
	step = (double)tex->height / data->line_height;
	tex_pos = (data->draw_start - SCREEN_H / 2 + data->line_height / 2) * step;
	while (y < data->draw_end)
	{
		tex_y = (int)tex_pos % tex->height;
		color = *(unsigned int *)(tex->addr + (tex_y * tex->line_length
					+ data->tex_x * (tex->bpp / 8)));
		image_put_px(image, x, y, color);
		tex_pos += step;
		y++;
	}
}
