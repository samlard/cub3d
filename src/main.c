#include "test.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (1);
	init_data(&data);
	if (!check_cub(av[1], &data))
		return (err_msg(ERROR_CUB, NULL, 1));
	if (!parsing(&data))
		return (1);
	if (!init_window(&data))
		return (1); 
    mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data); 
    mlx_hook(data.win, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data); 
	mlx_loop_hook(data.mlx, &display, &data);
	mlx_loop(data.mlx);             
	return (0);
}
