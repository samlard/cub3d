/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:35:57 by ssoumill          #+#    #+#             */
/*   Updated: 2025/04/25 11:03:19 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void    moove_up(t_data *data)
{
    float new_y;
    float  new_x;

    new_y = data->player->pos_y - (float) sin(deg_to_rad(data->player->pa)) * MOVE_SPEED;
    new_x = data->player->pos_x + (float) cos(deg_to_rad(data->player->pa)) * MOVE_SPEED;
    if (new_y >= data->nbr_line * 64 || new_y <= 0 || new_x >= data->larg_row * 64 || new_x <= 0)
        return;
    if (data->map[(int) (new_y /64.0f)][(int) (new_x /64.0f)] == '1')
        return;
    data->player->pos_x = new_x;
    data->player->pos_y = new_y;
}

void    moove_down(t_data *data)
{
    float new_y;
    float  new_x;

    new_y = data->player->pos_y + (float) sin(deg_to_rad(data->player->pa)) * MOVE_SPEED;
    new_x = data->player->pos_x - (float) cos(deg_to_rad(data->player->pa)) * MOVE_SPEED;
    if (new_y >= data->nbr_line * 64 || new_y <= 0 || new_x >= data->larg_row * 64 || new_x <= 0)
        return;
    if (data->map[(int) (new_y /64.0f)][(int) (new_x /64.0f)] == '1')
        return;
    data->player->pos_x = new_x;
    data->player->pos_y = new_y;
}

void    moove_left(t_data *data)
{
    float new_y;
    float  new_x;

    new_y = data->player->pos_y - (float) cos(deg_to_rad(data->player->pa)) * MOVE_SPEED;
    new_x = data->player->pos_x - (float) sin(deg_to_rad(data->player->pa)) * MOVE_SPEED;
    if (new_y >= data->nbr_line * 64 || new_y <= 0 || new_x >= data->larg_row * 64 || new_x <= 0)
        return;
    if (data->map[(int) (new_y /64.0f)][(int) (new_x /64.0f)] == '1')
        return;
    data->player->pos_x = new_x;
    data->player->pos_y = new_y;
}
    
void    moove_right(t_data *data)
{
    float new_y;
    float  new_x;

    new_y = data->player->pos_y + (float) cos(deg_to_rad(data->player->pa)) * MOVE_SPEED;
    new_x = data->player->pos_x + (float) sin(deg_to_rad(data->player->pa)) * MOVE_SPEED;
    if (new_y >= data->nbr_line * 64 || new_y <= 0 || new_x >= data->larg_row * 64 || new_x <= 0)
        return;
    if (data->map[(int) (new_y /64.0f)][(int) (new_x /64.0f)] == '1')
        return;
    data->player->pos_x = new_x;
    data->player->pos_y = new_y;
}

void	ft_rotate(t_data *data)
{
	if (data->player->pa >= 360 )
		data->player->pa = data->player->pa/360; 
	if (data->key.key_r == 1)
		data->player->pa-= 2;
	if (data->key.key_l == 1)
		data->player->pa+= 2;
	data->player->pdx = cos((data->player->pa) * PI / 180);
	data->player->pdy = -sin((data->player->pa) * PI/ 180);
}
