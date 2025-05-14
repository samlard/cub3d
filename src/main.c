#include "test.h"

int	main(int ac, char **av)
{
	t_data	data;
	int i = 0;

	if (ac != 2)
		return (1);
	init_data(&data);
	if (!parsing(&data, av[1]))
		return (1);
	if (!init_window(&data))
		return (1);
	get_xpm(&data);
	while(data.map[i])
	{
		printf("<%s>\n", data.map[i]);
		i++;
	}
	data.img = mlx_new_image(data.mlx, WIN_WIDTH, WIN_HEIGHT);
	data.img_addr = mlx_get_data_addr(data.img, &data.bpp, &data.size_line,
		&data.endian);
	mlx_hook(data.win, 17, 0, (void *)exit, 0);
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);
	mlx_loop_hook(data.mlx, &display, &data);
	//mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_loop(data.mlx);
	return (0);
}
