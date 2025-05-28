/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_xpm_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:14:06 by mvan-vel          #+#    #+#             */
/*   Updated: 2025/05/28 22:22:48 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	check_xpm(t_data *data)
{
	int	i;

	i = 0;
	if ((access(data->north, F_OK)) == -1)
		i = err_msg("path for NO doesn't exist !", NULL, 1);
	if ((access(data->SO, F_OK)) == -1)
		i = err_msg("path for SO doesn't exist !", NULL, 1);
	if ((access(data->WE, F_OK)) == -1)
		i = err_msg("path for WE doesn't exist !", NULL, 1);
	if ((access(data->EA, F_OK)) == -1)
		i = err_msg("path for EA doesn't exist !", NULL, 1);
	if (i == 0)
	{
		if ((access(data->north, R_OK)) == -1)
			i = err_msg("path for NO not accessible !", NULL, 1);
		if ((access(data->SO, R_OK)) == -1)
			i = err_msg("path for SO not accessible !", NULL, 1);
		if ((access(data->WE, R_OK)) == -1)
			i = err_msg("path for WE not accessible !", NULL, 1);
		if ((access(data->EA, R_OK)) == -1)
			i = err_msg("path for EA not accessible !", NULL, 1);
	}
	return (i);
}

int	ft_atoi_cub(const char *str)
{
	int	i;
	int	result;
	int	final;

	i = 0;
	final = 0;
	result = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		final = final * 10 + (str[i] - 48);
		i++;
	}
	return (final * result);
}

int	ft_strlen_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		i++;
	}
	return (i);
}

int	check_digit(char *str, int i)
{
	if (!*str)
	{
		if (i == 0)
			return (err_msg("number missing for C : need 3, no more, no less !",
							NULL,
							1));
		else
			return (err_msg("number missing for F : need 3, no more, no less !",
							NULL,
							1));
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
		{
			if (i == 0)
				return (err_msg("only number for C", NULL, 1));
			else
				return (err_msg("only number for F!", NULL, 1));
		}
		str++;
	}
	return (0);
}
int	convert_color(char **tab, int i, int j)
{
	int	r;
	int	g;
	int	b;

	while (tab[j])
	{
		if ((tab[j] = ft_strtrim(tab[j], " ")) == NULL)
			return (-1);
		if (check_digit(tab[j], i))
			return (-1);
		j++;
	}
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
					NULL,
					0);
		else
			err_msg("need 3 number no more, no less, for F : xxx, xxx, xxx!",
					NULL,
					0);
		return (ft_free_tab(tab), 1);
	}
	if (i == 0)
	{
		if ((data->rgb_c = convert_color(tab, i, 0)) == -1)
			return (ft_free_tab(tab), 1);
	}
	else
	{
		if ((data->rgb_f = convert_color(tab, i, 0)) == -1)
			return (ft_free_tab(tab), 1);
	}
	return (0);
}

int	check_xpm_color(t_data *data)
{
	if (check_xpm(data))
	{
		ft_free_texture(data);
		close(data->fd_map);
		return (1);
	}
	if (get_color(data, data->C, 0) || get_color(data, data->F, 1))
	{
		ft_free_texture(data);
		close(data->fd_map);
		//ce faire une fonction pour l handle d error pour bien tout free et close proprement
		return (1);
	}
	return (0);
}
