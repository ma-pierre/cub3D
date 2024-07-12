#include "cub3D.h"

int	check_extension(char *str, char *extension)
{
	int	len;
	int	ext_len;
	int	i;

	len = ft_strlen(str);
	ext_len = ft_strlen(extension);
	if (len < ext_len)
		return (1);
	i = 0;
	while (i < ext_len)
	{
		if (str[len - ext_len + i] != extension[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_cub(char *str)
{
	if (ft_strlen(str) < 4 || check_extension(str, ".cub") != 0)
		return (1);
	return (0);
}

int	check_xpm(char *str)
{
	if (ft_strlen(str) < 4 || check_extension(str, ".xpm") != 0)
	{
		ft_printf("Error\nInvalid .xpm file extension\n");
		return (1);
	}
	return (0);
}

int	is_valid_path(char *texture_path)
{
	int	fd;

	fd = open(texture_path, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	if (check_xpm(texture_path) != 0)
		return (1);
	return (0);
}

int	check_arg(int argc, char **argv)
{
	if (argc != 2 || argv[1] == NULL)
		return ((ft_printf("Error\nWrong arguments!\n")), 1);
	if (check_cub(argv[1]) == 1)
		return ((ft_printf("Error\nA .cub map is needed!\n"), 1));
	return (0);
}
