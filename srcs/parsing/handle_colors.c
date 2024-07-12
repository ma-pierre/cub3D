#include "cub3D.h"

int	count_comma(char *line)
{
	int	count_comma;
	int	i;

	count_comma = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ',')
			count_comma++;
		i++;
	}
	if (count_comma != 2)
	{
		ft_printf("Error\nTwo commas are needed to split the RGB colors\n");
		return (1);
	}
	return (0);
}

void	handle_floor_colors(char *line, int i, t_data_map *map)
{
	char	**c_v;
	int		rgb;

	c_v = NULL;
	if (count_comma(line + 1) == 1)
	{
		free(line);
		get_next_line(map->fd, 1);
		ft_clean(map, 1);
	}
	else if (count_comma(line + i) == 0)
	{
		c_v = ft_split(line + i, ',');
		get_rgb_values(c_v, &rgb, line, map);
		map->floor_color = rgb;
		free_tab(c_v);
	}
}

void	handle_ceiling_colors(char *line, int i, t_data_map *map)
{
	char		**c_v;
	int			rgb;

	c_v = NULL;
	if (count_comma(line + 1) == 1)
	{
		free(line);
		get_next_line(map->fd, 1);
		ft_clean(map, 1);
	}
	else if (count_comma(line + i) == 0)
	{
		c_v = ft_split(line + i, ',');
		get_rgb_values(c_v, &rgb, line, map);
		map->ceiling_color = rgb;
		free_tab(c_v);
	}
}

void	get_rgb_values(char **c_v, int *rgb, char *line, t_data_map *map)
{
	int		i;
	int		color;
	char	*tmp;

	i = 0;
	*rgb = 0;
	while (i < 3)
	{
		tmp = c_v[i];
		while (is_white_space(*tmp))
			tmp++;
		if (*tmp == '-' || !is_digit(*tmp))
			handle_error(line, map, c_v, "Unexpected characters, only digits.");
		color = ft_atoi(tmp);
		while (is_digit(*tmp))
			tmp++;
		while (is_white_space(*tmp))
			tmp++;
		if (*tmp != '\0' && *tmp != ',')
			handle_error(line, map, c_v, "Unexpected characters, only digits.");
		if (color < 0 || color > 255)
			handle_error(line, map, c_v, "Color value between 0 and 255.");
		apply_color_to_rgb(i, &color, rgb);
		i++;
	}
}

void	apply_color_to_rgb(int index, int *color, int *rgb)
{
	if (index == 0)
	{
		*rgb |= *color << 16;
	}
	else if (index == 1)
	{
		*rgb |= *color << 8;
	}
	else
	{
		*rgb |= *color;
	}
}
