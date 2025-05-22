/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-vel <mvan-vel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:39:10 by mvan-vel          #+#    #+#             */
/*   Updated: 2025/05/20 17:19:02 by mvan-vel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"


int	check_cub(char *str, t_data *data)
{
	if ((data->fd_map = open(str, O_RDONLY)) == -1)
		return (err_msg("directory not found", NULL, 0));
	if (ft_strlen(str) < 5)
		return (err_msg(ERROR_CUB, NULL, 0));
	while (*str && *str != '.')
		str++;
	if (ft_strcmp(str, ".cub") != 0)
		return (err_msg(ERROR_CUB, NULL, 0));
	return (1);
}

int	parsing(t_data *data, char *str)
{
    if (!check_cub(str, data))
	{
		ft_free_texture(data);
		close(data->fd_map);
		return (0);
	}
	if (check_texture(data))
	{
		ft_free_texture(data);
		close(data->fd_map);
		return (0);
	}
	if (check_xpm_color(data))
		return(0);
	if(copy_check_map(data))
		return(0);
	return (1);
}
