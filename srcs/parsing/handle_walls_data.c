#include "cub3D.h"

void	handle_no_data(char *line, t_data_map *map, int i)
{
	if (map->is_north_set == 0)
	{
		map->is_north_set = 1;
		map->count_elements += 1;
		handle_no_texture(line, i + 2, map);
	}
	else
	{
		ft_printf("Error\nNO element already exists.\n");
		free(line);
		get_next_line(map->fd, 1);
		ft_clean(map, 1);
	}
}

void	handle_so_data(char *line, t_data_map *map, int i)
{
	if (map->is_south_set == 0)
	{
		map->is_south_set = 1;
		map->count_elements += 1;
		handle_so_texture(line, i + 2, map);
	}
	else
	{
		ft_printf("Error\nSO element already exists.\n");
		free(line);
		get_next_line(map->fd, 1);
		ft_clean(map, 1);
	}
}

void	handle_we_data(char *line, t_data_map *map, int i)
{
	if (map->is_west_set == 0)
	{
		map->is_west_set = 1;
		map->count_elements += 1;
		handle_we_texture(line, i + 2, map);
	}
	else
	{
		ft_printf("Error\nWE element already exists.\n");
		free(line);
		get_next_line(map->fd, 1);
		ft_clean(map, 1);
	}
}

void	handle_ea_data(char *line, t_data_map *map, int i)
{
	if (map->is_east_set == 0)
	{
		map->is_east_set = 1;
		map->count_elements += 1;
		handle_ea_texture(line, i + 2, map);
	}
	else
	{
		ft_printf("Error\nEA element already exists.\n");
		free(line);
		get_next_line(map->fd, 1);
		ft_clean(map, 1);
	}
}
