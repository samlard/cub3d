/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:38:23 by ssoumill          #+#    #+#             */
/*   Updated: 2025/05/21 17:14:20 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == 65307) // Touche Escape pour quitter
		exit(0);
	if (keycode == 119)
		data->key.key_w = 1;
	if (keycode == 115)
		data->key.key_s = 1;
	if (keycode == 97)
		data->key.key_a = 1;
	if (keycode == 100)
		data->key.key_d = 1;
	if (keycode == 65363)
		data->key.key_l = 1;
	if (keycode == 65361)
		data->key.key_r = 1;
	return (0);
}

int	handle_keyrelease(int keycode, t_data *data)
{
	if (keycode == 119)
		data->key.key_w = 0;
	if (keycode == 115)
		data->key.key_s = 0;
	if (keycode == 97)
		data->key.key_a = 0;
	if (keycode == 100)
		data->key.key_d = 0;
	if (keycode == 65363)
		data->key.key_l = 0;
	if (keycode == 65361)
		data->key.key_r = 0;
	return (0);
}