/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tete.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:35:57 by ssoumill          #+#    #+#             */
/*   Updated: 2025/05/15 18:38:12 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	destroy_xpm(t_data *data)
{
	if (data->img_no)
	{
		mlx_destroy_image(data->mlx, data->img_no);
		data->img_no = NULL;
	}
	if (data->img_so)
	{
		mlx_destroy_image(data->mlx, data->img_so);
		data->img_so = NULL;
	}
	if (data->img_ea)
	{
		mlx_destroy_image(data->mlx, data->img_ea);
		data->img_ea = NULL;
	}
	if (data->img_we)
	{
		mlx_destroy_image(data->mlx, data->img_we);
		data->img_we = NULL;
	}
	ft_free_texture(data);
	close(data->fd_map);
	exit(1);
}

void    get_addr(t_texture *texture)
{
    texture[NORTH].addr = mlx_get_data_addr(texture[NORTH].img, &texture[NORTH].bpp, &texture[NORTH].size_line, &texture[NORTH].endian);
    texture[SOUTH].addr = mlx_get_data_addr(texture[SOUTH].img, &texture[SOUTH].bpp, &texture[SOUTH].size_line, &texture[SOUTH].endian);
    texture[EAST].addr = mlx_get_data_addr(texture[EAST].img, &texture[EAST].bpp, &texture[EAST].size_line, &texture[EAST].endian);
    texture[WEST].addr = mlx_get_data_addr(texture[WEST].img, &texture[WEST].bpp, &texture[WEST].size_line, &texture[WEST].endian);
}

void	get_xpm(t_data *data)
{
	int i;
	t_texture *texture;

	texture = data->texture;
	i = 0;
	if (!(texture[NORTH].img = mlx_xpm_file_to_image(data->mlx,
				data->NO, &texture[NORTH].width,
				&texture[NORTH].height)))
		i = err_msg("NO file xpm", data->NO, 1);
	if (!(texture[SOUTH].img = mlx_xpm_file_to_image(data->mlx,
				data->SO, &texture[SOUTH].width,
				&texture[SOUTH].height)))
		i = err_msg("SO file xpm", data->SO, 1);
	if (!(texture[EAST].img = mlx_xpm_file_to_image(data->mlx,
				data->EA, &texture[EAST].width,
				&texture[EAST].height)))
		i = err_msg("EA file xpm", data->EA, 1);
	if (!(texture[WEST].img = mlx_xpm_file_to_image(data->mlx,
				data->WE, &texture[WEST].width,
				&texture[WEST].height)))
		i = err_msg("WE file xpm", data->WE, 1);
    if (i != 0)
		destroy_xpm(data);
    get_addr(texture);
}
