#include "cub3D.h"

void	initialize_map(t_data_map *map)
{
	map->north_texture = NULL;
	map->south_texture = NULL;
	map->west_texture = NULL;
	map->east_texture = NULL;
	map->map = NULL;
	map->ceiling_color = 0;
	map->floor_color = 0;
	map->is_north_set = 0;
	map->is_south_set = 0;
	map->is_west_set = 0;
	map->is_east_set = 0;
	map->is_ceiling_set = 0;
	map->is_floor_set = 0;
	map->count_elements = 0;
	map->map_width = 0;
	map->map_height = 0;
	map->map_start = 0;
	map->fd = -1;
	map->countline = 0;
}

void	start_parsing(char *filename, t_data_map *map)
{
	initialize_map(map);
	if (check_data(filename, map) != 0)
	{
		ft_clean(map, 1);
	}
	if (check_map(filename, map) != 0)
		ft_clean(map, 1);
	turn_into_walls(map);
}
