/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tete.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:35:57 by ssoumill          #+#    #+#             */
/*   Updated: 2025/05/14 14:32:51 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void destroy_xpm(t_data *data)
{
    if (data->img_no) 
    {
        mlx_destroy_image(data->mlx, data->img_no);
        data->img_no = NULL;
    }
    if (data->img_so) 
    {
        mlx_destroy_image(data->mlx, data->img_so);
        data->img_so = NULL;
    }
    if (data->img_ea) 
    {
        mlx_destroy_image(data->mlx, data->img_ea);
        data->img_ea = NULL;
    }
    if (data->img_we) 
    {
        mlx_destroy_image(data->mlx, data->img_we);
        data->img_we = NULL;
    }
    ft_free_texture(data);
    close(data->fd_map);
    exit (1);
}

void get_xpm(t_data *data)
{
    int i;
    int j;

    j = 0;

        i = 0;
        if ((data->img_no = mlx_xpm_file_to_image(data->mlx, "texture/north.xpm", &j, &j)) == NULL)
        {
            printf("cacacacacac \n");
            i = err_msg("NO file xpm", data->NO, 1);
        }
        if (!(data->img_so = mlx_xpm_file_to_image(data->mlx, data->SO, &j, &j)))
        {
            printf("bonjour 2\n");
            i = err_msg("SO file xpm", data->SO, 1);
        }
        if (!(data->img_ea = mlx_xpm_file_to_image(data->mlx, data->EA, &j, &j)))
        {
            printf("bonjour 3\n");
            i = err_msg("EA file xpm", data->EA, 1);
        }
        if (!(data->img_we = mlx_xpm_file_to_image(data->mlx, data->WE, &j, &j)))
        {
            printf("bonjour 4\n");
            i = err_msg("WE file xpm", data->WE, 1);
        }
        if (i != 0)
            destroy_xpm(data);
}