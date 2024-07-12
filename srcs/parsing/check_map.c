#include "cub3D.h"

int	check_elements(t_data_map *map)
{
	int			i;
	int			j;
	static int	player_count;

	i = 0;
	while (i < map->map_height && map->map[i] != NULL)
	{
		j = 0;
		while (j < map->map_width && map->map[i][j] != '\0')
		{
			if (is_player(map->map[i][j]))
			{
				player_count++;
				map->player_direction = map->map[i][j];
			}
			else if (map->map[i][j] != '1' && map->map[i][j] != '0'
				&& !is_white_space(map->map[i][j]))
				return (ft_printf("Error\nInvalid element in map\n"), 1);
			j++;
		}
		i++;
	}
	if (player_count != 1)
		return (ft_printf("Error\nInvalid number of players\n"), 1);
	return (0);
}

int	check_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || is_player(map[i][j]))
			{
				if (i == 0 || map[i + 1] == NULL || j == 0
					|| map[i][j + 1] == '\0'
					|| map[i + 1][j] == '\0' || is_white_space(map[i + 1][j])
					|| is_white_space(map[i - 1][j])
					|| is_white_space(map[i][j - 1])
					|| is_white_space(map[i][j + 1]))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	turn_into_walls(t_data_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (is_white_space(map->map[i][j]))
				map->map[i][j] = 1;
			j++;
		}
		i++;
	}
}

int	check_map(char *filename, t_data_map *map)
{
	if (get_dimensions(filename, map) != 0)
		return (ft_printf("Error\nCounting map dimensions failed\n"), 1);
	if (store_map(filename, map) != 0)
		return (ft_printf("Error\nReading and storing map failed\n"), 1);
	if (check_empty_line(map) != 0)
		return (ft_printf("Error\nEmpty lines in the map\n"), 1);
	if (check_elements(map) != 0)
		return (1);
	if (check_walls(map->map) != 0)
		return (ft_printf("Error\nChecking map walls failed\n"), 1);
	if (floodfill(map) != 0)
		return (ft_printf("Error\nFloodfill check failed\n"), 1);
	return (0);
}

int	check_top_border(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\0' && map[i] != '\n')
	{
		if (map[i] != '1' && !is_white_space(map[i]))
			return (1);
		i++;
	}
	return (0);
}
