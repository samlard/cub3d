/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-vel <mvan-vel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:41:40 by mvan-vel          #+#    #+#             */
/*   Updated: 2025/06/04 16:22:52 by mvan-vel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	check_valid(t_data *data, char *str)
{
	while (*str)
	{
		if (*str == 'N' || *str == 'S' || *str == 'W' || *str == 'E')
		{
			data->count_player++;
			get_start_angle(*str, data);
			if (data->count_player > 1)
			{
				err_msg("too many player !", NULL, 0);
				handle_error(data, 1);
			}
		}
		else if (*str != '0' && *str != '1' && *str != ' ' && *str != '\n')
		{
			err_msg("invalid caracter in map !", NULL, 0);
			handle_error(data, 1);
		}
		str++;
	}
}

void	backtrack(t_data *data, char **map, int x, int y)
{
	if (map[x][y] == ' ' || (map[x][y] == '0' && (y == ((int)ft_strlen(map[x])
					- 1) || y == 0 || x == 0 || x == data->nbr_line - 1)))
	{
		data->flag = 1;
		return ;
	}
	map[x][y] = 'z';
	if (x > 0 && (y <= (int)ft_strlen(map[x - 1]) - 1) && (map[x - 1][y] != 'z'
			&& map[x - 1][y] != '1'))
		backtrack(data, map, x - 1, y);
	if (x < data->nbr_line - 1 && (y <= (int)ft_strlen(map[x + 1]) - 1)
		&& (map[x + 1][y] != 'z' && map[x + 1][y] != '1'))
		backtrack(data, map, x + 1, y);
	if (y < ((int)ft_strlen(map[x]) - 1) && (map[x][y + 1] != 'z' && map[x][y
			+ 1] != '1'))
		backtrack(data, map, x, y + 1);
	if (y > 0 && (map[x][y - 1] != 'z' && map[x][y - 1] != '1'))
		backtrack(data, map, x, y - 1);
}

void	replace_all_map(char **tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] != 'z' && tab[i][j] != '\0')
				tab[i][j] = '1';
			j++;
		}
		i++;
	}
}
