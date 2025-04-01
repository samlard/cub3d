/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:38:23 by ssoumill          #+#    #+#             */
/*   Updated: 2025/03/30 18:21:25 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	handle_keypress(int keycode, t_data *data)
{
    if (keycode == 65307)  // Touche Escape pour quitter
        exit(0);
    // Déplacement avant (W)
    if (keycode == 119)
        data->key.key_w = 1;
    // Déplacement arrière (S)
    if (keycode == 115)
        data->key.key_s = 1;
    // Déplacement à gauche (A)
    if (keycode == 97)
        data->key.key_a = 1;
    // Déplacement à droite (D)
    if (keycode == 100)
         data->key.key_d = 1;
    if (keycode == 65363)
        data->key.key_w = 1;
    // Flèche gauche (déplacer à gauche)
    if (keycode == 65361)
        data->key.key_w = 1;
    return (0);
}

int	handle_keyrelease(int keycode, t_data *data)
{
    // Déplacement avant (W)
    if (keycode == 119)
        data->key.key_w = 0;
    // Déplacement arrière (S)
    if (keycode == 115)
        data->key.key_s = 0;
    // Déplacement à gauche (A)
    if (keycode == 97)
        data->key.key_a = 0;
    // Déplacement à droite (D)
    if (keycode == 100)
         data->key.key_d = 0;
    if (keycode == 65363)
        data->player->pos_x += 1 * MOVE_SPEED;
    // Flèche gauche (déplacer à gauche)
    if (keycode == 65361)
        data->player->pos_x -= 1 * MOVE_SPEED;
    return (0);
    //printf("Keyrelease: %d\n", keysym);
}