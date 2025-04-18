/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:51:38 by ssoumill          #+#    #+#             */
/*   Updated: 2025/04/18 15:57:11 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	get_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		if ((int)ft_strlen(data->map[i]) > data->larg_row)
			data->larg_row = (int)ft_strlen(data->map[i]);
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'W' || data->map[i][j] == 'E')
			{
				data->player->pos_x = j;
				data->player->pos_y = i;
			}
			j++;
		}
		i++;
	}
	data->nbr_line = i;
}

int	check_valid(t_data *data, char *str)
{
	while (*str)
	{
		if (*str == 'N' || *str == 'S' || *str == 'W' || *str == 'E')
		{
			data->count_player++;
		}
		else if (*str != '0' && *str != '1' && *str != ' ' && *str != '\n')
			data->handle_error = 1; // 1 = pas les bons caractere
		str++;
	}
	return (data->handle_error);
}

int	map_copy(t_data *data)
{
	char	*str;
	char	*temp;

	str = ft_strdup("");
	while (1)
	{
		temp = get_next_line(data->fd_map);
		if (temp == NULL)
			break ;
		if (check_valid(data, temp))
			return (1);
		str = ft_strjoin(str, temp);
		free(temp);
	}
	data->map = ft_split(str, '\n');
	free(str);
	free(temp);
	return (0);
}

int	copy_check_map(t_data *data)
{
	map_copy(data);
	if (data->count_player != 1)
	{
		printf("error nb player %d\n", data->count_player);
		data->handle_error = 2; // 2 = trop de player;
								//freemap;
	}
	get_pos(data);
	get_map_square(data);
	return (0);
}