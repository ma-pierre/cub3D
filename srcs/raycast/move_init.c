/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:31:09 by mapierre          #+#    #+#             */
/*   Updated: 2024/07/11 18:36:37 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_player_n_s(t_data *data)
{
	if (data->player_start_dir == 'N')
	{
		data->dir_y = 0.01;
		data->dir_x = -1;
		data->plane_y = 0.66;
		data->plane_x = 0.01;
	}
	else if (data->player_start_dir == 'S')
	{
		data->dir_y = 0.01;
		data->dir_x = 1;
		data->plane_y = -0.66;
		data->plane_x = 0.01;
	}
}

void	init_player_direction(t_data *data)
{
	if (data->player_start_dir == 'N' || data->player_start_dir == 'S')
		init_player_n_s(data);
	else if (data->player_start_dir == 'E')
	{
		data->dir_y = 1;
		data->dir_x = 0.01;
		data->plane_y = 0.01;
		data->plane_x = 0.66;
	}
	else if (data->player_start_dir == 'W')
	{
		data->dir_y = -1;
		data->dir_x = 0.01;
		data->plane_y = 0.01;
		data->plane_x = -0.66;
	}
}
