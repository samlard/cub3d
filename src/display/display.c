/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:35:57 by ssoumill          #+#    #+#             */
/*   Updated: 2025/04/23 18:25:03 by ssoumill         ###   ########.fr       */
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

void	drawPlayer(t_data *data)
{
	int	x2;
	int	y2;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
	int	playerSize;
	int	x1;
	int	y1;

	playerSize = 4;
	// Taille du carré représentant le joueur (16x16 pixels)
	// Dessiner un carré représentant le joueur
	if (data->key.key_w == 1)
		moove_up(data);
	if (data->key.key_s == 1)
		moove_down(data);
	if (data->key.key_a == 1)
		moove_left(data);
	if (data->key.key_d == 1)
		moove_right(data);
	if (data->key.key_l == 1 || data->key.key_r == 1)
		ft_rotate(data);
	for (int i = data->player->pos_x; i < data->player->pos_x + playerSize; i++)
	{
		for (int j = data->player->pos_y; j < data->player->pos_y
				+ playerSize; j++)
		{
			my_pixel_put(data, i, j, 0xFF0000);
			//mlx_pixel_put(data->mlx, data->win, i, j, 0xFFFF00);
			// 0xFFFF00 est la couleur jaune
		}
	}
	// Dessiner une ligne (représente la direction)
	x1 = data->player->pos_x + playerSize / 2;
	// Centrer la ligne à l'intérieur du carré
	y1 = data->player->pos_y + playerSize / 2;
	// Centrer la ligne à l'intérieur du carré
	x2 = x1 + data->player->pdx * 20;
	y2 = y1 + data->player->pdy * 20;
	// Algorithme de tracé de ligne de Bresenham pour dessiner une ligne entre (x1,y1) et (x2,y2)
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	sx = (x1 < x2) ? 1 : -1;
	sy = (y1 < y2) ? 1 : -1;
	err = dx - dy;
	while (1)
	{
		my_pixel_put(data, x1, y1, 0xFF0000);
		//my_pixel_put(data->mlx, data->win, x1, y1, 0xFFFF00);
		// Tracer la ligne en jaune
		if (x1 == x2 && y1 == y2)
			break ;
		e2 = err * 2;
		if (e2 > -dy)
		{
			err -= dy;
			x1 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y1 += sy;
		}
	}
}

void	draw_map(t_data *data)
{
	int	color;
	int	x;
	int	y;

	int xo, yo;
	x = 0;
	while (data->map[x]) // Parcourt les lignes de la carte
	{
		y = 0;
		while (data->map[x][y]) // Parcourt les colonnes de chaque ligne
		{
			xo = y * SQUARE_SIZE;
			// Calcul le point de depart pour dessiner le carre si indice (0;0) alors commence coin sup gauche
			yo = x * SQUARE_SIZE;
			if (data->map[x][y] == '1' || data->map[x][y] == ' ')
				// Si c'est un "mur" ou un case espace
				color = 0x000000;
			else
				color = 0xFFFFFF;
			int i, j;
			for (i = xo; i < xo + SQUARE_SIZE; i++)
			{
				for (j = yo; j < yo + SQUARE_SIZE; j++)
					my_pixel_put(data, i, j, color);
			}
			y++; // Passer à la colonne suivante
		}
		x++; // Passer à la ligne suivante
	}
	x = 0;
	while (x < data->larg_row * 64) // Parcourt les lignes de la carte
	{
		y = 0;
		while (y < data->nbr_line * 64) // Parcourt les colonnes de chaque ligne
		{
			color = 0xFFF00;
			my_pixel_put(data, x, y, color);
			my_pixel_put(data, y, x, color);
			y++; // Passer à la colonne suivante
		}
		x += SQUARE_SIZE; // Passer à la ligne suivante
	}
}



void	draw_ray(t_data *data)
{
	float	ra;
	float	Tan;
	float	px;
	float	py;
	int		map_x;
	int		map_y;
	int		x;
	float	xo;
	float	yo;
	float	h_dist;
	float	v_dist;
	int		i = 0;
	xo = 0;
	yo = 0;
	float rx, ry;
	float rx_v, ry_v;
	px = data->player->pos_x;
	py = data->player->pos_y;
	rx = 0;
	ry = 0;
	x = 0;
	ra = data->player->pa;
	ra -= 30;
	while (x < 60)
	{
		h_dist = 0;
		v_dist = 0;
		if (ra >= 360)
			ra -= 360;
		if (ra < 0)
			ra += 360;
		Tan = tan(deg_to_rad(ra));
		if (cos(deg_to_rad(ra)) > 0.0001)
		{
			rx_v = ((int)(px / 64)) * 64 + 64;
			ry_v = (px - rx_v) * Tan + py;
			xo = 64;
			yo = -64 * Tan;
		}
		else if (cos(deg_to_rad(ra)) < 0.0001)
		{
			rx_v = ((int)(px / 64))* 64 -0.0001 ;
			ry_v = (px - rx_v) * Tan + py;
			xo = -64;
			yo = 64 * Tan;
		}
		else 
		{
			rx_v = px;
			ry_v = py;
			if (ra > 80 && ra < 100)
				yo = -64;
			else
				yo = 64;
			xo = 0;
		}
		while (i < 8)
		{
			map_x = (int)(rx_v / 64);
			map_y = (int)(ry_v / 64);
			if (map_x < 0 || map_x >= data->larg_row || map_y < 0
				|| map_y >= data->nbr_line)
				{
					v_dist = 8 * 64;
					break ;
				}
			// if (rx_v > (data->larg_row -1) * 64 && rx_v <= 0 && ry_v <= 0
			// 	&& ry_v > (data->nbr_line -1 ) * 64)
			// 	break;
			if (data->map[map_y][map_x] == '1')
			{
				v_dist = sqrtf((px - rx_v) * (px - rx_v) + (py - ry_v) * (py - ry_v));
				break ;
			}
			rx_v += xo;
			ry_v += yo;
			i++;
		}
		i = 0;
		Tan = 1 / tan(deg_to_rad(ra));
		if (sin(deg_to_rad(ra)) > 0.0001)
		{
			ry = ((int)(py / 64)) * 64 - 0.001;
			rx = (py - ry) * Tan + px;
			yo = -64;
			xo = -yo * Tan;
		}
		else if (sin(deg_to_rad(ra)) < -0.0001)
		{
			ry = ((int)(py / 64))* 64 + 64;
			rx = (py - ry) * Tan + px;
			yo = 64;
			xo = -yo * Tan;
		}
		else
		{
			rx = px;
			ry = py;
			if (ra > 170 && ra < 190)
				xo = -64;
			else 
				xo = 64;
			yo = 0;
		}
		while (i < 8)
		{
			map_x = (int)(rx / 64);
			map_y = (int)(ry / 64);
			if (map_x < 0 || map_x >= data->larg_row || map_y < 0
				|| map_y >= data->nbr_line)
				{
					h_dist = 8 * 64;
					break ;
				}
			
			// if (rx > (data->larg_row -1) * 64 && rx <= 0 && ry <= 0
			// 	&& ry > (data->nbr_line + 1) * 64)
			// 	break;
			if (data->map[map_y][map_x] == '1')
			{
				h_dist = sqrtf((px - rx) * (px - rx) + (py - ry) * (py - ry));
				break ;
			}
			rx += xo;
			ry += yo;
			i++;
		}
		i = 0;
		printf("v_dist = %f\n h_dist = %f\n", v_dist, h_dist);
		if (v_dist < h_dist)
		{
			my_pixel_put(data, rx_v, ry_v, 0xFF0000);
		}
		else
			my_pixel_put(data, rx, ry, 0xFF0000);
		ra++;
		x++;
	}
}
	// x = 0;
	// ra-=60;
	// while (x < 60)
	// {
	// 	xo = 0;
	// 	if (ra > 360)
	// 		ra -= 360;
	// 	Tan = 1 / tan(deg_to_rad(ra));
	// 	if (sin(deg_to_rad(ra)) > 0.0001)
	// 	{
	// 		ry = ((int)(py / 64)) * 64 - 0.001;
	// 		rx = (py - ry) * Tan + px;
	// 		yo = -64;
	// 		xo = -yo * Tan;
	// 	}
	// 	else if (sin(deg_to_rad(ra)) < -0.0001)
	// 	{
	// 		ry = ((int)(py / 64))* 64 + 64;
	// 		rx = (py - ry) * Tan + px;
	// 		yo = 64;
	// 		xo = -yo * Tan;
	// 	}
	// 	else
	// 	{
	// 		rx = 0;
	// 		ry = 0;
	// 	}
	// 	while (i < 1500)
	// 	{
	// 		map_x = (int)(rx / 64);
	// 		map_y = (int)(ry / 64);
	// 		if (map_x < 0 || map_x >= data->larg_row || map_y < 0
	// 			|| map_y >= data->nbr_line)
	// 			break ;
	// 		else if (data->map[map_y][map_x] == '1')
	// 			break ;
	// 		else if (rx < (data->larg_row -1) * 64 && rx >= 0 && ry >= 0
	// 			&& ry < data->nbr_line * 64)
	// 			my_pixel_put(data, rx, ry, 0xFF0000);
	// 		rx += xo/200;
	// 		ry += yo/200;
	// 		i++;
	// 	}
	// 	i = 0;
	// 	ra++;
	// 	x++;
	// }
// }
// // void	draw_ray(t_data *data)
// {
// 	float	ra = data->player->pa - 30;
// 	float	px = data->player->pos_x;
// 	float	py = data->player->pos_y;

// 	if (ra < 0)
// 		ra += 360;

// 	for (int x = 0; x < 60; x++, ra++)
// 	{
// 		if (ra > 360)
// 			ra -= 360;

// 		float hor_rx, hor_ry, vert_rx, vert_ry;
// 		float hor_dist = 1e30, vert_dist = 1e30;
// 		float Tan = tan(deg_to_rad(ra));
// 		float xo, yo;
// 		int map_x, map_y;
// 		int i;

// 		// --- Vertical Raycasting ---
// 		float ra_rad = deg_to_rad(ra);
// 		i = 0;

// 		if (cos(ra_rad) > 0.0001) // Looking right
// 		{
// 			vert_rx = ((int)(px / 64)) * 64 + 64;
// 			vert_ry = (px - vert_rx) * Tan + py;
// 			xo = 64;
// 			yo = -64 * Tan;
// 		}
// 		else if (cos(ra_rad) < -0.0001) // Looking left
// 		{
// 			vert_rx = ((int)(px / 64)) * 64 - 0.0001;
// 			vert_ry = (px - vert_rx) * Tan + py;
// 			xo = -64;
// 			yo = 64 * Tan;
// 		}
// 		else
// 		{
// 			vert_rx = px;
// 			vert_ry = py;
// 			xo = yo = 0;
// 			i = 1500;
// 		}

// 		while (i < 1500)
// 		{
// 			map_x = (int)(vert_rx / 64);
// 			map_y = (int)(vert_ry / 64);
// 			if (map_x < 0 || map_x >= data->larg_row || map_y < 0 || map_y >= data->nbr_line)
// 				break;
// 			if (data->map[map_y][map_x] == '1')
// 			{
// 				vert_dist = sqrtf((vert_rx - px) * (vert_rx - px) + (vert_ry - py) * (vert_ry - py));
// 				break;
// 			}
// 			vert_rx += xo;
// 			vert_ry += yo;
// 			i++;
// 		}

// 		// --- Horizontal Raycasting ---
// 		Tan = 1 / Tan;
// 		i = 0;

// 		if (sin(ra_rad) > 0.0001) // Looking up
// 		{
// 			hor_ry = ((int)(py / 64)) * 64 - 0.0001;
// 			hor_rx = (py - hor_ry) * Tan + px;
// 			yo = -64;
// 			xo = -yo * Tan;
// 		}
// 		else if (sin(ra_rad) < -0.0001) // Looking down
// 		{
// 			hor_ry = ((int)(py / 64)) * 64 + 64;
// 			hor_rx = (py - hor_ry) * Tan + px;
// 			yo = 64;
// 			xo = -yo * Tan;
// 		}
// 		else
// 		{
// 			hor_rx = px;
// 			hor_ry = py;
// 			xo = yo = 0;
// 			i = 1500;
// 		}

// 		while (i < 1500)
// 		{
// 			map_x = (int)(hor_rx / 64);
// 			map_y = (int)(hor_ry / 64);
// 			if (map_x < 0 || map_x >= data->larg_row || map_y < 0 || map_y >= data->nbr_line)
// 				break;
// 			if (data->map[map_y][map_x] == '1')
// 			{
// 				hor_dist = sqrtf((hor_rx - px) * (hor_rx - px) + (hor_ry - py) * (hor_ry - py));
// 				break;
// 			}
// 			hor_rx += xo;
// 			hor_ry += yo;
// 			i++;
// 		}

// 		// --- Draw the shortest ray ---
// 		if (hor_dist < vert_dist)
// 			my_pixel_put(data, hor_rx, hor_ry, 0xFF0000);
// 		else
// 			my_pixel_put(data, vert_rx, vert_ry, 0xFF0000);
// 	}
// }


//float y = Tan * (px - rx) + py;
// Calcul de la coordonnée y avec la formule d'une droite

int	display(t_data *data)
{
	clear_image(data, 0x000000);
	draw_map(data);
	drawPlayer(data);
	draw_ray(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}