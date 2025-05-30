/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-vel <mvan-vel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:51:38 by ssoumill          #+#    #+#             */
/*   Updated: 2025/05/30 18:05:51 by mvan-vel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	pos_player(t_data *data)
{
	if (data->player->pos_x == 0 || data->player->pos_y == 0)
		return (1);
	else if (data->player->pos_x == data->larg_row - 1
		|| data->player->pos_y == data->nbr_line - 1)
		return (1);
	return (0);
}

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
			data->larg_row = ((int)ft_strlen(data->map[i]));
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

void	prepare_to_copy(t_data *data)
{
	char	*temp;
	char	*temp2;

	check_valid(data, data->map_first_line);
	while (1)
	{
		temp = get_next_line(data->fd_map);
		if (temp == NULL)
			break ;
		check_valid(data, temp);
		temp2 = ft_strtrim(temp, " ");
		if (!temp2)
			return (free(temp), handle_error(data, 0));
		data->map_first_line = ft_strjoin(data->map_first_line, temp2);
		if (!data->map_first_line)
			return (free(temp), free(temp2), handle_error(data, 0));
		free(temp);
		free(temp2);
	}
}

void	map_copy(t_data *data)
{
	prepare_to_copy(data);
	data->map = ft_split(data->map_first_line, '\n');
	if (!data->map)
		handle_error(data, 0);
	free(data->map_first_line);
	data->map_first_line = NULL;
}

void	copy_check_map(t_data *data)
{
	map_copy(data);
	if (data->count_player == 0)
	{
		err_msg("need a player !", NULL, 0);
		handle_error(data, 1);
	}
	get_pos(data);
	if (data->larg_row < 3 || data->nbr_line < 3)
	{
		err_msg("invalid map !", NULL, 1);
		handle_error(data, 1);
	}
	if (pos_player(data))
	{
		err_msg("position player error !", NULL, 1);
		handle_error(data, 1);
	}
	get_map_square(data);
	backtrack(data, data->map, data->player->pos_y, data->player->pos_x);
	if (data->flag == 1)
	{
		err_msg("invalid map, there is a hole!", NULL, 1);
		handle_error(data, 1);
	}
}
