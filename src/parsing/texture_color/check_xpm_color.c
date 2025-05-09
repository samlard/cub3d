/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_xpm_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-vel <mvan-vel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:14:06 by mvan-vel          #+#    #+#             */
/*   Updated: 2025/05/09 13:05:44 by mvan-vel         ###   ########.fr       */
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
    ft_free_tab(data->map);
    close(data->fd_map);
    exit (1);
}

void get_xpm(t_data *data)
{
    int i;

    i = 0;
    if (!(data->img_no = mlx_xpm_file_to_image(data->mlx, data->NO, NULL, NULL)))
        i = err_msg("NO file xpm", data->NO, 1);
    if (!(data->img_so = mlx_xpm_file_to_image(data->mlx, data->SO, NULL, NULL)))
        i = err_msg("SO file xpm", data->SO, 1);
    if (!(data->img_ea = mlx_xpm_file_to_image(data->mlx, data->EA, NULL, NULL)))
        i = err_msg("EA file xpm", data->EA, 1);
    if (!(data->img_we = mlx_xpm_file_to_image(data->mlx, data->WE, NULL, NULL)))
        i = err_msg("WE file xpm", data->WE, 1);
    if (i != 0)
        destroy_xpm(data);
}
int get_color(t_data *data, char *str)
{
        
}

int check_xpm_color(t_data *data)
{
    get_xpm(data);
    if(get_color(data, data->C))
    {
        ft_free_texture(data);
        ft_free_tab(data->map);
        close(data->fd_map); //ce faire une fonction pour l handle d error pour bien tout free et close proprement
        return (1);
    }
    if(get_color(data, data->F))
    {
        ft_free_texture(data);
        ft_free_tab(data->map);
        close(data->fd_map); //ce faire une fonction pour l handle d error pour bien tout free et close proprement
        return (1);
    }
    return(0);
}
