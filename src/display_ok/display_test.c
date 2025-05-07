// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   display_test.c                                     :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/03/30 14:35:57 by ssoumill          #+#    #+#             */
// /*   Updated: 2025/05/07 15:53:08 by ssoumill         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "test.h"

// void	my_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dest;

// 	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
// 	{
// 		dest = data->img_addr + (y * data->size_line + x * (data->bpp / 8));
// 		*(unsigned int *)dest = color;
// 	}
// }

// void	clear_image(t_data *data, int color)
// {
// 	int	y;
// 	int	x;

// 	y = -1;
// 	while (++y < WIN_HEIGHT)
// 	{
// 		x = -1;
// 		while (++x < WIN_WIDTH)
// 		{
// 			my_pixel_put(data, x, y, color);
// 		}
// 	}
// }

// void	drawPlayer(t_data *data)
// {
// 	int	x2;
// 	int	y2;
// 	int	dx;
// 	int	dy;
// 	int	sx;
// 	int	sy;
// 	int	err;
// 	int	e2;
// 	int	playerSize;
// 	int	x1;
// 	int	y1;

// 	playerSize = 4;
// 	// Taille du carré représentant le joueur (16x16 pixels)
// 	// Dessiner un carré représentant le joueur
// 	if (data->key.key_w == 1)
// 	{
// 		usleep(20000);
// 		moove_up(data);
// 	}
// 	if (data->key.key_s == 1)
// 		moove_down(data);
// 	if (data->key.key_d == 1)
// 		moove_left(data);
// 	if (data->key.key_a == 1)
// 		moove_right(data);
// 	if (data->key.key_l == 1 || data->key.key_r == 1)
// 		ft_rotate(data);
// 	for (int i = data->player->pos_x; i < data->player->pos_x + playerSize; i++)
// 	{
// 		for (int j = data->player->pos_y; j < data->player->pos_y
// 				+ playerSize; j++)
// 		{
// 			my_pixel_put(data, i, j, 0xFF0000);
// 			//mlx_pixel_put(data->mlx, data->win, i, j, 0xFFFF00);
// 			// 0xFFFF00 est la couleur jaune
// 		}
// 	}
// 	// Dessiner une ligne (représente la direction)
// 	x1 = data->player->pos_x + playerSize / 2;
// 	// Centrer la ligne à l'intérieur du carré
// 	y1 = data->player->pos_y + playerSize / 2;
// 	// Centrer la ligne à l'intérieur du carré
// 	x2 = x1 + data->player->pdx * 20;
// 	y2 = y1 + data->player->pdy * 20;
// 	// Algorithme de tracé de ligne de Bresenham pour dessiner une ligne entre (x1,y1) et (x2,y2)
// 	dx = abs(x2 - x1);
// 	dy = abs(y2 - y1);
// 	sx = (x1 < x2) ? 1 : -1;
// 	sy = (y1 < y2) ? 1 : -1;
// 	err = dx - dy;
// 	while (1)
// 	{
// 		my_pixel_put(data, x1, y1, 0xFF0000);
// 		//my_pixel_put(data->mlx, data->win, x1, y1, 0xFFFF00);
// 		// Tracer la ligne en jaune
// 		if (x1 == x2 && y1 == y2)
// 			break ;
// 		e2 = err * 2;
// 		if (e2 > -dy)
// 		{
// 			err -= dy;
// 			x1 += sx;
// 		}
// 		if (e2 < dx)
// 		{
// 			err += dx;
// 			y1 += sy;
// 		}
// 	}
// }

// void	draw_map(t_data *data)
// {
// 	int	color;
// 	int	x;
// 	int	y;

// 	int xo, yo;
// 	x = 0;
// 	while (data->map[x]) // Parcourt les lignes de la carte
// 	{
// 		y = 0;
// 		while (data->map[x][y]) // Parcourt les colonnes de chaque ligne
// 		{
// 			xo = y * SQUARE_SIZE;
// 			// Calcul le point de depart pour dessiner le carre si indice (0;0) alors commence coin sup gauche
// 			yo = x * SQUARE_SIZE;
// 			if (data->map[x][y] == '1' || data->map[x][y] == ' ')
// 				// Si c'est un "mur" ou un case espace
// 				color = 0x000000;
// 			else
// 				color = 0xFFFFFF;
// 			int i, j;
// 			for (i = xo; i < xo + SQUARE_SIZE; i++)
// 			{
// 				for (j = yo; j < yo + SQUARE_SIZE; j++)
// 					my_pixel_put(data, i, j, color);
// 			}
// 			y++; // Passer à la colonne suivante
// 		}
// 		x++; // Passer à la ligne suivante
// 	}
// 	x = 0;
// 	while (x < data->larg_row * SQUARE_SIZE) // Parcourt les lignes de la carte
// 	{
// 		y = 0;
// 		while (y < data->nbr_line * SQUARE_SIZE) // Parcourt les colonnes de chaque ligne
// 		{
// 			color = 0xFFF00;
// 			my_pixel_put(data, x, y, color);
// 			my_pixel_put(data, y, x, color);
// 			y++; // Passer à la colonne suivante
// 		}
// 		x += SQUARE_SIZE; // Passer à la ligne suivante
// 	}
// }


// float   get_h_dist(t_data *data)
// {
//     Tan = 1 / tan(deg_to_rad(ra));
//     if (sin(deg_to_rad(ra)) > 0.0001)
//     {
//         ry = ((int)(py / SQUARE_SIZE)) * SQUARE_SIZE - 0.001;
//         rx = (py - ry) * Tan + px;
//         yo = -SQUARE_SIZE;
//         xo = -yo * Tan;
//     }
//     else if (sin(deg_to_rad(ra)) < -0.0001)
//     {
//         ry = ((int)(py / SQUARE_SIZE)) * SQUARE_SIZE + SQUARE_SIZE;
//         rx = (py - ry) * Tan + px;
//         yo = SQUARE_SIZE;
//         xo = -yo * Tan;
//     }
//     while (1)
//     {
//         map_x = (int)(rx / SQUARE_SIZE);
//         map_y = (int)(ry / SQUARE_SIZE);
//         if (map_x < 0 || map_x > data->larg_row || map_y < 0
//             || map_y >= data->nbr_line)
//         {
//             h_dist = data->larg_row * SQUARE_SIZE;
//             break ;
//         }
//         if (data->map[map_y][map_x] == '1')
//         {
//             h_dist = sqrtf((px - rx) * (px - rx) + (py - ry) * (py - ry));
//             break ;
//         }
//         rx += xo;
//         ry += yo;
//     }
// }

// float   get_v_dist(t_data *data)
// {
//         ra = fix_angle(ra);
// 		Tan = tan(deg_to_rad(ra));
// 		if (cos(deg_to_rad(ra)) > 0.0001)
// 		{
// 			rx_v = ((int)(px / SQUARE_SIZE)) * SQUARE_SIZE + SQUARE_SIZE;
// 			ry_v = (px - rx_v) * Tan + py;
// 			xo = SQUARE_SIZE;
// 			yo = -SQUARE_SIZE * Tan;
// 		}
// 		else if (cos(deg_to_rad(ra)) < 0.0001)
// 		{
// 			rx_v = ((int)(px / SQUARE_SIZE)) * SQUARE_SIZE - 0.0001;
// 			ry_v = (px - rx_v) * Tan + py;
// 			xo = -SQUARE_SIZE;
// 			yo = SQUARE_SIZE * Tan;
// 		}
// 		while (1)
// 		{
// 			map_x = (int)(rx_v / SQUARE_SIZE);
// 			map_y = (int)(ry_v / SQUARE_SIZE);
// 			if (map_x < 0 || map_x >= data->larg_row || map_y < 0
// 				|| map_y >= data->nbr_line)
// 			{
// 				v_dist = data->nbr_line * SQUARE_SIZE;
// 				break ;
// 			}
// 			if (data->map[map_y][map_x] == '1')
// 			{
// 				v_dist = sqrtf((px - rx_v) * (px - rx_v) + (py - ry_v) * (py
// 							- ry_v));
// 				break ;
// 			}
// 			rx_v += xo;
// 			ry_v += yo;
// 		}
// }

// void    get_variabe(t_data *data)
// {
//     data->ray->color = 0;
//     data->ray->xo = 0;
//     data->ray->yo = 0;
//     data->ray->rx = 0;
// 	data->ray->px = data->player->pos_x;
// 	data->ray->py = data->player->pos_y;
//     data->ray->map_x = 0;
//     data->ray->map_y = 0;
// }

// float	calculate_vertical_intersection(t_data *data, t_ray *ray)
// {
// 	    ra = fix_angle(ra);
// 		Tan = tan(deg_to_rad(ra));
// 		if (cos(deg_to_rad(ra)) > 0.0001)
// 		{
// 			rx_v = ((int)(px / SQUARE_SIZE)) * SQUARE_SIZE + SQUARE_SIZE;
// 			ry_v = (px - rx_v) * Tan + py;
// 			xo = SQUARE_SIZE;
// 			yo = -SQUARE_SIZE * Tan;
// 		}
// 		else if (cos(deg_to_rad(ra)) < 0.0001)
// 		{
// 			rx_v = ((int)(px / SQUARE_SIZE)) * SQUARE_SIZE - 0.0001;
// 			ry_v = (px - rx_v) * Tan + py;
// 			xo = -SQUARE_SIZE;
// 			yo = SQUARE_SIZE * Tan;
// 		}
// 		while (1)
// 		{
// 			map_x = (int)(rx_v / SQUARE_SIZE);
// 			map_y = (int)(ry_v / SQUARE_SIZE);
// 			if (map_x < 0 || map_x >= data->larg_row || map_y < 0
// 				|| map_y >= data->nbr_line)
// 			{
// 				v_dist = data->nbr_line * SQUARE_SIZE;
// 				break ;
// 			}
// 			if (data->map[map_y][map_x] == '1')
// 			{
// 				v_dist = sqrtf((px - rx_v) * (px - rx_v) + (py - ry_v) * (py
// 							- ry_v));
// 				break ;
// 			}
// 			rx_v += xo;
// 			ry_v += yo;
// 		}
// }

// void	init_ray_variables(t_ray *ray, t_player *player, int x)
// {
// 	ray->ra = fix_angle(player->pa - (FOV / 2.0f) + ((float)x * FOV / (float)WIN_WIDTH));
// 	ray->px = player->pos_x;
// 	ray->py = player->pos_y;
// }

// void	draw_ray_column(t_data *data, int x, float dist, int color)
// {
// 	float	line_h = SQUARE_SIZE * WIN_HEIGHT / dist;
// 	float	line_o = WIN_HEIGHT / 2 - (line_h / 2);
// 	if (line_h > WIN_HEIGHT)
// 		line_h = WIN_HEIGHT;
// 	while (line_h-- > 0)
// 		my_pixel_put(data, x, line_o++, color);
// }

// float	compute_distance(float v_dist, float h_dist, float ray_angle, float player_angle, int *color)
// {
// 	float	dist;
// 	float	ca = fix_angle(player_angle - ray_angle);
// 	dist = (v_dist < h_dist ? v_dist : h_dist);
// 	*color = (v_dist < h_dist) ? 0xFFF000 : 0xFF0000;
// 	return dist * cos(deg_to_rad(ca)); // Correction du fish-eye
// }


// void	draw_ray(t_data *data)
// {
// 	int		x;
// 	t_ray	ray;
// 	float	v_dist, h_dist, dist;
// 	int		color;

// 	x = 0;
// 	while (x < WIN_WIDTH)
// 	{
// 		init_ray_variables(&ray, data->player, x);
// 		v_dist = calculate_vertical_intersection(data, &ray);
// 		h_dist = calculate_horizontal_intersection(data, &ray);
// 		dist = compute_distance(v_dist, h_dist, ray.ra, data->player->pa, &color);
// 		draw_ray_column(data, x, dist, color);
// 		x++;
// 	}
// }


// int	display(t_data *data)
// {
// 	clear_image(data, 0x000000);
// 	//draw_map(data);
// 	drawPlayer(data);
// 	draw_ray(data);
// 	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
// 	return (0);
// }