#include "cub3D.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

void	ft_clean(t_data_map *map, int status)
{
	if (map->north_texture)
		free(map->north_texture);
	if (map->south_texture)
		free(map->south_texture);
	if (map->west_texture)
		free(map->west_texture);
	if (map->east_texture)
		free(map->east_texture);
	if (map->fd != -1)
		close(map->fd);
	if (map->map)
		free_tab(map->map);
	exit(status);
}

void	handle_error(char *line, t_data_map *map, char **c_v, char *str)
{
	ft_printf("Error\n%s\n", str);
	free(line);
	free_tab(c_v);
	get_next_line(map->fd, 1);
	ft_clean(map, 1);
}

void	tex_path_error(char *line, t_data_map *map, char *new_path)
{
	ft_printf("Error\nInvalid texture path\n");
	get_next_line(map->fd, 1);
	free(new_path);
	free(line);
	ft_clean(map, 1);
}
