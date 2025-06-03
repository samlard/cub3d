/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:35:57 by ssoumill          #+#    #+#             */
/*   Updated: 2025/06/03 19:27:07 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	init_ray(t_data *data, t_ray *ray)
{
	ray->ra = data->player->pa - 30;
	ray->tang = 0;
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

void	draw_texture(t_data *data, t_texture *texture, t_ray *ray, int x)
{
	while (ray->line_h > 0)
	{
		texture->text_y = (int)texture->texture_pos % texture->height;
		texture->texture_pos += texture->step;
		my_pixel_put(data, x, ray->line_o, *(int *)(texture->addr
				+ (texture->text_y * texture->size_line) + texture->text_x
				* (texture->bpp / 8)));
		ray->line_o++;
		ray->line_h--;
	}
}

void	set_up_texture(t_data *data, int x, t_ray *ray)
{
	t_texture	*texture;

	if (ray->h_dist < ray->v_dist)
	{
		if (sin(deg_to_rad(ray->ra)) > 0)
			texture = &data->texture[NORTH];
		else
			texture = &data->texture[SOUTH];
		texture->text_x = (int)fmod(ray->rx_h, texture->width);
	}
	else
	{
		if (cos(deg_to_rad(ray->ra)) > 0)
			texture = &data->texture[EAST];
		else
			texture = &data->texture[WEST];
		texture->text_x = (int)fmod(ray->ry_v, texture->width);
	}
	texture->step = texture->height / ray->line_h;
	texture->texture_pos = (ray->line_o - WIN_HEIGHT / 2 + ray->line_h / 2)
		* texture->step;
	draw_texture(data, texture, ray, x);
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
	set_up_texture(data, x, ray);
	while (ray->line_o < WIN_HEIGHT)
	{
		my_pixel_put(data, x, ray->line_o, data->rgb_f);
		ray->line_o++;
	}
}

void	draw_ray(t_data *data)
{
	int		x;
	t_ray	ray;

	x = 0;
	init_ray(data, &ray);
	while (x < WIN_WIDTH)
	{
		vertical_distance(data, &ray);
		horizontal_distance(data, &ray);
		compute_distance(data->player->pa, &ray);
		draw_ray_column(data, x, &ray);
		ray.ra += (float)FOV / (float)WIN_WIDTH;
		x++;
	}
}
