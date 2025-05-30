/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tete.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:35:57 by ssoumill          #+#    #+#             */
/*   Updated: 2025/05/30 18:27:52 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	destroy_xpm(t_data *data)
{
	if (data->texture[NORTH].img)
	{
		mlx_destroy_image(data->mlx, data->texture[NORTH].img);
		data->texture[NORTH].img = NULL;
	}
	if (data->texture[SOUTH].img)
	{
		mlx_destroy_image(data->mlx, data->texture[SOUTH].img);
		data->texture[SOUTH].img = NULL;
	}
	if (data->texture[EAST].img)
	{
		mlx_destroy_image(data->mlx, data->texture[EAST].img);
		data->texture[EAST].img = NULL;
	}
	if (data->texture[WEST].img)
	{
		mlx_destroy_image(data->mlx, data->texture[WEST].img);
		data->texture[WEST].img = NULL;
	}
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	ft_free_texture(data);
	close(data->fd_map);
}

void	get_addr(t_texture *texture)
{
	texture[NORTH].addr = mlx_get_data_addr(texture[NORTH].img,
			&texture[NORTH].bpp,
			&texture[NORTH].size_line,
			&texture[NORTH].endian);
	texture[SOUTH].addr = mlx_get_data_addr(texture[SOUTH].img,
			&texture[SOUTH].bpp,
			&texture[SOUTH].size_line,
			&texture[SOUTH].endian);
	texture[EAST].addr = mlx_get_data_addr(texture[EAST].img,
			&texture[EAST].bpp,
			&texture[EAST].size_line,
			&texture[EAST].endian);
	texture[WEST].addr = mlx_get_data_addr(texture[WEST].img,
			&texture[WEST].bpp,
			&texture[WEST].size_line,
			&texture[WEST].endian);
}

void	get_xpm2(t_data *data, t_texture *texture)
{
	texture[EAST].img = mlx_xpm_file_to_image(data->mlx,
			data->east,
			&texture[EAST].width,
			&texture[EAST].height);
	if (!texture[EAST].img)
	{
		err_msg("EA file xpm", data->east, 1);
		handle_error(data, 2);
	}
	texture[WEST].img = mlx_xpm_file_to_image(data->mlx,
			data->west,
			&texture[WEST].width,
			&texture[WEST].height);
	if (!texture[WEST].img)
	{
		err_msg("WE file xpm", data->west, 1);
		handle_error(data, 2);
	}
	get_addr(texture);
}

void	get_xpm(t_data *data)
{
	t_texture	*texture;

	texture = data->texture;
	texture[NORTH].img = mlx_xpm_file_to_image(data->mlx,
			data->north,
			&texture[NORTH].width,
			&texture[NORTH].height);
	if (!texture[NORTH].img)
	{
		err_msg("NO file xpm", data->north, 1);
		handle_error(data, 2);
	}
	texture[SOUTH].img = mlx_xpm_file_to_image(data->mlx,
			data->south,
			&texture[SOUTH].width,
			&texture[SOUTH].height);
	if (!texture[SOUTH].img)
	{
		err_msg("SO file xpm", data->south, 1);
		handle_error(data, 2);
	}
	get_xpm2(data, texture);
}
