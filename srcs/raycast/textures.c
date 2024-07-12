/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:31:20 by mapierre          #+#    #+#             */
/*   Updated: 2024/07/12 15:25:03 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_texture(t_data *d)
{
	d->s_tex[0].img = mlx_xpm_file_to_image(d->mlx, d->map->north_texture,
			&d->s_tex[0].width, &d->s_tex[0].height);
	d->s_tex[0].addr = mlx_get_data_addr(d->s_tex[0].img, &d->s_tex[0].bpp,
			&d->s_tex[0].line_length, &d->s_tex[0].endian);
	d->s_tex[1].img = mlx_xpm_file_to_image(d->mlx, d->map->south_texture,
			&d->s_tex[1].width, &d->s_tex[1].height);
	d->s_tex[1].addr = mlx_get_data_addr(d->s_tex[1].img, &d->s_tex[1].bpp,
			&d->s_tex[1].line_length, &d->s_tex[1].endian);
	d->s_tex[2].img = mlx_xpm_file_to_image(d->mlx, d->map->east_texture,
			&d->s_tex[2].width, &d->s_tex[2].height);
	d->s_tex[2].addr = mlx_get_data_addr(d->s_tex[2].img, &d->s_tex[2].bpp,
			&d->s_tex[2].line_length, &d->s_tex[2].endian);
	d->s_tex[3].img = mlx_xpm_file_to_image(d->mlx, d->map->west_texture,
			&d->s_tex[3].width, &d->s_tex[3].height);
	d->s_tex[3].addr = mlx_get_data_addr(d->s_tex[3].img, &d->s_tex[3].bpp,
			&d->s_tex[3].line_length, &d->s_tex[3].endian);
}

t_texture	*define_texture(t_data *d, int side)
{
	if (side == 0)
	{
		if (d->raycast_var.step_x > 0)
			return (&d->s_tex[0]);
		else
			return (&d->s_tex[1]);
	}
	else
	{
		if (d->raycast_var.step_y > 0)
			return (&d->s_tex[3]);
		else
			return (&d->s_tex[2]);
	}
	return (NULL);
}
