/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-vel <mvan-vel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:35:57 by ssoumill          #+#    #+#             */
/*   Updated: 2025/05/20 17:58:56 by mvan-vel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"


void	init_ray(t_data *data, t_ray *ray)
{
	ray->ra = data->player->pa - 30;
	ray->Tan = 0;
	ray->px = data->player->pos_x;
	ray->py = data->player->pos_y;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->dist = 0;
	ray->v_dist = 0;
	ray->h_dist = 0;
	ray->xo = 0;
	ray->yo = 0;
	ray->rx_v = 0;
	ray->ry_v = 0;
	ray->rx_h = 0;
	ray->ry_h = 0;
	ray->color = 0;
	ray->ca = 0;
	ray->line_h = 0;
	ray->line_o = 0;
}

// void	draw_texture(t_data *data, int x, t_ray *ray)
// {
// 	int	text_x;
// 	int	text_y;
// 	float texture_pos;
// 	float	step;
// 	t_texture *texture;

// 	if (ray->h_dist < ray->v_dist)
// 	{
// 		if (sin(deg_to_rad(ray->ra)) > 0)
// 			texture = &data->texture[NORTH];
// 		else
// 			texture = &data->texture[SOUTH];
// 		    text_x = (int)(ray->rx_h * texture->width) & (texture->width - 1);
// 	}
// 	else
// 	{
// 		if (cos(deg_to_rad(ray->ra)) > 0)
// 			texture = &data->texture[EAST];
// 		else
// 			texture = &data->texture[WEST];
// 		    text_x = (int)(ray->ry_v * texture->width) & (texture->width - 1);
// 	}
// 	step = texture->height / ray->line_h;
// 	// if (ray->line_h == (float) WIN_HEIGHT)
// 	// 	texture_pos = 0;
// 	// else
// 		texture_pos = (ray->line_o - WIN_HEIGHT / 2 + ray->line_h / 2) * step;
// 	while (ray->line_h >= 0)
// 	{
// 		text_y = (int)texture_pos % texture->height;
// 		texture_pos += step;
// 		my_pixel_put(data, x, ray->line_o, *(int *) (texture->addr + (text_y * texture->size_line) + text_x * (texture->bpp / 8)));
// 		ray->line_o++;
// 		ray->line_h--;
// 	}
// }
void draw_texture(t_data *data, int x, t_ray *ray)
{
    int text_x;
    int text_y;
    float texture_pos;
    float step;
    t_texture *texture;

    if (ray->h_dist < ray->v_dist) {
        if (sin(deg_to_rad(ray->ra)) > 0)
            texture = &data->texture[NORTH];
        else
            texture = &data->texture[SOUTH];
        text_x = (int)fmod(ray->rx_h, texture->width);
    } else {
        if (cos(deg_to_rad(ray->ra)) > 0)
            texture = &data->texture[EAST];
        else
            texture = &data->texture[WEST];
        
        // Calcul du text_x pour le rayon vertical
        text_x = (int)fmod(ray->ry_v, texture->width);
    }

    // Calcul de la hauteur de la texture projetée sur l'écran
    step = texture->height / ray->line_h;
	if (step < 0.01)
		step = 0.01;
    texture_pos = (ray->line_o - WIN_HEIGHT / 2 + ray->line_h / 2) * step;

    // Dessin de la texture ligne par ligne
    while (ray->line_h > 0)
    {
        // Calcul de la coordonnée y de la texture
        text_y = (int)texture_pos % texture->height;
        texture_pos += step;

        // Dessiner le pixel à la position correcte sur l'écran
        my_pixel_put(data, x, ray->line_o, *(int *)(texture->addr + (text_y * texture->size_line) + text_x * (texture->bpp / 8)));

        // Incrémentation de la position de l'écran et décrémentation de la hauteur
        ray->line_o++;
        ray->line_h--;
    }
}



void	draw_ray_column(t_data *data, int x, t_ray *ray)
{
	int	i;

	i = 0;
	while (i < ray->line_o)
	{
		my_pixel_put(data, x, i, data->rgb_c);
		i++;
	}
	draw_texture(data, x, ray);
	while (ray->line_o < WIN_HEIGHT)
	{
		my_pixel_put(data, x, ray->line_o, data->rgb_f);
		ray->line_o++;
	}
}

void	draw_ray(t_data *data)
{
	int		x;
	t_ray 	ray;

	x = 0;
	init_ray(data, &ray);
	while (x < WIN_WIDTH)
	{
		vertical_distance(data, &ray);
		horizontal_distance(data, &ray);
		compute_distance(data->player->pa, &ray);
		draw_ray_column(data, x, &ray);
		ray.ra+= (float)FOV/(float)WIN_WIDTH;
		x++;
	}
}
