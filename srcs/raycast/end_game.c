/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:25:33 by mapierre          #+#    #+#             */
/*   Updated: 2024/07/11 18:37:30 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	clean_game(t_data *data)
{
	int	i;

	i = 0;
	if (data->win)
	{
		mlx_clear_window(data->mlx, data->win);
		mlx_destroy_window(data->mlx, data->win);
	}
	while (i < 4)
	{
		if (data->s_tex[i].img)
			mlx_destroy_image(data->mlx, data->s_tex[i].img);
		i++;
	}
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->map)
	{
		close(data->map->fd);
		ft_clean(data->map, 0);
	}
	exit(0);
}
