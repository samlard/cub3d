/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 11:58:44 by ssoumill          #+#    #+#             */
/*   Updated: 2025/05/28 20:53:51 by ssoumill         ###   ########.fr       */
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
	if (data->NO)
		free(data->NO);
	if (data->SO)
		free(data->SO);
	if (data->EA)
		free(data->EA);
	if (data->WE)
		free(data->WE);
	if (data->C)
		free(data->C);
	if (data->F)
		free(data->F);
	free(data->player);
}
