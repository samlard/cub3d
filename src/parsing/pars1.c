/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:51:38 by ssoumill          #+#    #+#             */
/*   Updated: 2025/03/06 17:04:13 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int check_cub(char *str, t_data *data)
{
    if ((data->fd_map = open(str, O_RDONLY)) == -1)
        return(0);
    if (ft_strlen(str) < 5)
        return (0);
    while (*str && *str != '.')
        str++;
    if (ft_strcmp(str, ".cub") != 0)
        return (0);
    return (1);
}