/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 11:58:44 by ssoumill          #+#    #+#             */
/*   Updated: 2025/05/30 18:41:49 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	err_msg(char *detail, char *str, int code)
{
	ft_putstr_fd(RED BOLD "cub3D: Error", 2);
	if (detail)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(detail, 2);
	}
	if (str)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(str, 2);
	}
	ft_putstr_fd("\n" RESET, 2);
	return (code);
}

void	handle_error(t_data *data, int i)
{
	if (i == 0)
		err_msg("malloc !", NULL, 1);
	ft_free_texture(data);
	if (data->map)
		ft_free_tab(data->map);
	if (i == 2)
	{
		destroy_xpm(data);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
	}
	close(data->fd_map);
	exit(1);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

void	ft_free_texture(t_data *data)
{
	if (data->north)
		free(data->north);
	if (data->south)
		free(data->south);
	if (data->east)
		free(data->east);
	if (data->west)
		free(data->west);
	if (data->c)
		free(data->c);
	if (data->f)
		free(data->f);
	if (data->map_first_line != NULL)
		free(data->map_first_line);
	get_next_line(-1);
	free(data->player);
}

int	exit_prog(t_data *data)
{
	destroy_xpm(data);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
	}
	ft_free_tab(data->map);
	exit(0);
	return (0);
}
