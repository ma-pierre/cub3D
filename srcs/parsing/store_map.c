#include "cub3D.h"

int	store_map(char *filename, t_data_map *map)
{
	int		line_index;

	map->fd = open(filename, O_RDONLY);
	if (map->fd == -1)
		return (-1);
	skip_lines(map->fd, map->countline);
	map->map = malloc(sizeof(char *) * (map->map_height + 1));
	if (!map->map)
		return (get_next_line(map->fd, 1), close(map->fd), 1);
	line_index = read_and_store_map(map, 0);
	if (line_index == -1)
		return (1);
	clean_end_white_space_lines(map);
	map->map[line_index] = NULL;
	get_next_line(map->fd, 1);
	close(map->fd);
	return (0);
}

int	read_and_store_map(t_data_map *map, int line_index)
{
	char	*line;
	int		line_length;

	while (1)
	{
		line = get_next_line(map->fd, 0);
		if (!line)
			break ;
		line_length = ft_strlen(line);
		if (line[line_length - 1] == '\n')
			line[line_length - 1] = '\0';
		map->map[line_index] = malloc(sizeof(char) * (line_length + 1));
		if (!map->map[line_index])
		{
			free(line);
			return (get_next_line(map->fd, 1), close(map->fd), -1);
		}
		ft_strncpy(map->map[line_index], line, line_length + 1);
		map->map[line_index][line_length] = '\0';
		free(line);
		line_index++;
		if (line_index >= map->map_height)
			break ;
	}
	return (line_index);
}

void	skip_lines(int fd, int skip)
{
	char	*line;
	int		i;

	i = 1;
	while (i < skip)
	{
		line = get_next_line(fd, 0);
		if (line)
		{
			free(line);
		}
		i++;
	}
}
