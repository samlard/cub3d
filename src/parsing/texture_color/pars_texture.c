/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-vel <mvan-vel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 11:58:54 by ssoumill          #+#    #+#             */
/*   Updated: 2025/05/30 16:32:37 by mvan-vel         ###   ########.fr       */
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

void	verif_flag(char *str, t_data *data)
{
	if (ft_strnstr(str, "NO", 3) != 0)
		data->f_no += 1;
	if (ft_strnstr(str, "SO", 3) != 0)
		data->f_so += 1;
	if (ft_strnstr(str, "WE", 3) != 0)
		data->f_we += 1;
	if (ft_strnstr(str, "EA", 3) != 0)
		data->f_ea += 1;
	if (ft_strnstr(str, "C", 2) != 0)
		data->f_c += 1;
	if (ft_strnstr(str, "F", 2) != 0)
		data->f_f += 1;
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
	tmp = ft_strtrim(str, "\n");
	result = ft_strtrim(tmp, " ");
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
		data->west = get_texture(str, 1, data->west, data);
	else if (ft_strnstr(str, "C", 2) != NULL)
		data->c = get_texture(str, 0, data->c, data);
	else if (ft_strnstr(str, "F", 2) != NULL)
		data->f = get_texture(str, 0, data->f, data);
	else if (ft_strchr(str, '1') || (ft_strchr(str, '0')))
	{
		data->map_first_line = ft_strtrim(str, " ");
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
		end = handle_texture(data, str);
		if (end > 0)
		{
			free(str);
			break ;
		}
		free(str);
		check_empty++;
	}
	return (name_error_texture(data, end));
}
