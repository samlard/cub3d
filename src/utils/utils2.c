/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 11:58:54 by ssoumill          #+#    #+#             */
/*   Updated: 2025/05/30 17:00:53 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	get_start_angle(char c, t_data *data)
{
	if (c == 'N')
		data->player->pa = 90;
	if (c == 'S')
		data->player->pa = 270;
	if (c == 'W')
		data->player->pa = 180;
	if (c == 'E')
		data->player->pa = 0;
}

float	fix_angle(float ra)
{
	if (ra > 360)
		ra -= 360;
	else if (ra < 0)
		ra += 360;
	return (ra);
}

float	deg_to_rad(float pa)
{
	return (pa * PI / 180);
}
