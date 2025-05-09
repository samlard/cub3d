/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_xpm_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-vel <mvan-vel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:14:06 by mvan-vel          #+#    #+#             */
/*   Updated: 2025/05/09 17:31:00 by mvan-vel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

// void destroy_xpm(t_data *data)
// {
//     if (data->img_no) 
//     {
//         mlx_destroy_image(data->mlx, data->img_no);
//         data->img_no = NULL;
//     }
//     if (data->img_so) 
//     {
//         mlx_destroy_image(data->mlx, data->img_so);
//         data->img_so = NULL;
//     }
//     if (data->img_ea) 
//     {
//         mlx_destroy_image(data->mlx, data->img_ea);
//         data->img_ea = NULL;
//     }
//     if (data->img_we) 
//     {
//         mlx_destroy_image(data->mlx, data->img_we);
//         data->img_we = NULL;
//     }
//     ft_free_texture(data);
//     close(data->fd_map);
//     exit (1);
// }

// void get_xpm(t_data *data)
// {
//     int i;

//     i = 0;
//     if ((data->img_no = mlx_xpm_file_to_image(data->mlx, data->NO, NULL, NULL)) == NULL)
//     {
//         printf("bonjour 1\n");
//         i = err_msg("NO file xpm", data->NO, 1);
//     }
//     if (i)
//         printf("55555555\n");
//     if (!(data->img_so = mlx_xpm_file_to_image(data->mlx, data->SO, NULL, NULL)))
//     {
//         printf("bonjour 2\n");
//         i = err_msg("SO file xpm", data->SO, 1);
//     }
//     if (i)
//         printf("55555555\n");
//     if (!(data->img_ea = mlx_xpm_file_to_image(data->mlx, data->EA, NULL, NULL)))
//     {
//         printf("bonjour 3\n");
//         i = err_msg("EA file xpm", data->EA, 1);
//     }
//     if (i)
//         printf("55555555\n");
//     if (!(data->img_we = mlx_xpm_file_to_image(data->mlx, data->WE, NULL, NULL)))
//     {
//         printf("bonjour 4\n");
//         i = err_msg("WE file xpm", data->WE, 1);
//     }
//     if (i)
//         printf("55555555\n");
//     if (i != 0)
//         destroy_xpm(data);
// }

int ft_strlen_tab(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
    {
        i++;
    }
    return(i);
}

int check_digit(char *str, int i)
{
    printf("%s\n", str);
    while (*str)
    {
        if (!ft_isdigit(*str))
        {
            if (i == 0)
                return(err_msg("only number for C", NULL, 1));
            else
                return(err_msg("only number for F!", NULL, 1));
        } 
        str++;
    }
    return(0);
}
int convert_color(char **tab, int i, int j)
{
    int r;
    int g;
    int b;

    while (tab[j])
    {
        if ((tab[j] = ft_strtrim(tab[j], " ")) == NULL)
            return(-1);
        if (check_digit(tab[j], i))
            return(-1);
        j++;
    }
    r = ft_atoi(tab[0]);
    g = ft_atoi(tab[1]);
    b = ft_atoi(tab[2]);
    if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
    {
        if (i == 0)
            return(err_msg("number should be between 0 and 255 for C!", NULL, -1));
        else
            return(err_msg("number should be between 0 and 255 for F!", NULL, -1));
    }
    return ((r << 16) + (g << 8) + b);
}

int get_color(t_data *data, char *str, int i)
{
    char **tab;

    if (!(tab = ft_split(str, ',')))
        return(err_msg("split malloc error !", NULL, 1));
    if (ft_strlen_tab(tab) != 3)
    {
        if (i == 0)
            err_msg("need 3 number no more, no less, for C : xxx, xxx, xxx!", NULL, 0);
        else
            err_msg("need 3 number no more, no less, for F : xxx, xxx, xxx!", NULL, 0);
        return (ft_free_tab(tab), 1);
    }
    if (i == 0)
    {
       if ((data->rgb_c = convert_color(tab, i, 0)) == -1)
        return(ft_free_tab(tab), 1);
    }
    else
    {
       if ((data->rgb_f = convert_color(tab, i, 0)) == -1)
        return(ft_free_tab(tab), 1);
    }
    return(0);
}

int check_xpm_color(t_data *data)
{
    //get_xpm(data);
    if(get_color(data, data->C, 0) || get_color(data, data->F, 1))
    {
        ft_free_texture(data);
        close(data->fd_map); //ce faire une fonction pour l handle d error pour bien tout free et close proprement
        return (1);
    }
    printf("color C : %d \n color F : %d\n", data->rgb_c, data->rgb_f);
    return(0);
}
