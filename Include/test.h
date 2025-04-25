/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-vel <mvan-vel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:39:26 by mvan-vel          #+#    #+#             */
/*   Updated: 2025/04/19 17:24:04 by mvan-vel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include "../libft42/Include/get_next_line.h"
# include "../libft42/Include/libft.h"
# include "../minilibx-linux/mlx.h"
# include "color.h"
# include <X11/X.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
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
# define PI 3.14159265358979323846

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 1510
# endif

# ifndef SQUARE_SIZE
#  define SQUARE_SIZE 64
# endif

# ifndef MOVE_SPEED
#  define MOVE_SPEED 7
# endif

# ifndef WIN_WIDTH
#  define WIN_WIDTH 2024
# endif

// message error

# define ERROR_CUB "Not a .cub file"
# define ERROR_TEXTURE "Not enough pack texture"
# define ERROR_MLX_INIT "Crash when lauching mlx_init()"
# define ERROR_WIN_INIT "Crash when creating the window"

typedef struct s_player	t_player;
// typedef struct s_key	t_key;

typedef struct s_key
{
	int					key_w;
	int					key_s;
	int					key_a;
	int					key_d;
	int					key_l;
	int					key_r;
}						t_key;

typedef struct s_data
{
	void				*mlx;
	void				*win;
	int					size_line;
	int					bpp;
	int					win_height;
	int					endian;
	int					win_width;
	void				*img;
	void				*img_addr;
	char				**map;
	int					fd_map;
	int					count_direction;
	int					count_player;
	int					handle_error;
	char				*NO;
	char				*SO;
	char				*EA;
	char				*WE;
	char				*F;
	char				*C;
	int					flag;
	int					nbr_line;
	int					larg_row;
	t_player			*player;
	t_key				key;
}						t_data;

typedef struct s_player
{
	float				pos_x;
	float				pos_y;
	float pdx; //correspond a la pente (direction)
	float				pdy;
	float				pa;

}						t_player;

// parsing

int						check_cub(char *str, t_data *data);
int						parsing(t_data *data);
int						copy_check_map(t_data *data);
int					get_map_square(t_data *data);

// handle error + init data

void					init_data(t_data *data);
int						init_window(t_data *data);
void					handle_error(t_data *data);
int						err_msg(char *detail, char *str, int code);
void	ft_free_tab(char **tab);
void	ft_free_texture(t_data *data);

//draw function
void					draw_map(t_data *data);
void					drawPlayer(t_data *data);
int						display(t_data *data);
int						handle_keypress(int keycode, t_data *data);
int						handle_keyrelease(int keysym, t_data *data);
void					clear_image(t_data *data, int color);

// moove function
void					moove_up(t_data *data);
void					moove_down(t_data *data);
void					moove_left(t_data *data);
void					moove_right(t_data *data);
void					ft_rotate(t_data *data);
float					deg_to_rad(float pa);

#endif
