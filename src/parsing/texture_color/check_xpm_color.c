/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_xpm_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-vel <mvan-vel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:14:06 by mvan-vel          #+#    #+#             */
/*   Updated: 2025/05/30 16:50:17 by mvan-vel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	check_xpm(t_data *data)
{
	int	i;

	i = 0;
	if ((access(data->north, F_OK)) == -1)
		i = err_msg("path for NO doesn't exist !", NULL, 1);
	if ((access(data->south, F_OK)) == -1)
		i = err_msg("path for SO doesn't exist !", NULL, 1);
	if ((access(data->west, F_OK)) == -1)
		i = err_msg("path for WE doesn't exist !", NULL, 1);
	if ((access(data->east, F_OK)) == -1)
		i = err_msg("path for EA doesn't exist !", NULL, 1);
	if (i == 0)
	{
		if ((access(data->north, R_OK)) == -1)
			i = err_msg("path for NO not accessible !", NULL, 1);
		if ((access(data->south, R_OK)) == -1)
			i = err_msg("path for SO not accessible !", NULL, 1);
		if ((access(data->west, R_OK)) == -1)
			i = err_msg("path for WE not accessible !", NULL, 1);
		if ((access(data->east, R_OK)) == -1)
			i = err_msg("path for EA not accessible !", NULL, 1);
	}
	return (i);
}

int	convert_color(char **tab, int i)
{
	int	r;
	int	g;
	int	b;

	if (check_tab(tab, 0))
		return (-1);
	r = ft_atoi_cub(tab[0]);
	g = ft_atoi_cub(tab[1]);
	b = ft_atoi_cub(tab[2]);
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
	{
		if (i == 0)
			return (err_msg("number should be between 0 and 255 for C!", NULL,
					-1));
		else
			return (err_msg("number should be between 0 and 255 for F!", NULL,
					-1));
	}
	return ((r << 16) + (g << 8) + b);
}

int	get_color(t_data *data, char *str, int i)
{
	char	**tab;

	if (!(tab = ft_split(str, ',')))
		return (err_msg("split malloc error !", NULL, 1));
	if (ft_strlen_tab(tab) != 3)
	{
		if (i == 0)
			err_msg("need 3 number no more, no less, for C : xxx, xxx, xxx!",
				NULL, 0);
		else
			err_msg("need 3 number no more, no less, for F : xxx, xxx, xxx!",
				NULL, 0);
		return (ft_free_tab(tab), 1);
	}
	if (i == 0)
	{
		if ((data->rgb_c = convert_color(tab, i)) == -1)
			return (ft_free_tab(tab), 1);
	}
	else
	{
		if ((data->rgb_f = convert_color(tab, i)) == -1)
			return (ft_free_tab(tab), 1);
	}
	ft_free_tab(tab);
	return (0);
}

void	check_xpm_color(t_data *data)
{
	if (check_xpm(data))
		handle_error(data);
	if (get_color(data, data->c, 0) || get_color(data, data->f, 1))
		handle_error(data);
}
