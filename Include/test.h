/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-vel <mvan-vel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:39:26 by mvan-vel          #+#    #+#             */
/*   Updated: 2025/03/11 16:25:00 by mvan-vel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include "../libft42/Include/get_next_line.h"
# include "../libft42/Include/libft.h"
# include "../minilibx-linux/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_data
{
	char	**map;
	int		fd_map;
	int		count_direction;
	int		count_player;
	int		handle_error;
	char	*NO;
	char	*SO;
	char	*EA;
	char	*WE;
	char	*F;
	char	*C;
	int		flag;
	int		pos_x;
	int		nbr_line;
	int		pos_y;
	int		larg_row;
}			t_data;

// parsing

int			check_cub(char *str, t_data *data);
int			parsing(t_data *data);
int			copy_check_map(t_data *data);
void		get_map_square(t_data *data);

// handle error + init data

void		init_data(t_data *data);
void		handle_error(t_data *data);

#endif
