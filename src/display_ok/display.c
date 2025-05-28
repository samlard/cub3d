/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:35:57 by ssoumill          #+#    #+#             */
/*   Updated: 2025/05/28 20:48:38 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dest;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		dest = data->img_addr + (y * data->size_line + x * (data->bpp / 8));
		*(unsigned int *)dest = color;
	}
}

void	clear_image(t_data *data, int color)
{
	int	y;
	int	x;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
		{
			my_pixel_put(data, x, y, color);
		}
	}
}

int	key_pressed(t_key key)
{
	if (key.key_w == 1 || key.key_s == 1 || key.key_d == 1 || key.key_a == 1
		|| key.key_l == 1 || key.key_r == 1)
		return (1);
	return (0);
}

void	check_move(t_data *data)
{
	if (data->key.key_d == 1)
		move_left(data);
	if (data->key.key_a == 1)
		move_right(data);
	if (data->key.key_w == 1)
		move_up(data);
	if (data->key.key_s == 1)
		move_down(data);
	if (data->key.key_l == 1 || data->key.key_r == 1)
		ft_rotate(data);
}

int	display(t_data *data)
{
	clear_image(data, 0x000000);
	if (key_pressed(data->key))
	{
		check_move(data);
		draw_ray(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	return (0);
}