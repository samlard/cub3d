/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-vel <mvan-vel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:51:38 by ssoumill          #+#    #+#             */
/*   Updated: 2025/05/15 18:16:42 by mvan-vel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	find_back(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			if (str[i + 1] == '\n')
				return (1);
		i++;
	}
	return (0);
}

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

int	check_valid(t_data *data, char *str)
{
	while (*str)
	{
		if (*str == 'N' || *str == 'S' || *str == 'W' || *str == 'E')
		{
			data->count_player++;
			if (data->count_player > 1)
			{
				err_msg("too many player !", NULL, 0);
				data->handle_error = 1;
			}
		}
		else if (*str != '0' && *str != '1' && *str != ' ' && *str != '\n')
		{
			err_msg("invalid caracter in map !", NULL, 0);
			data->handle_error = 1; // 1 = pas les bons caractere
		}
		str++;
	}
	return (data->handle_error);
}

int	map_copy(t_data *data)
{
	char	*temp;

	check_valid(data, data->map_first_line);
	while (1)
	{
		temp = get_next_line(data->fd_map);
		if (temp == NULL)
			break ;
		check_valid(data, temp);
		temp = ft_strtrim(temp, " ");
		data->map_first_line = ft_strjoin(data->map_first_line, temp);
		free(temp);
	}
	if (data->count_player == 0)
	{
		err_msg("need a player !", NULL, 0);
		data->handle_error = 1;
	}
	data->map = ft_split(data->map_first_line, '\n');
	free(data->map_first_line);
	free(temp);
	return (data->handle_error);
}

int	copy_check_map(t_data *data)
{
	int	i;

	i = 0;
	if (map_copy(data))
	{
		ft_free_texture(data);
		ft_free_tab(data->map);
		return (1);
	}
	while (data->map[i])
	{
		data->map[i] = ft_strtrim(data->map[i], " ");
		i++;
	}
	get_pos(data);
	if (data->larg_row < 3 || data->nbr_line < 3)
	{
		err_msg("invalid map !", NULL, 1);
		ft_free_texture(data);
		ft_free_tab(data->map);
		return (1);
	}
	if (pos_player(data))
	{
		err_msg("position player error !", NULL, 1);
		ft_free_texture(data);
		ft_free_tab(data->map);
		return (1);
	}
	i = 0;
	while (data->map[i])
	{
		printf("<%s>\n", data->map[i]);
		i++;
	}
	if (get_map_square(data))
	{
		ft_free_texture(data);
		return (1);
	}
	return (0);
}
