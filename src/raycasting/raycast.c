/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:35:57 by ssoumill          #+#    #+#             */
/*   Updated: 2025/05/14 13:11:50 by ssoumill         ###   ########.fr       */
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
	ray->rx = 0;
	ray->ry = 0;
	ray->color = 0;
	ray->ca = 0;
	ray->line_h = 0;
	ray->line_o = 0;
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
	while (ray->line_h >= 0)
	{
		my_pixel_put(data, x, ray->line_o, ray->color);
		ray->line_h--;
		ray->line_o++;
	}
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
