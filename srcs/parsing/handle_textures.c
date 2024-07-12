#include "cub3D.h"

void	handle_texture(char **texture, char *line, int i, t_data_map *map)
{
	char	*new_path;
	int		len;

	while (is_white_space(line[i]))
		i++;
	new_path = ft_strdup(line + i);
	if (new_path == NULL)
	{
		ft_printf("Error\nAllocating memory\n");
		ft_clean(map, 1);
	}
	len = ft_strlen(new_path);
	while (len > 0 && (is_white_space(new_path[len - 1])
			|| new_path[len - 1] == '\n'))
		len--;
	new_path[len] = '\0';
	if (is_valid_path(new_path) != 0)
		tex_path_error(line, map, new_path);
	if (*texture != NULL)
		free(*texture);
	*texture = new_path;
}

void	handle_no_texture(char *line, int i, t_data_map *map)
{
	handle_texture(&(map->north_texture), line, i, map);
}

void	handle_so_texture(char *line, int i, t_data_map *map)
{
	handle_texture(&(map->south_texture), line, i, map);
}

void	handle_we_texture(char *line, int i, t_data_map *map)
{
	handle_texture(&(map->west_texture), line, i, map);
}

void	handle_ea_texture(char *line, int i, t_data_map *map)
{
	handle_texture(&(map->east_texture), line, i, map);
}
