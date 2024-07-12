
#include "cub3D.h"

int	parse_line(char *line, t_data_map *map)
{
	int	i;

	i = 0;
	if (line[i] != '\0')
	{
		while (is_white_space(line[i]))
			i++;
		if (ft_strncmp(line + i, "NO", 2) == 0)
			handle_no_data(line, map, i);
		else if (ft_strncmp(line + i, "SO", 2) == 0)
			handle_so_data(line, map, i);
		else if (ft_strncmp(line + i, "WE", 2) == 0)
			handle_we_data(line, map, i);
		else if (ft_strncmp(line + i, "EA", 2) == 0)
			handle_ea_data(line, map, i);
		else if ((ft_strncmp(line + i, "F", 1) == 0)
			&& (next_is_space(line[i + 1])))
			handle_f_data(line, map, i);
		else if ((ft_strncmp(line + i, "C", 1) == 0)
			&& (next_is_space(line[i + 1])))
			handle_c_data(line, map, i);
		else if (line[i] != '\n' && line[i] != '\0')
			return (ft_printf("Error\nNo other character is allowed.\n"), 1);
	}
	return (0);
}

int	process_file(t_data_map *map)
{
	char	*line;

	while (1)
	{
		line = get_next_line(map->fd, 0);
		if (!line)
			break ;
		if (parse_line(line, map) != 0)
			return (get_next_line(map->fd, 1), free(line), 1);
		map->countline++;
		if (map->count_elements == 6 && map->map_start == 0)
		{
			if (handle_map_start(map) != 0)
				return (free(line), 1);
			free(line);
			break ;
		}
		else if (handle_line_errors(line, map) != 0)
		{
			free(line);
			return (1);
		}
		free(line);
	}
	return (0);
}

int	close_and_finalize(t_data_map *map)
{
	get_next_line(map->fd, 1);
	close(map->fd);
	if (map->count_elements != 6)
	{
		ft_printf("Error\nMissing data\n");
		return (1);
	}
	return (0);
}

int	check_data(char *filename, t_data_map *map)
{
	if (open_file(filename, map) != 0)
		return (1);
	if (process_file(map) != 0)
		return (1);
	return (close_and_finalize(map));
}
