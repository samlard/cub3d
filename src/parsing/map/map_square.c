/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:24:05 by mvan-vel          #+#    #+#             */
/*   Updated: 2025/05/28 22:43:33 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

size_t	ft_strcpy(char *dst, const char *src)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(src);
	if (j < 1)
		return (j);
	while (src[i] && i < j)
	{
		dst[i] = src[i];
		i++;
	}
	return (j);
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

char	**cpy_map(char **map, t_data *data)
{
	char	**tab;
	int		i;

	i = 0;
	tab = malloc((data->nbr_line + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	while (map[i])
	{
		tab[i] = malloc((data->larg_row + 1) * sizeof(char));
		ft_strcpy(tab[i], map[i]);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

int	get_map_square(t_data *data)
{
	char	**tab;
	int		i;

	i = 0;
	tab = malloc((data->nbr_line + 1) * sizeof(char *));
	if (!tab)
		return (err_msg("initialization malloc", NULL, 1));
	while (i < data->nbr_line)
	{
		tab[i] = malloc((data->larg_row + 1) * sizeof(char));
		ft_memset(tab[i], ' ', data->larg_row + 1);
		ft_strcpy(tab[i], data->map[i]);
		i++;
	}
	tab[i] = NULL;
	i = 0;
	ft_free(data->map);
	data->map = cpy_map(tab, data);
	ft_free_tab(tab);
	backtrack(data, data->map, data->player->pos_y, data->player->pos_x);
	if (data->flag == 1)
	{
		ft_free_tab(data->map);
		return (err_msg("invalid map, there is a hole!", NULL, 1));
	}
	return (0);
}
