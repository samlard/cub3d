/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 11:58:54 by ssoumill          #+#    #+#             */
/*   Updated: 2025/05/28 22:33:40 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	check_invalid_line(char *str)
{
	while (*str)
	{
		if (*str != ' ' && *str != '\n')
			return (1);
		str++;
	}
	return (0);
}

int	name_error_texture(t_data *data, int end)
{
	int	i;

	i = 0;
	if (data->f_NO == 0 || data->f_NO > 1 || !data->north)
		i = err_msg("only 1 texture for NO, no more, no less !", NULL, 1);
	if (data->f_SO == 0 || data->f_SO > 1 || !data->south)
		i = err_msg("only 1 texture for SO, no more, no less !", NULL, 1);
	if (data->f_WE == 0 || data->f_WE > 1 || !data->WE)
		i = err_msg("only 1 texture for WE, no more, no less !", NULL, 1);
	if (data->f_EA == 0 || data->f_EA > 1 || !data->east)
		i = err_msg("only 1 texture for EA, no more, no less !", NULL, 1);
	if (data->f_C == 0 || data->f_C > 1 || !data->C)
		i = err_msg("only 1 C ask for ceiling color, no more, no less !", NULL,
				1);
	if (data->F == 0 || data->f_F > 1 || !data->F)
		i = err_msg("only 1 F ask for floor color, no more, no less !", NULL,
				1);
	if (end == 0)
		i = (err_msg("missing map !", NULL, 1));
	if (end == 2)
		i = 1;
	return (i);
}

void	verif_flag(char *str, t_data *data)
{
	if (ft_strnstr(str, "NO", 3) != 0)
		data->f_NO += 1;
	if (ft_strnstr(str, "SO", 3) != 0)
		data->f_SO += 1;
	if (ft_strnstr(str, "WE", 3) != 0)
		data->f_WE += 1;
	if (ft_strnstr(str, "EA", 3) != 0)
		data->f_EA += 1;
	if (ft_strnstr(str, "C", 2) != 0)
		data->f_C += 1;
	if (ft_strnstr(str, "F", 2) != 0)
		data->f_F += 1;
}

char	*get_texture(char *str, int i, char *final, t_data *data)
{
	char	*result;
	char	*tmp;
	int		j;

	j = 2;
	result = NULL;
	verif_flag(str, data);
	if (final != NULL)
		free(final);
	if (i == 0)
		j = 1;
	str = str + j;
	while (*str == ' ')
		str++;
	result = ft_strdup(str);
	tmp = result;
	result = ft_strtrim(result, "\n");
	result = ft_strtrim(result, " ");
	free(tmp);
	data->count_texture++;
	return (result);
}

int	handle_texture(t_data *data, char *str)
{
	if ((ft_strnstr(str, "NO", 2)) != NULL)
		data->north = get_texture(str, 1, data->north, data);
	else if (ft_strnstr(str, "SO", 3) != NULL)
		data->south = get_texture(str, 1, data->south, data);
	else if (ft_strnstr(str, "EA", 3) != NULL)
		data->east = get_texture(str, 1, data->east, data);
	else if (ft_strnstr(str, "WE", 3) != NULL)
		data->WE = get_texture(str, 1, data->WE, data);
	else if (ft_strnstr(str, "C", 2) != NULL)
		data->C = get_texture(str, 0, data->C, data);
	else if (ft_strnstr(str, "F", 2) != NULL)
		data->F = get_texture(str, 0, data->F, data);
	else if (ft_strchr(str, '1') || (ft_strchr(str, '0')))
	{
		data->map_first_line = ft_strdup(str);
		data->map_first_line = ft_strtrim(data->map_first_line, " ");
		return (1);
	}
	else if (check_invalid_line(str))
		return (err_msg("invalid line in file :", str, 2));
	return (0);
}

int	check_texture(t_data *data)
{
	char	*str;
	int		check_empty;
	int		end;

	str = NULL;
	check_empty = 0;
	end = 0;
	while (1)
	{
		str = get_next_line(data->fd_map);
		if (!str && check_empty == 0)
			return (err_msg("empty file !", NULL, 1));
		if (!str)
			break ;
		if ((end = handle_texture(data, str)) > 0)
			break ;
		free(str);
		check_empty++;
	}
	return (name_error_texture(data, end));
}
