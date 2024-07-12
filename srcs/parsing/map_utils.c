#include "cub3D.h"

int	is_all_white_space(const char *str)
{
	if (!str)
		return (1);
	while (*str)
	{
		if (!is_white_space((unsigned char)*str))
		{
			return (0);
		}
		str++;
	}
	return (1);
}

int	get_dimensions(char *filename, t_data_map *map)
{
	int		max_width;
	int		line_length;
	char	*line;

	max_width = 0;
	map->fd = open(filename, O_RDONLY);
	if (map->fd == -1)
		return (-1);
	skip_lines(map->fd, map->countline);
	while (1)
	{
		line = get_next_line(map->fd, 0);
		if (!line)
			break ;
		map->map_height++;
		line_length = ft_strlen(line);
		if (line_length > max_width)
			max_width = line_length;
		free(line);
	}
	get_next_line(map->fd, 1);
	close(map->fd);
	map->map_width = max_width;
	return (0);
}

void	clean_end_white_space_lines(t_data_map *map)
{
	int	i;

	i = map->map_height -1 ;
	while (i >= 0 && is_all_white_space(map->map[i]))
	{
		free(map->map[i]);
		map->map[i] = NULL;
		map->map_height -= 1;
		i--;
	}
}

int	check_empty_line(t_data_map *map)
{
	int	i;

	i = 0;
	while (map->map[i] != NULL)
	{
		if (is_all_white_space(map->map[i]))
		{
			ft_printf("Error\nEmpty line(s) after top border\n");
			ft_clean(map, 2);
			return (1);
		}
		i++;
	}
	return (0);
}
