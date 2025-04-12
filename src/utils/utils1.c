/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 11:58:54 by ssoumill          #+#    #+#             */
/*   Updated: 2025/04/12 15:14:04 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	handle_error(t_data *data)
{
	(void)data;
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
	data->count_direction = 0;
	data->count_player = 0;
	data->handle_error = 0;
	data->NO = NULL;
	data->SO = NULL;
	data->EA = NULL;
	data->WE = NULL;
	data->F = NULL;
	data->C = NULL;
	data->flag = 0;
	data->player->pos_x = 0;
	data->player->pos_y = 0;
	data->player->pa = 90;
	data->player->pdx = cos((data->player->pa) * PI / 180);
	data->player->pdy = -sin((data->player->pa) * PI/ 180);
	data->nbr_line = 0;
	data->larg_row = 0;
	data->key.key_w = 0;
	data->key.key_s = 0;
	data->key.key_a = 0;
	data->key.key_d= 0;
	data->key.key_l= 0;
	data->key.key_r= 0;
}

int	init_window(t_data *data)
{
	data->mlx = mlx_init();
	//data->mlx = NULL;
	if (!data->mlx)
		return (err_msg(ERROR_MLX_INIT, NULL, 0));
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT,
			"Hulahup Barbatruc");
	if (!data->win)
		return (err_msg(ERROR_WIN_INIT, NULL, 0));
	data->player->pos_x = data->player->pos_x * 64;
	data->player->pos_y = data->player->pos_y * 64;
	return (1);
}