/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:35:57 by ssoumill          #+#    #+#             */
/*   Updated: 2025/04/13 17:51:15 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dest;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		dest = data->img_addr + (y * data->size_line
				+ x * (data->bpp / 8));
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
void	ft_rotate(t_data *data)
{
	if (data->key.key_l == 1)
		data->player->pa-= 5;
	if (data->key.key_r == 1)
		data->player->pa+= 5;
	if (data->player->pa >= 360 )
		data->player->pa = data->player->pa/360; 
	data->player->pdx = cos((data->player->pa) * PI / 180);
	data->player->pdy = -sin((data->player->pa) * PI/ 180);
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

	int playerSize = 4;
		// Taille du carré représentant le joueur (16x16 pixels)
	// Dessiner un carré représentant le joueur
	if (data->key.key_w == 1 && data->map[(int)((data->player->pos_y - (float)MOVE_SPEED) / 64.0f)][(int)(data->player->pos_x / 64.0f)] != '1')
		data->player->pos_y-=  MOVE_SPEED;
	if (data->key.key_s == 1 && data->map[(int)((data->player->pos_y + (float)MOVE_SPEED) / 64.0f)][(int)(data->player->pos_x / 64.0f)] != '1')
		data->player->pos_y+= MOVE_SPEED;
	if (data->key.key_a == 1 && data->map[(int)(data->player->pos_y / 64.0f)][(int)((data->player->pos_x - (float)MOVE_SPEED) / 64.0f)] != '1')
		data->player->pos_x -= MOVE_SPEED;
	if (data->key.key_d == 1 && data->map[(int)(data->player->pos_y / 64.0f)][(int)((data->player->pos_x + (float)MOVE_SPEED) / 64.0f)] != '1')
		data->player->pos_x += MOVE_SPEED;
	if (data->key.key_l == 1 || data->key.key_r == 1)
		ft_rotate(data);
		
	for (int i = data->player->pos_x; i < data->player->pos_x + playerSize; i++)
	{
		for (int j = data->player->pos_y; j < data->player->pos_y + playerSize; j++)
		{
			my_pixel_put(data, i, j, 0xFF0000);
			//mlx_pixel_put(data->mlx, data->win, i, j, 0xFFFF00);
				// 0xFFFF00 est la couleur jaune
		}
	}
	// Dessiner une ligne (représente la direction)
	int x1 = data->player->pos_x + playerSize / 2;
		// Centrer la ligne à l'intérieur du carré
	int y1 = data->player->pos_y + playerSize / 2;
		// Centrer la ligne à l'intérieur du carré
	x2 = x1 + data->player->pdx * 20;
	y2 = y1 + data->player->pdy * 20;
	// Algorithme de tracé de ligne de Bresenham pour dessiner une ligne entre (x1,y1) et (x2, y2)
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
	x = 0 ;
	while (x < data->larg_row * 64) // Parcourt les lignes de la carte
	{
		y = 0;
		while (y < data->nbr_line * 64) // Parcourt les colonnes de chaque ligne
		{
			color = 0xFFFF0;
			my_pixel_put(data, x, y, color);
			my_pixel_put(data, y, x, color);
			y++; // Passer à la colonne suivante
		}
		x+= SQUARE_SIZE; // Passer à la ligne suivante
	}
}

void draw_ray(t_data *data)
{
    float ra; // Rayon actuel
    float rx, ry;      // Coordonnées de l'impact du rayon
    float Tan;         // Tangente pour les calculs
    float px = data->player->pos_x;
    float py = data->player->pos_y;

    // Angle du rayon (avec sécurité pour éviter les angles > 360)
    ra = data->player->pa;
    if (ra > 360)
        ra -= 360;

    // Calcul de la tangente pour l'angle
    Tan = tan(ra * PI / 180);

    // Initialisation des coordonnées du rayon
    rx = 0;
    ry = 0;

    // Sécurités pour gérer la direction du rayon (regarder à droite, éviter 90° et 270°)
    if (cos(ra * PI / 180) > 0 && ra != 90 && ra != 270) // regarde vers la droite
    {
        rx = ((int)(px / 64)) * 64 + 64;  // Premier multiple de 64 à droite
        ry = (px - rx) * Tan + py;         // Calcul de la coordonnée y du rayon

        // Trace le rayon
        for (int x = px; x < 1500; x++) // Limiter à une largeur d'écran de 1500 px
        {
            // Calcul de la coordonnée y avec la formule d'une droite
            float y = Tan * (px - x) + py;

            // Vérifier si la position (x, y) touche un mur dans la carte
            int map_x = (int)(x / 64);  // Position du rayon sur la carte (x)
            int map_y = (int)(y / 64);  // Position du rayon sur la carte (y)

            // Vérifier que les coordonnées sont dans les limites de la carte
            if (map_x >= 0 && map_x < data->larg_row * 64 && map_y >= 0 && map_y < data->nbr_line * 64)
            {
                // Si le rayon touche un mur, arrêter le tracé
                if (data->map[map_y][map_x] == '1') // 1 signifie un mur
                {
                    my_pixel_put(data, x, y, 0xFF0000);  // Dessine le rayon en rouge
                    break;  // Arrêter dès que le rayon touche un mur
                }
            }

            // Dessiner le rayon (sécurité pour ne pas dépasser l'écran)
            if (x >= 0 && x < 1500 && y >= 0 && y < 1000)
                my_pixel_put(data, x, y, 0xFF0000); // Dessiner un pixel à la position (x, y)
        }
    }
}


int	display(t_data *data)
{
	// printf("x = %f y = %f \n", data->player->pos_x, data->player->pos_y);
	clear_image(data, 0x000000);
	draw_map(data);
	drawPlayer(data);
	draw_ray(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}