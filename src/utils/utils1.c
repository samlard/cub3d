/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 11:58:54 by ssoumill          #+#    #+#             */
/*   Updated: 2025/05/30 17:37:24 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	init_data_2(t_data *data)
{
	data->flag = 0;
	data->player->pos_x = 0;
	data->player->pos_y = 0;
	data->player->pa = 0;
	data->player->pdx = cos(deg_to_rad(data->player->pa));
	data->player->pdy = -sin(deg_to_rad(data->player->pa));
	data->nbr_line = 0;
	data->larg_row = 0;
}

void	init_data(t_data *data)
{
	data->player = malloc(sizeof(t_player) * 1);
	data->map = NULL;
	data->mlx = NULL;
	data->win = NULL;
	data->win_height = WIN_HEIGHT;
	data->win_width = WIN_WIDTH;
	data->fd_map = 0;
	data->map_first_line = NULL;
	data->count_texture = 0;
	data->count_player = 0;
	data->handle_error = 0;
	data->north = NULL;
	data->south = NULL;
	data->east = NULL;
	data->west = NULL;
	data->f = NULL;
	data->c = NULL;
	init_data_2(data);
	init_key(data);
}

void	init_key(t_data *data)
{
	data->key.key_w = 0;
	data->key.key_s = 0;
	data->key.key_a = 0;
	data->key.key_d = 0;
	data->key.key_l = 0;
	data->key.key_r = 0;
	data->f_f = 0;
	data->f_c = 0;
	data->f_ea = 0;
	data->f_we = 0;
	data->f_so = 0;
	data->f_no = 0;
}

int	init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (err_msg(ERROR_MLX_INIT, NULL, 0));
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT,
			"Hulahup Barbatruc");
	if (!data->win)
		return (err_msg(ERROR_WIN_INIT, NULL, 0));
	data->player->pos_x = data->player->pos_x * SQUARE_SIZE + 20;
	data->player->pos_y = data->player->pos_y * SQUARE_SIZE + 20;
	return (1);
}
