/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 11:58:54 by ssoumill          #+#    #+#             */
/*   Updated: 2025/03/29 12:52:25 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	handle_error(t_data *data)
{
	(void)data;
}

void	init_data(t_data *data)
{
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
	data->pos_x = 0;
	data->pos_y = 0;
    data->nbr_line = 0;
	data->larg_row = 0;
}

int	init_window(t_data *data)
{
	data->mlx = mlx_init();
	//data->mlx = NULL;
	if (!data->mlx)
		return (err_msg(ERROR_MLX_INIT, NULL, 0));
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Hulahup Barbatruc");
	if (!data->win)
		return (err_msg(ERROR_WIN_INIT, NULL, 0));
	return(1);
}