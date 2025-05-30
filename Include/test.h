/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-vel <mvan-vel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:39:26 by mvan-vel          #+#    #+#             */
/*   Updated: 2025/05/30 17:54:23 by mvan-vel         ###   ########.fr       */
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
#  define WIN_HEIGHT 1000
# endif

# ifndef SQUARE_SIZE
#  define SQUARE_SIZE 64.0f
# endif

# ifndef MOVE_SPEED
#  define MOVE_SPEED 4.0f
# endif

# ifndef WIN_WIDTH
#  define WIN_WIDTH 1500
# endif

# ifndef FOV
#  define FOV 60
# endif

# ifndef ROT_SPEED
#  define ROT_SPEED 2.2f
# endif

# define NORTH 0

# define SOUTH 1

# define EAST 2

# define WEST 3

# define UP_RIGHT 0
# define UP_LEFT 1
# define DOWN_RIGHT 2
# define DOWN_LEFT 3

// message error

# define ERROR_CUB "Not a .cub file"
# define ERROR_TEXTURE "Not enough pack texture"
# define ERROR_MLX_INIT "Crash when lauching mlx_init()"
# define ERROR_WIN_INIT "Crash when creating the window"

typedef struct s_player	t_player;

typedef struct s_texture
{
	int					endian;
	int					bpp;
	int					size_line;
	int					width;
	int					height;
	char				*addr;
	void				*img;
	int					text_x;
	int					text_y;
	float				texture_pos;
	float				step;
}						t_texture;

typedef struct s_ray
{
	float				ra;
	float				tang;
	float				px;
	float				py;
	int					map_x;
	int					map_y;
	float				dist;
	float				xo;
	float				yo;
	float				rx_v;
	float				ry_v;
	float				ry_h;
	float				rx_h;
	int					color;
	float				v_dist;
	float				h_dist;
	float				line_h;
	float				line_o;
	float				ca;

}						t_ray;

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
	char				*map_first_line;
	int					fd_map;
	int					count_texture;
	int					count_player;
	int					handle_error;
	char				*north;
	int					f_no;
	char				*south;
	int					f_so;
	char				*east;
	int					f_ea;
	char				*west;
	int					f_we;
	char				*f;
	int					f_f;
	char				*c;
	int					f_c;
	int					flag;
	int					nbr_line;
	int					larg_row;
	float				speed_factor;
	t_player			*player;
	t_ray				*ray;
	t_key				key;
	void				*img_no;
	void				*img_so;
	void				*img_ea;
	void				*img_we;
	int					rgb_c;
	int					rgb_f;
	t_texture			texture[4];
}						t_data;

typedef struct s_player
{
	float				pos_x;
	float				pos_y;
	float				pdx;
	float				pdy;
	float				pa;

}						t_player;

void					get_xpm(t_data *data);
// parsing

int						check_cub(char *str, t_data *data);
void					parsing(t_data *data, char *str);
int						check_texture(t_data *data);
void					copy_check_map(t_data *data);
void					get_map_square(t_data *data);
void					check_xpm_color(t_data *data);
void					get_start_angle(char c, t_data *data);
int						name_error_texture(t_data *data, int end);
int						ft_strlen_tab(char **tab);
int						ft_atoi_cub(const char *str);
int						check_digit(char *str, int i);
int						check_tab(char **tab, int i, t_data *data);
void					check_valid(t_data *data, char *str);
void					backtrack(t_data *data, char **map, int x, int y);

// handle error + init data

void					init_data(t_data *data);
void					init_key(t_data *data);
int						init_window(t_data *data);
int						err_msg(char *detail, char *str, int code);
void					ft_free_tab(char **tab);
void					ft_free_texture(t_data *data);
void					handle_error(t_data *data, int i);

//draw function
int						display(t_data *data);
int						handle_keypress(int keycode, t_data *data);
int						handle_keyrelease(int keysym, t_data *data);
void					clear_image(t_data *data, int color);
float					fix_angle(float ra);
void					draw_ray(t_data *data);
void					my_pixel_put(t_data *data, int x, int y, int color);
void					vertical_distance(t_data *data, t_ray *ray);
void					horizontal_distance(t_data *data, t_ray *ray);
void					compute_distance(float pa, t_ray *ray);

// move function
void					move_up(t_data *data);
void					move_down(t_data *data);
void					move_left(t_data *data);
void					move_right(t_data *data);
void					ft_rotate(t_data *data);
float					deg_to_rad(float pa);

#endif
