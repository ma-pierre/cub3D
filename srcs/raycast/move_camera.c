/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:55:41 by mapierre          #+#    #+#             */
/*   Updated: 2024/07/11 18:31:07 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	camera_left(t_data *d)
{
	double	c_dir_x;
	double	c_plane_x;

	c_dir_x = d->dir_x;
	c_plane_x = d->plane_x;
	d->dir_x = d->dir_x * cos(d->rot_speed) - d->dir_y * sin(d->rot_speed);
	d->dir_y = c_dir_x * sin(d->rot_speed) + d->dir_y * cos(d->rot_speed);
	d->plane_x = d->plane_x * cos(d->rot_speed)
		- d->plane_y * sin(d->rot_speed);
	d->plane_y = c_plane_x * sin(d->rot_speed) + d->plane_y * cos(d->rot_speed);
}

void	camera_right(t_data *d)
{
	double	c_dir_x;
	double	c_plane_x;

	c_dir_x = d->dir_x;
	c_plane_x = d->plane_x;
	d->dir_x = d->dir_x * cos(-d->rot_speed) - d->dir_y * sin(-d->rot_speed);
	d->dir_y = c_dir_x * sin(-d->rot_speed) + d->dir_y * cos(-d->rot_speed);
	d->plane_x = d->plane_x * cos(-d->rot_speed)
		- d->plane_y * sin(-d->rot_speed);
	d->plane_y = c_plane_x * sin(-d->rot_speed)
		+ d->plane_y * cos(-d->rot_speed);
}
