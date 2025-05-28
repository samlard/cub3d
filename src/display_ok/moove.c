/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:35:57 by ssoumill          #+#    #+#             */
/*   Updated: 2025/05/21 17:06:02 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	move_up(t_data *data)
{
	int	xo;
	int	yo;

	if (data->player->pdx > 0)
		xo = 10;
	else
		xo = -10;
	if (data->player->pdy > 0)
		yo = 10;
	else
		yo = -10;
	if (data->map[(int)((data->player->pos_y + yo) / SQUARE_SIZE)]
					[(int)((data->player->pos_x) / SQUARE_SIZE)] != '1')
		data->player->pos_y += (data->player->pdy * MOVE_SPEED);
	if (data->map[(int)((data->player->pos_y) / SQUARE_SIZE)]
					[(int)((data->player->pos_x + xo) / SQUARE_SIZE)] != '1')
		data->player->pos_x += (data->player->pdx * MOVE_SPEED);
}

void	move_down(t_data *data)
{
	int	xo;
	int	yo;

	if (data->player->pdx > 0)
		xo = -10;
	else
		xo = 10;
	if (data->player->pdy > 0)
		yo = -10;
	else
		yo = 10;
	if (data->map[(int)((data->player->pos_y + yo) / SQUARE_SIZE)]
					[(int)((data->player->pos_x) / SQUARE_SIZE)] != '1')
		data->player->pos_y -= (data->player->pdy * MOVE_SPEED);
	if (data->map[(int)((data->player->pos_y) / SQUARE_SIZE)]
					[(int)((data->player->pos_x + xo) / SQUARE_SIZE)] != '1')
		data->player->pos_x -= (data->player->pdx * MOVE_SPEED);
}

void	move_left(t_data *data)
{
	int	xo;
	int	yo;

	if (data->player->pdy > 0)
		xo = 10;
	else
		xo = -10;
	if (data->player->pdx > 0)
		yo = -10;
	else
		yo = 10;
	if (data->map[(int)((data->player->pos_y + yo) / SQUARE_SIZE)]
					[(int)((data->player->pos_x) / SQUARE_SIZE)] != '1')
		data->player->pos_y -= (data->player->pdx * MOVE_SPEED);
	if (data->map[(int)((data->player->pos_y) / SQUARE_SIZE)]
					[(int)((data->player->pos_x + xo) / SQUARE_SIZE)] != '1')
		data->player->pos_x += (data->player->pdy * MOVE_SPEED);
}

void	move_right(t_data *data)
{
	int	xo;
	int	yo;

	if (data->player->pdy > 0)
		xo = -10;
	else
		xo = 10;
	if (data->player->pdx > 0)
		yo = 10;
	else
		yo = -10;
	if (data->map[(int)((data->player->pos_y + yo) / SQUARE_SIZE)]
					[(int)((data->player->pos_x) / SQUARE_SIZE)] != '1')
		data->player->pos_y += (data->player->pdx * MOVE_SPEED);
	if (data->map[(int)((data->player->pos_y) / SQUARE_SIZE)]
					[(int)((data->player->pos_x + xo) / SQUARE_SIZE)] != '1')
		data->player->pos_x -= (data->player->pdy * MOVE_SPEED);
}

void	ft_rotate(t_data *data)
{
	if (data->key.key_r == 1)
		data->player->pa -= ROT_SPEED;
	if (data->key.key_l == 1)
		data->player->pa += ROT_SPEED;
	data->player->pa = fix_angle(data->player->pa);
	data->player->pdx = cos(deg_to_rad(data->player->pa));
	data->player->pdy = -sin(deg_to_rad(data->player->pa));
}
