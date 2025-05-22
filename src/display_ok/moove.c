/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:35:57 by ssoumill          #+#    #+#             */
/*   Updated: 2025/05/20 20:04:35 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	check_offset(t_data *data, int *xo, int *yo, char dir)
{
	if (dir == 'v')
	{
		if (data->player->pdx < 0)
			*xo = -20;
		else
			*xo = 20;
		if (data->player->pdy < 0)
			*yo = -20;
		else
			*yo = 20;
	}
	if (dir == 'h')
	{
		if (data->player->pdx <0)
			*xo = 20;
		else
			*xo = -20;
		if (data->player->pdy < 0)
			*yo = 20;
		else
			*yo = -20;
	}
}

void moove_up(t_data *data)
{
    int xo, yo;
	float	new_y;
	float	new_x;

    check_offset(data, &xo, &yo, 'v');
	new_y = data->player->pos_y + (data->player->pdy * (float)MOVE_SPEED);
	new_x = data->player->pos_x + (data->player->pdx * (float)MOVE_SPEED);
    if (data->map[(int)((new_y + yo)/ (float)SQUARE_SIZE)]
                 [(int)(data->player->pos_x / (float)SQUARE_SIZE)] != '1')
    {
        data->player->pos_y = new_y;
    }
    if (data->map[(int)(data->player->pos_y / (float)SQUARE_SIZE)]
                 [(int)( (new_x  + xo)/ (float)SQUARE_SIZE)] != '1')
    {
        data->player->pos_x = new_x;
    }
}

void moove_down(t_data *data)
{
    int xo, yo;
	float	new_y;
	float	new_x;

    check_offset(data, &xo, &yo, 'v');
	new_y = data->player->pos_y - (data->player->pdy * (float)MOVE_SPEED);
	new_x = data->player->pos_x - (data->player->pdx * (float) MOVE_SPEED);
    if (data->map[(int)((new_y - yo)/ (float)SQUARE_SIZE)]
                 [(int)(data->player->pos_x / (float)SQUARE_SIZE)] != '1')
    {
        data->player->pos_y = new_y;
    }
    if (data->map[(int)(data->player->pos_y / (float)SQUARE_SIZE)]
                 [(int)( (new_x  - xo)/ (float)SQUARE_SIZE)] != '1')
    {
        data->player->pos_x = new_x;
    }
}


// void moove_left(t_data *data)
// {
//     int xo, yo;
// 	float	new_y;
// 	float	new_x;

//     check_offset(data, &xo, &yo, 'h');
// 	printf("%f %i\n", data->player->pdx, xo);
// 	new_y = data->player->pos_y - (data->player->pdy * (float)MOVE_SPEED);
// 	new_x = data->player->pos_x - (data->player->pdx * (float) MOVE_SPEED);
//     if (data->map[(int)((new_y - yo)/ (float)SQUARE_SIZE)]
//                  [(int)(data->player->pos_x / (float)SQUARE_SIZE)] != '1')
//     {
//         data->player->pos_y = new_y;
//     }
//     if (data->map[(int)(data->player->pos_y / (float)SQUARE_SIZE)]
//                  [(int)( (new_x - xo)/ (float)SQUARE_SIZE)] != '1')
//     {
//         data->player->pos_x = new_x;
//     }
// }



void	moove_left(t_data *data)
{
	float	new_y;
	float	new_x;
	int xo, yo;
	
    check_offset(data, &xo, &yo, 'h');
	new_y = data->player->pos_y - ((float)cos(deg_to_rad(data->player->pa))
			* MOVE_SPEED * data->speed_factor);
	new_x = data->player->pos_x - ((float)sin(deg_to_rad(data->player->pa))
			* MOVE_SPEED * data->speed_factor);
	if (new_y >= data->nbr_line * 64 || new_y <= 0 || new_x >= data->larg_row
		* 64 || new_x <= 0)
		return ;
	if (data->map[(int)(((new_y + (float)yo) / (float)SQUARE_SIZE))][(int)((new_x - (float)xo)
				/ (float)SQUARE_SIZE)] == '1')
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
	data->player->posdxp = sin((data->player->pa) * PI / 180);
	data->player->posdyp = cos((data->player->pa) * PI / 180);
}
