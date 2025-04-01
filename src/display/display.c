/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:35:57 by ssoumill          #+#    #+#             */
/*   Updated: 2025/04/01 16:05:52 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

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

	int playerSize = 16;
		// Taille du carré représentant le joueur (16x16 pixels)
	// Dessiner un carré représentant le joueur
	if (data->key.key_w == 1)
		data->player->pos_y-=1;
	if (data->key.key_s == 1)
		data->player->pos_y+=1;
	if (data->key.key_a == 1)
		data->player->pos_x -=1;
	if (data->key.key_d == 1)
		data->player->pos_x +=1;
		
	for (int i = data->player->pos_x; i < data->player->pos_x + playerSize; i++)
	{
		for (int j = data->player->pos_y; j < data->player->pos_y + playerSize; j++)
		{
			mlx_pixel_put(data->mlx, data->win, i, j, 0xFFFF00);
				// 0xFFFF00 est la couleur jaune
		}
	}
	// Dessiner une ligne (représente la direction)
	int x1 = data->player->pos_x + playerSize / 2;
		// Centrer la ligne à l'intérieur du carré
	int y1 = data->player->pos_y + playerSize / 2;
		// Centrer la ligne à l'intérieur du carré
	x2 = x1 + data->player->pdx * 20;
	y2 = y1 + data->player->pdx * 20;
	// Algorithme de tracé de ligne de Bresenham pour dessiner une ligne entre (x1,y1) et (x2, y2)
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	sx = (x1 < x2) ? 1 : -1;
	sy = (y1 < y2) ? 1 : -1;
	err = dx - dy;
	while (1)
	{
		mlx_pixel_put(data->mlx, data->win, x1, y1, 0xFFFF00);
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
	unsigned long	color;
	int				x;
	int				y;
	int xo, yo;
	x = 0;
	while (data->map[x]) // Parcourt les lignes de la carte
	{
		y = 0;
		while (data->map[x][y]) // Parcourt les colonnes de chaque ligne
		{
			xo = y * SQUARE_SIZE; // Calcul le point de depart pour dessiner le carre si indice (0;0) alors commence coin sup gauche
			yo = x * SQUARE_SIZE;
			if (data->map[x][y] == '1' || data->map[x][y] == ' ') // Si c'est un "mur" ou un case espace
				color = 0xFFFFFF;
			else
				color = 0x000000;
			int i, j;
			for (i = xo; i < xo + SQUARE_SIZE; i++)
			{
				for (j = yo; j < yo + SQUARE_SIZE; j++)
					mlx_pixel_put(data->mlx, data->win, i, j, color);
			}
			y++; // Passer à la colonne suivante
		}
		x++; // Passer à la ligne suivante
	}
}

int	display(t_data *data)
{
	// printf("x = %f y = %f \n", data->player->pos_x, data->player->pos_y);
	draw_map(data);
	drawPlayer(data);
	return (0);
}