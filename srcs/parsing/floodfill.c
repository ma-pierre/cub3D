#include "cub3D.h"

int	fill(char **copy, int x, int y)
{
	if (copy[y][x] == '1' || copy[y][x] == '2')
		return (0);
	copy[y][x] = '2';
	if (x == 0 || y == 0 || copy[y + 1] == NULL || copy[y][x + 1] == '\0')
		return (1);
	if (fill(copy, x + 1, y))
		return (1);
	if (fill(copy, x - 1, y))
		return (1);
	if (fill(copy, x, y + 1))
		return (1);
	if (fill(copy, x, y - 1))
		return (1);
	return (0);
}

void	get_player_directions(t_data_map *map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (is_player(map->map[i][j]))
			{
				*x = j;
				*y = i;
			}
			j++;
		}
		i++;
	}
}

char	**mapcopy(t_data_map *map)
{
	int		i;
	char	**copy_map;

	copy_map = malloc(sizeof(char *) * (map->map_height + 1));
	if (!copy_map)
	{
		free_tab(copy_map);
		return (free(copy_map), NULL);
	}
	i = 0;
	while (map->map[i])
	{
		copy_map[i] = ft_strdup(map->map[i]);
		i++;
	}
	copy_map[i] = 0;
	return (copy_map);
}

int	checkflood(char **copy_map)
{
	int	i;
	int	j;

	i = 0;
	while (copy_map[i])
	{
		j = 0;
		while (copy_map[i][j])
		{
			if (copy_map[i][j] != '1' && copy_map[i][j] != '2'
			&& !is_white_space(copy_map[i][j]) && copy_map[i][j] != '0')
			{
				ft_printf("Error\nProblem with items\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	floodfill(t_data_map *map)
{
	int		x;
	int		y;
	char	**copy;

	copy = mapcopy(map);
	get_player_directions(map, &x, &y);
	fill(copy, x, y);
	if (checkflood(copy) != 0)
	{
		free_tab(copy);
		return (1);
	}
	free_tab(copy);
	return (0);
}
