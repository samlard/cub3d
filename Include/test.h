/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:39:26 by mvan-vel          #+#    #+#             */
/*   Updated: 2025/03/29 14:34:16 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include "../libft42/Include/get_next_line.h"
# include "../libft42/Include/libft.h"
# include "../minilibx-linux/mlx.h"
# include "color.h"
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

//define window

#ifndef WIN_HEIGHT
# define WIN_HEIGHT 1000
#endif

#ifndef WIN_WIDTH
# define WIN_WIDTH 1400
#endif

// message error

# define ERROR_CUB "Not a .cub file"
# define ERROR_TEXTURE "Not enough pack texture"
# define ERROR_MLX_INIT "Crash when lauching mlx_init()"
# define ERROR_WIN_INIT "Crash when creating the window"

typedef struct s_data
{

	void	*mlx;
	void	*win;
	int		win_height;
	int		win_width;
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
	float		pos_x;
	int		nbr_line;
	float		pos_y;
	int		larg_row;
}			t_data;


// parsing

int			check_cub(char *str, t_data *data);
int			parsing(t_data *data);
int			copy_check_map(t_data *data);
void		get_map_square(t_data *data);

// handle error + init data

void		init_data(t_data *data);
int			init_window(t_data *data);
void		handle_error(t_data *data);
int			err_msg(char *detail, char *str, int code);

#endif
