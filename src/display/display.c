/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:35:57 by ssoumill          #+#    #+#             */
/*   Updated: 2025/04/12 17:46:43 by ssoumill         ###   ########.fr       */
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

// void draw_ray(t_data *data)
// {
// 	float	ra = data->player->pa;

// 	while (ra - 30 < ra + 30)
// 	{
// 		ra += 1;
// 	}
	
// }

void draw_ray(t_data *data)
{
    float ra; // Rayon actuel
    int r;    // Compteur pour les rayons (nombre de rayons)
    float disV, disH; // Distance à la verticale et à l'horizontale
    float rx, ry;      // Coordonnées de l'impact du rayon
    float Tan;         // Tangente pour les calculs
    int dof;           // Distance jusqu'à l'impact avec un mur
    int mx, my;        // Coordonnées de la grille
    int mp;            // Case de la carte

    ra = data->player->pa - 30.0f; // Commencer à -30° par rapport à l'angle du joueur

    for (r = 0; r < 60; r++) // 60 rayons dans le champ de vision
    {
        // Calcul de l'angle du rayon
        if (ra > 360 )
			ra = ra /360;

        // --- Partie Raycasting Vertical ---
        dof = 0;
        disV = 100000.0f; // Distance maximale par défaut
        Tan = tan(ra * PI / 180);
        
        if (cos(ra * PI / 180) > 0.001) // Rayon qui regarde vers la droite
        {
            rx = (((int)data->player->pos_x >> 6) << 6) + 64;
            ry = (data->player->pos_x - rx) * Tan + data->player->pos_y;
        }
        else if (cos(ra * PI / 180) < -0.001) // Rayon qui regarde vers la gauche
        {
            rx = (((int)data->player->pos_x >> 6) << 6) - 0.0001f;
            ry = (data->player->pos_x - rx) * Tan + data->player->pos_y;
        }
        else // Regarder directement vers le haut ou vers le bas
        {
            rx = data->player->pos_x;
            ry = data->player->pos_y;
            dof = 8;
        }

        while (dof < 8)
        {
            mx = (int)(rx) >> 6;
            my = (int)(ry) >> 6;
            mp = my * data->larg_row + mx; // ID de la case dans la carte
            
            if (mp > 0 && mp < data->larg_row * data->nbr_line && data->map[mx][my] == '1') // Mur
            {
                dof = 8;
                disV = cos(ra * PI / 180) * (rx - data->player->pos_x) - sin(ra * PI / 180) * (ry - data->player->pos_y);
            }
            else
            {
                rx += 64; // Avancer à la prochaine case
                ry += 64 * Tan; // Avancer à la prochaine case
                dof++;
            }
        }

        // --- Partie Raycasting Horizontal ---
        dof = 0;
        disH = 100000.0f;
        Tan = 1.0f / Tan;

        if (sin(ra * PI / 180) > 0.001) // Rayon qui regarde vers le bas
        {
            ry = (((int)data->player->pos_y >> 6) << 6) + 64;
            rx = (data->player->pos_y - ry) * Tan + data->player->pos_x;
        }
        else if (sin(ra * PI / 180) < -0.001) // Rayon qui regarde vers le haut
        {
            ry = (((int)data->player->pos_y >> 6) << 6) - 0.0001f;
            rx = (data->player->pos_y - ry) * Tan + data->player->pos_x;
        }
        else
        {
            rx = data->player->pos_x;
            ry = data->player->pos_y;
            dof = 8;
        }

        while (dof < 8)
        {
            mx = (int)(rx) >> 6;
            my = (int)(ry) >> 6;
            mp = my * data->larg_row + mx;

            if (mp > 0 && mp < data->larg_row * data->nbr_line && data->map[mx][my] == '1') // Mur
            {
                dof = 8;
                disH = cos(ra * PI / 180) * (rx - data->player->pos_x) - sin(ra * PI / 180) * (ry - data->player->pos_y);
            }
            else
            {
                rx += 64 * Tan;
                ry += 64;
                dof++;
            }
        }

        // --- Dessin des rayons ---
        if (disV < disH) // Si le rayon vertical touche le mur le plus tôt
        {
            // rx = rx;
            // ry = ry;
            disH = disV;
        }

        // Correction fisheye pour les rayons qui sont plus loin
        disH = disH * cos(PI *(ra - data->player->pa) /180);

        // Dessiner la ligne entre le joueur et le mur
        int lineHeight = (int)(320.0f / disH);
        if (lineHeight > 320) lineHeight = 320;
        int lineOff = 160 - (lineHeight >> 1); // Position verticale du mur

        for (int i = r * 8 + 530; i < r * 8 + 530 + 8; i++) // Chaque rayon est un petit segment de ligne
        {
            for (int j = lineOff; j < lineOff + lineHeight; j++)
                my_pixel_put(data, i, j, 0xFF0000); // Dessiner le mur
        }

        ra = PI * (ra + 1) /180; // Passer au rayon suivant
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