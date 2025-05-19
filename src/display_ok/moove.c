/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:35:57 by ssoumill          #+#    #+#             */
/*   Updated: 2025/05/19 16:52:24 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	moove_up(t_data *data)
{
	float	new_y;
	float	new_x;
	int		signe_x;
	int		signe_y;

	if (sin(deg_to_rad(data->player->pa) > 0.0))
		signe_y = -1;
	else
		signe_y = -1;
	if (cos(deg_to_rad(data->player->pa) < 0.0))
		signe_x = 1;
    else
		signe_x = -1;
	new_y = data->player->pos_y - ((float)sin(deg_to_rad(data->player->pa))
			* MOVE_SPEED * data->speed_factor);
	new_x = data->player->pos_x + ((float)cos(deg_to_rad(data->player->pa))
			* MOVE_SPEED * data->speed_factor);
	if (new_y >= (data->nbr_line) * 64 || new_y <= 0
		|| new_x >= (data->larg_row) * 64 || new_x <= 0)
		return ;
	if (data->map[(int)((new_y / (float)SQUARE_SIZE) + OFFSET
			* signe_y)][(int)((new_x / (float)SQUARE_SIZE) + OFFSET
			* signe_x)] == '1')
		return ;
	data->player->pos_x = new_x;
	data->player->pos_y = new_y;
}


void move_down(t_data *data)
{
    float new_x, new_y;
    int grid_x, grid_y;
    float offset = 0.2; // Même principe d’offset pour éviter les erreurs d’arrondi

    new_x = data->player->pos_x - cos(deg_to_rad(data->player->pa)) * MOVE_SPEED * data->speed_factor;
    new_y = data->player->pos_y + sin(deg_to_rad(data->player->pa)) * MOVE_SPEED * data->speed_factor;

    grid_x = (int)(new_x / SQUARE_SIZE - (offset * copysign(1, cos(deg_to_rad(data->player->pa)))));
    grid_y = (int)(new_y / SQUARE_SIZE - (offset * copysign(1, sin(deg_to_rad(data->player->pa)))));

    if (data->map[grid_y][grid_x] == '1')
        return;

    data->player->pos_x = new_x;
    data->player->pos_y = new_y;
}


void	moove_down(t_data *data)
{
	float	new_y;
	float	new_x;
    int		signe_x;
	int		signe_y;

	if (sin(deg_to_rad(data->player->pa) > 0.0))
		signe_y = -1;
	else
		signe_y = 1;
	if (cos(deg_to_rad(data->player->pa) < 0.0))
		signe_x = -1;
    else
		signe_x = 1;
	new_y = data->player->pos_y + ((float)sin(deg_to_rad(data->player->pa))
			* MOVE_SPEED * data->speed_factor);
	new_x = data->player->pos_x - ((float)cos(deg_to_rad(data->player->pa))
			* MOVE_SPEED * data->speed_factor);
	if (new_y >= data->nbr_line * 64 || new_y <= 0 || new_x >= data->larg_row
		* 64 || new_x <= 0)
		return ;
    if (data->map[(int)((new_y / (float)SQUARE_SIZE) - OFFSET
			* signe_y)][(int)((new_x / (float)SQUARE_SIZE) - OFFSET
			* signe_x)] == '1')
		return ;
	data->player->pos_x = new_x;
	data->player->pos_y = new_y;
}

void	moove_left(t_data *data)
{
	float	new_y;
	float	new_x;

	new_y = data->player->pos_y - ((float)cos(deg_to_rad(data->player->pa))
			* MOVE_SPEED * data->speed_factor);
	new_x = data->player->pos_x - ((float)sin(deg_to_rad(data->player->pa))
			* MOVE_SPEED * data->speed_factor);
	if (new_y >= data->nbr_line * 64 || new_y <= 0 || new_x >= data->larg_row
		* 64 || new_x <= 0)
		return ;
	if (data->map[(int)((new_y / (float)SQUARE_SIZE) + 0.3)][(int)((new_x
				/ (float)SQUARE_SIZE) + 0.3)] == '1')
		return ;
	data->player->pos_x = new_x;
	data->player->pos_y = new_y;
}

void	moove_right(t_data *data)
{
	float	new_y;
	float	new_x;

	new_y = data->player->pos_y + ((float)cos(deg_to_rad(data->player->pa))
			* MOVE_SPEED * data->speed_factor);
	new_x = data->player->pos_x + ((float)sin(deg_to_rad(data->player->pa))
			* MOVE_SPEED * data->speed_factor);
	if (new_y >= data->nbr_line * 64 || new_y <= 0 || new_x >= data->larg_row
		* 64 || new_x <= 0)
		return ;
	if (data->map[(int)((new_y / (float)SQUARE_SIZE) - 0.3)][(int)((new_x
				/ (float)SQUARE_SIZE) - 0.3)] == '1')
		return ;
	data->player->pos_x = new_x;
	data->player->pos_y = new_y;
}

void	ft_rotate(t_data *data)
{
	if (data->key.key_r == 1)
		data->player->pa -= 2 * ROT_SPEED * data->speed_factor;
	if (data->key.key_l == 1)
		data->player->pa += 2 * ROT_SPEED * data->speed_factor;
    data->player->pa = fix_angle(data->player->pa);
	data->player->pdx = cos((data->player->pa) * PI / 180);
	data->player->pdy = -sin((data->player->pa) * PI / 180);
}
