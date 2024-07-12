#include "cub3D.h"

void	handle_f_data(char *line, t_data_map *map, int i)
{
	if (map->is_floor_set == 0)
	{
		map->is_floor_set = 1;
		map->count_elements += 1;
		handle_floor_colors(line, i + 1, map);
	}
	else
	{
		ft_printf("Error\nF element already exists.\n");
		free(line);
		get_next_line(map->fd, 1);
		ft_clean(map, 1);
	}
}

void	handle_c_data(char *line, t_data_map *map, int i)
{
	if (map->is_ceiling_set == 0)
	{
		map->is_ceiling_set = 1;
		map->count_elements += 1;
		handle_ceiling_colors(line, i + 1, map);
	}
	else
	{
		ft_printf("Error\nC element already exists.\n");
		free(line);
		get_next_line(map->fd, 1);
		ft_clean(map, 1);
	}
}
