/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:51:38 by ssoumill          #+#    #+#             */
/*   Updated: 2025/03/07 18:10:37 by ssoumill         ###   ########.fr       */
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
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'W' || data->map[i][j] == 'E')
			{
				data->pos_x = j;
				data->pos_y = i;
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

void	backtrack(t_data *data, int x, int y)
{
	if (data->map[x][y] == ' ')
	{
		printf("oui\n");
		data->flag = 1;
		return ;
	}
	data->map[x][y] = 'z';
	if (x > 0 && (y <= (int)ft_strlen(data->map[x - 1])) && (data->map[x
			- 1][y] != 'z' && data->map[x - 1][y] != '1'))
		backtrack(data, x - 1, y);
	if (x < data->nbr_line && (y <= (int)ft_strlen(data->map[x + 1])) && (data->map[x
			+ 1][y] != 'z' && data->map[x + 1][y] != '1'))
		backtrack(data, x + 1, y);
	if (y < (int)ft_strlen(data->map[x]) && (data->map[x][y + 1] != 'z'
			&& data->map[x][y + 1] != '1'))
		backtrack(data, x, y + 1);
	if (y > 0 && (data->map[x][y - 1] != 'z' && data->map[x][y - 1] != '1'))
		backtrack(data, x, y - 1);
}

int	copy_check_map(t_data *data)
{
	int i;

	i = 0;
	map_copy(data);
	if (data->count_player != 1)
	{
		printf("error nb player %d\n", data->count_player);
		data->handle_error = 2; // 2 = trop de player;
								//freemap;
	}
	get_pos(data);
	printf("nbr line %d\n", data->nbr_line);
	backtrack(data, data->pos_y, data->pos_x);
	if (data->flag == 1)
		printf("there is a hole in your ass\n");
	while (data->map[i])
	{
		printf("%s\n", data->map[i]);
		i++;
	}
	return (0);
}