/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_distance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:35:57 by ssoumill          #+#    #+#             */
/*   Updated: 2025/05/20 17:26:13 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	compute_distance(float pa, t_ray *ray)
{
	if (ray->v_dist < ray->h_dist)
		ray->dist = ray->v_dist;
	else
		ray->dist = ray->h_dist;
	ray->ca = pa - ray->ra;
	fix_angle(ray->ca);
	if (ray->dist == ray->v_dist)
		ray->color = 0xFFF000;
	else
		ray->color =0xFFFF00;
	ray->dist = ray->dist * cos(deg_to_rad(ray->ca));
	ray->line_h = SQUARE_SIZE * WIN_HEIGHT / ray->dist;
	ray->line_o = WIN_HEIGHT / 2 - (ray->line_h / 2);
}

void	set_h_variable(t_ray *ray)
{
	float sinus;

	ray->ra = fix_angle(ray->ra);
	sinus = sin(deg_to_rad(ray->ra));
	if (sinus <= 0.0001 && sinus >= -0.0001)
		sinus = 0.0001;
	ray->Tan = 1 / tan(deg_to_rad(ray->ra));
	if (sinus > 0.0001)
	{
		ray->ry_h = ((int)(ray->py / SQUARE_SIZE)) * SQUARE_SIZE - 0.001;
		ray->rx_h = (ray->py - ray->ry_h) * ray->Tan + ray->px;
		ray->yo = -SQUARE_SIZE;
		ray->xo = -ray->yo * ray->Tan;
}
	else if (sinus < -0.0001)
	{
		ray->ry_h = ((int)(ray->py / SQUARE_SIZE)) * SQUARE_SIZE + SQUARE_SIZE;
		ray->rx_h = (ray->py - ray->ry_h) * ray->Tan + ray->px;
		ray->yo = SQUARE_SIZE;
		ray->xo = -ray->yo * ray->Tan;
	}
}


void	horizontal_distance(t_data *data, t_ray *ray)
{
		set_h_variable(ray);
		while (1)
		{
			ray->map_x = (int)(ray->rx_h / SQUARE_SIZE);
			ray->map_y = (int)(ray->ry_h / SQUARE_SIZE);
			if (ray->map_x < 0 || ray->map_x >= data->larg_row || ray->map_y < 0
				|| ray->map_y >= data->nbr_line)
				break ;
			if (data->map[ray->map_y][ray->map_x] == '1')
				break ;
			ray->rx_h += ray->xo;
			ray->ry_h += ray->yo;
		}
		ray->h_dist = sqrtf((ray->px - ray->rx_h) * (ray->px - ray->rx_h) + (ray->py - ray->ry_h) * (ray->py
			- ray->ry_h));
}

void	set_v_variable(t_ray *ray)
{
	float cosinus;
	
	ray->ra = fix_angle(ray->ra);
	cosinus = cos(deg_to_rad(ray->ra));
	if (cosinus <= 0.0001 && cosinus >= -0.0001)
		cosinus = 0.0001;	
	ray->Tan = tan(deg_to_rad(ray->ra));
	if (cosinus > 0.0001)
		{
			ray->rx_v = ((int)(ray->px / SQUARE_SIZE)) * SQUARE_SIZE + SQUARE_SIZE;
			ray->ry_v = (ray->px - ray->rx_v) * ray->Tan + ray->py;
			ray->xo = SQUARE_SIZE;
			ray->yo = -SQUARE_SIZE * ray->Tan;
		}
		else if (cosinus < -0.0001)
		{
			ray->rx_v = ((int)(ray->px / SQUARE_SIZE)) * SQUARE_SIZE - 0.001;
			ray->ry_v = (ray->px - ray->rx_v) * ray->Tan + ray->py;
			ray->xo = -SQUARE_SIZE;
			ray->yo = SQUARE_SIZE * ray->Tan;
		}
}

void	vertical_distance(t_data *data, t_ray *ray)
{
		set_v_variable(ray);
		while (1)
		{
			ray->map_x = (int)(ray->rx_v / SQUARE_SIZE);
			ray->map_y = (int)(ray->ry_v / SQUARE_SIZE);
			if (ray->map_x <= 0 || ray->map_x >= data->larg_row || ray->map_y <= 0
				|| ray->map_y >= data->nbr_line)
				break ;
			if (data->map[ray->map_y][ray->map_x] == '1')
				break ;
			ray->rx_v += ray->xo;
			ray->ry_v += ray->yo;
		}
		ray->v_dist = sqrtf((ray->px - ray->rx_v) * (ray->px - ray->rx_v) + (ray->py - ray->ry_v) * (ray->py
			- ray->ry_v));
}
