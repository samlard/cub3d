/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-vel <mvan-vel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:31:47 by mvan-vel          #+#    #+#             */
/*   Updated: 2025/05/30 17:38:23 by mvan-vel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	name_error_texture(t_data *data, int end)
{
	int	i;

	i = 0;
	if (data->f_no == 0 || data->f_no > 1 || !data->north)
		i = err_msg("only 1 texture for NO, no more, no less !", NULL, 1);
	if (data->f_so == 0 || data->f_so > 1 || !data->south)
		i = err_msg("only 1 texture for SO, no more, no less !", NULL, 1);
	if (data->f_we == 0 || data->f_we > 1 || !data->west)
		i = err_msg("only 1 texture for WE, no more, no less !", NULL, 1);
	if (data->f_ea == 0 || data->f_ea > 1 || !data->east)
		i = err_msg("only 1 texture for EA, no more, no less !", NULL, 1);
	if (data->f_c == 0 || data->f_c > 1 || !data->c)
		i = err_msg("only 1 C ask for ceiling color, no more, no less !", NULL,
				1);
	if (data->f == 0 || data->f_f > 1 || !data->f)
		i = err_msg("only 1 F ask for floor color, no more, no less !", NULL,
				1);
	if (end == 0)
		i = (err_msg("missing map !", NULL, 1));
	if (end == 2)
		i = 1;
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

int	check_tab(char **tab, int i, t_data *data)
{
	char	*str;

	while (tab[i])
	{
		str = ft_strtrim(tab[i], " ");
		if (!str)
			handle_error(data, 0);
		if (check_digit(str, i))
		{
			free(str);
			return (1);
		}
		free(str);
		i++;
	}
	return (0);
}
