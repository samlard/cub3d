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

// void	check_offset(t_data *data, int *xo, int *yo, char dir)
// {
// 	if (dir == 'h')
// 	{
// 		if (data->player->pdx < 0)
// 			*xo = -20;
// 		else
// 			if (data->player->pdx < 0)
// 			*xo = 20;
// 		if (data->player->pdy < 0)
// 			*yo = -20;
// 		else
// 			*xo = -20;
// 		if (data->player->pdy < 0)
// 			*yo = 20;
// 		else
// 			*yo = -20;
// 	}
// }
// // int		check_border(t_data *data)
// // {
// // 	if (data->player->pdx > 0)
// // 	{
// // 		if(data->player->pdy < 0)
// // 		{
// // 			if (data->map[(int)((data->player->pos_y - SQUARE_SIZE)
// 						/ SQUARE_SIZE)]
// // 					[(int)((data->player->pos_x + SQUARE_SIZE)
// 							/ SQUARE_SIZE)] == '1')
// // 			{
// // 				if (data->player->pos_y - (floorf(data->player->pos_y
// 								/ SQUARE_SIZE) * SQUARE_SIZE) < 20
// 						&& (ceilf(data->player->pos_x / SQUARE_SIZE)
// 							* SQUARE_SIZE) - data->player->pos_x < 20)
// // 					return (0);
// // 				return (1);
// // 			}
// // 		}
// // 		else
// // 		{
// // 			if (data->map[(int)((data->player->pos_y + SQUARE_SIZE)
// 						/ SQUARE_SIZE)]
// // 					[(int)((data->player->pos_x + SQUARE_SIZE)
// 							/ SQUARE_SIZE)] == '1')
// // 			{
// // 				if ((ceilf(data->player->pos_y / SQUARE_SIZE) * SQUARE_SIZE)
// 						- data->player->pos_y < 20 && (ceilf(data->player->pos_x
// 								/ SQUARE_SIZE) * SQUARE_SIZE)
// 						- data->player->pos_x < 20)
// // 					return (0);
// // 				return (1);
// // 			}
// // 		}
// // 	}
// // 	else
// // 	{
// // 		if(data->player->pdy < 0)
// // 		{
// // 			if (data->map[(int)((data->player->pos_y - SQUARE_SIZE)
// 						/ SQUARE_SIZE)]
// // 			[(int)((data->player->pos_x - SQUARE_SIZE)
				//	/ SQUARE_SIZE)] == '1')
// // 			{
// // 				if (data->player->pos_y - (floorf(data->player->pos_y
// 								/ SQUARE_SIZE) * SQUARE_SIZE) < 20
// 						&& (data->player->pos_x - floorf(data->player->pos_x
// 								/ SQUARE_SIZE) * SQUARE_SIZE) < 20)
// // 					return (0);
// // 				return (1);
// // 			}
// // 		}
// // 		else
// // 		{
// // 			if (data->map[(int)((data->player->pos_y + SQUARE_SIZE)
// 						/ SQUARE_SIZE)]
// // 					[(int)((data->player->pos_x - SQUARE_SIZE)
// 							/ SQUARE_SIZE)] == '1')
// // 			{
// // 				if ((ceilf(data->player->pos_y / SQUARE_SIZE) * SQUARE_SIZE)
// 						- data->player->pos_y < 20
// 						&& (floorf(data->player->pos_x / SQUARE_SIZE)
// 							* SQUARE_SIZE) - data->player->pos_x < 20)
// // 					return (0);
// // 				return (1);

// // 			}

// // 		}

// // 	}
// // 	return (1);
// // }

// int check_cord(t_data *data)
// {
//     if (data->wall_hit[UP_RIGHT] &&
//         (data->player->pos_y - (floorf(data->player->pos_y / SQUARE_SIZE) * SQUARE_SIZE) < 20) &&
//         ((ceilf(data->player->pos_x / SQUARE_SIZE) * SQUARE_SIZE) - data->player->pos_x < 20))
//         return (1); // Empêche le joueur d'aller dans le coin haut droit
    
//     if (data->wall_hit[UP_LEFT] &&
//         (data->player->pos_y - (floorf(data->player->pos_y / SQUARE_SIZE) * SQUARE_SIZE) < 20) &&
//         (data->player->pos_x - floorf(data->player->pos_x / SQUARE_SIZE) * SQUARE_SIZE < 20))
//         return (1); // Empêche le joueur d'aller dans le coin haut gauche

//     if (data->wall_hit[DOWN_RIGHT] &&
//         (ceilf(data->player->pos_y / SQUARE_SIZE) * SQUARE_SIZE - data->player->pos_y < 20) &&
//         (ceilf(data->player->pos_x / SQUARE_SIZE) * SQUARE_SIZE - data->player->pos_x < 20))
//         return (1); // Empêche le joueur d'aller dans le coin bas droit

//     if (data->wall_hit[DOWN_LEFT] &&
//         (ceilf(data->player->pos_y / SQUARE_SIZE) * SQUARE_SIZE - data->player->pos_y < 20) &&
//         (data->player->pos_x - floorf(data->player->pos_x / SQUARE_SIZE) * SQUARE_SIZE < 20))
//         return (1); // Empêche le joueur d'aller dans le coin bas gauche

//     return (0);
// }

void reset_wall(t_data *data)
{
	data->wall_hit[UP_RIGHT] = 0;
	data->wall_hit[UP_LEFT] = 0;
	data->wall_hit[DOWN_RIGHT] = 0;
	data->wall_hit[DOWN_LEFT] = 0;
}


int check_cord_x(t_data *data)
{
    if ((data->wall_hit[UP_RIGHT] || data->wall_hit[DOWN_RIGHT]) &&
        (ceilf(data->player->pos_x / SQUARE_SIZE) * SQUARE_SIZE) - data->player->pos_x < 20)
        return (1); // Bloque l'entrée dans le coin à droite

    if ((data->wall_hit[UP_LEFT] || data->wall_hit[DOWN_LEFT]) &&
        (data->player->pos_x - floorf(data->player->pos_x / SQUARE_SIZE) * SQUARE_SIZE < 20))
        return (1); // Bloque l'entrée dans le coin à gauche

    return (0); // Sinon, X est libre
}

int check_cord_y(t_data *data)
{
    if ((data->wall_hit[UP_RIGHT] || data->wall_hit[UP_LEFT]) &&
        (data->player->pos_y - floorf(data->player->pos_y / SQUARE_SIZE) * SQUARE_SIZE < 20))
        return (1); // Bloque l'entrée dans le coin en haut

    if ((data->wall_hit[DOWN_RIGHT] || data->wall_hit[DOWN_LEFT]) &&
        (ceilf(data->player->pos_y / SQUARE_SIZE) * SQUARE_SIZE) - data->player->pos_y < 20)
        return (1); // Bloque l'entrée dans le coin en bas

    return (0); // Sinon, Y est libre
}


int	check_border(t_data *data, int i)
{
	if (data->map[(int)((data->player->pos_y - SQUARE_SIZE) / SQUARE_SIZE)]
					[(int)((data->player->pos_x + SQUARE_SIZE)
							/ SQUARE_SIZE)] == '1')
		data->wall_hit[UP_RIGHT] = 1;
	if (data->map[(int)((data->player->pos_y + SQUARE_SIZE) / SQUARE_SIZE)]
					[(int)((data->player->pos_x + SQUARE_SIZE)
							/ SQUARE_SIZE)] == '1')
		data->wall_hit[DOWN_RIGHT] = 1;
	if (data->map[(int)((data->player->pos_y - SQUARE_SIZE) / SQUARE_SIZE)]
					[(int)((data->player->pos_x - SQUARE_SIZE)
							/ SQUARE_SIZE)] == '1')
		data->wall_hit[UP_LEFT] = 1;
	if (data->map[(int)((data->player->pos_y + SQUARE_SIZE) / SQUARE_SIZE)]
		[(int)((data->player->pos_x - SQUARE_SIZE)
				/ SQUARE_SIZE)] == '1')
		data->wall_hit[DOWN_LEFT] = 1;
	if (i == 0)
	{
		if (check_cord_x(data))
			return (1);
	}
	else
	{
		if (check_cord_y(data))
			return (1);
	}
	return (0);
}
void	move_up(t_data *data)
{
	int	xo;
	int	yo;

	if (data->player->pdx > 0)
		xo = 20;
	else
		xo = -20;
	if (data->player->pdy > 0)
		yo = 20;
	else
		yo = -20;
	if (data->map[(int)((data->player->pos_y + yo) / SQUARE_SIZE)]
					[(int)((data->player->pos_x) / SQUARE_SIZE)] != '1' && !check_border(data, 1))
	{
		data->player->pos_y += (data->player->pdy * MOVE_SPEED);
		reset_wall(data);
	}
	if (data->map[(int)((data->player->pos_y) / SQUARE_SIZE)]
					[(int)((data->player->pos_x + xo) / SQUARE_SIZE)] != '1' && !check_border(data, 0))
	{
		data->player->pos_x += (data->player->pdx * MOVE_SPEED);
		reset_wall(data);
	}
}

void	move_down(t_data *data)
{
	int	xo;
	int	yo;

	reset_wall(data);
	if (data->player->pdx > 0)
		xo = -20;
	else
		xo = 20;
	if (data->player->pdy > 0)
		yo = -20;
	else
		yo = 20;
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
		xo = 20;
	else
		xo = -20;
	if (data->player->pdx > 0)
		yo = -20;
	else
		yo = 20;
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

	reset_wall(data);
	if (data->player->pdy > 0)
		xo = -20;
	else
		xo = 20;
	if (data->player->pdx > 0)
		yo = 20;
	else
		yo = -20;
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
