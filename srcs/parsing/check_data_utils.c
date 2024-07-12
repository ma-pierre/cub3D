
#include "cub3D.h"

int	open_file(char *filename, t_data_map *map)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nOpening file failed\n");
		return (1);
	}
	map->fd = fd;
	map->countline = 0;
	return (0);
}

int	verify_border_and_cleanup(t_data_map *map, char *line)
{
	if (check_top_border(line) != 0)
	{
		free(line);
		get_next_line(map->fd, 1);
		close(map->fd);
		ft_printf("Error\nNo upper border!\n");
		ft_clean(map, 1);
		return (1);
	}
	free(line);
	return (0);
}

int	handle_map_start(t_data_map *map)
{
	char	*line;

	while (1)
	{
		line = get_next_line(map->fd, 0);
		if (!line || (!is_all_white_space(line) && line[0] != '\n'))
			break ;
		map->countline++;
		free(line);
	}
	if (line)
	{
		map->countline++;
		if (verify_border_and_cleanup(map, line) != 0)
			return (1);
	}
	map->map_start = 1;
	return (0);
}

int	handle_line_errors(char *line, t_data_map *map)
{
	if (!is_all_white_space(line) && map->count_elements < 6
		&& check_top_border(line) == 0)
	{
		ft_printf("Error\nMissing data elements\n");
		get_next_line(map->fd, 1);
		ft_clean(map, 1);
		return (1);
	}
	return (0);
}
