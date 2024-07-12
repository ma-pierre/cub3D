#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_data_map	map;
	t_data		data;

	if (check_arg(argc, argv) != 0)
		return (1);
	start_parsing(argv[1], &map);
	data.map = &map;
	init_raycast_main(&data);
	data.mlx = mlx_init();
	if (!data.mlx)
	{
		ft_clean(&map, 1);
		close(map.fd);
		return (1);
	}
	init_raycast_all(&data);
	mlx_hook(data.win, KEYPRESS, (1L << 0), key_press, &data);
	mlx_hook(data.win, KEYRELEASE, (1L << 1), key_release, &data);
	mlx_loop_hook(data.mlx, &do_frame, &data);
	mlx_hook(data.win, 17, 0, &clean_game, &data);
	mlx_loop(data.mlx);
	close(map.fd);
	ft_clean(&map, 0);
	return (0);
}
