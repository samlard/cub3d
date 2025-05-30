/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-vel <mvan-vel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:24:05 by mvan-vel          #+#    #+#             */
/*   Updated: 2025/05/30 18:05:03 by mvan-vel         ###   ########.fr       */
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
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	return (j);
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
		if (!tab[i])
			handle_error(data, 0);
		ft_strcpy(tab[i], map[i]);
		tab[i][data->larg_row] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

void	get_map_square(t_data *data)
{
	char	**tab;
	int		i;

	i = 0;
	tab = malloc((data->nbr_line + 1) * sizeof(char *));
	if (!tab)
		handle_error(data, 0);
	while (i < data->nbr_line)
	{
		tab[i] = malloc((data->larg_row + 1) * sizeof(char));
		if (!tab[i])
			handle_error(data, 0);
		ft_memset(tab[i], ' ', data->larg_row);
		tab[i][data->larg_row] = '\0';
		ft_strcpy(tab[i], data->map[i]);
		tab[i][data->larg_row] = '\0';
		i++;
	}
	tab[i] = NULL;
	ft_free_tab(data->map);
	data->map = cpy_map(tab, data);
	ft_free_tab(tab);
}
