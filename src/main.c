/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-vel <mvan-vel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 11:58:54 by ssoumill          #+#    #+#             */
/*   Updated: 2025/05/30 15:02:30 by mvan-vel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (err_msg("only one argument : exemple.cub", NULL, 1));
	init_data(&data);
	if (!parsing(&data, av[1]))
		return (1);
	if (!init_window(&data))
		return (1);
	get_xpm(&data);
	data.img = mlx_new_image(data.mlx, WIN_WIDTH, WIN_HEIGHT);
	data.img_addr = mlx_get_data_addr(data.img, &data.bpp, &data.size_line,
			&data.endian);
	draw_ray(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_hook(data.win, 17, 0, (void *)exit, 0);
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);
	mlx_loop_hook(data.mlx, &display, &data);
	mlx_loop(data.mlx);
	return (0);
}
