/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-vel <mvan-vel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:39:10 by mvan-vel          #+#    #+#             */
/*   Updated: 2025/05/30 15:59:48 by mvan-vel         ###   ########.fr       */
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
		exit(1);
	}
	if (check_texture(data))
	{
		ft_free_texture(data);
		close(data->fd_map);
		exit(1);
	}
	check_xpm_color(data)
	if (copy_check_map(data))
		return (0);
	return (1);
}
