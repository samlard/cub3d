/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-vel <mvan-vel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:39:26 by mvan-vel          #+#    #+#             */
/*   Updated: 2025/05/15 17:40:54 by mvan-vel         ###   ########.fr       */
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
#  define SQUARE_SIZE 64
# endif

# ifndef MOVE_SPEED
#  define MOVE_SPEED 4
# endif

# ifndef WIN_WIDTH
#  define WIN_WIDTH 1500
# endif

# ifndef FOV
#  define FOV 60
# endif

# ifndef ROT_SPEED
#  define ROT_SPEED 0.8
# endif

// message error

# define ERROR_CUB "Not a .cub file"
# define ERROR_TEXTURE "Not enough pack texture"
# define ERROR_MLX_INIT "Crash when lauching mlx_init()"
# define ERROR_WIN_INIT "Crash when creating the window"

typedef struct s_player	t_player;
typedef struct s_ray	t_ray;
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
	char				*map_first_line;
	int					fd_map;
	int					count_texture;
	int					count_player;
	int					handle_error;
	char				*NO;
	int					f_NO;
	char				*SO;
	int					f_SO;
	char				*EA;
	int					f_EA;
	char				*WE;
	int					f_WE;
	char				*F;
	int					f_F;
	char				*C;
	int					f_C;
	int					flag;
	int					nbr_line;
	int					larg_row;
	float				speed_factor;
	t_player			*player;
	t_ray				*ray;
	// t_raycast			raycast;
	t_key				key;
	// mlx image et la couleur
	void 				*img_no;
	void 				*img_so;
	void 				*img_ea;
	void 				*img_we;
	int					rgb_c;
	int					rgb_f;
}						t_data;

typedef struct s_player
{
	float				pos_x;
	float				pos_y;
	float pdx; //correspond a la pente (direction)
	float				pdy;
	float				pa;

}						t_player;

typedef struct s_ray
{
	float ra; //vecteur directon du player
	float				Tan;
	float px;   //pos en x du joueur
	float py;   //pos en y du joueur
	int map_x;  //index position dans la map 2d
	int map_y;  //index position dans la map 2d
	float dist; // dist plus courte entre h_dist et v_dist
	float xo;   // pas a faire quand check si mur
	float yo;   //pas a faire quand check si mur
	float rx;   //coordone avec ligne verticale la plus proche
	float ry;   //coordone avec ligne verticale la plus proche
	int					color;
	float				v_dist;
	float				h_dist;
	float				line_h;
	float				line_o;
	float				ca;

}						t_ray;

// }						t_raycast;


void get_xpm(t_data *data);
// parsing

int						check_cub(char *str, t_data *data);
int						parsing(t_data *data, char *str);
int						check_texture(t_data *data);
int						copy_check_map(t_data *data);
int						get_map_square(t_data *data);
int 					check_xpm_color(t_data *data);

// handle error + init data

void					init_data(t_data *data);
void					init_key(t_data *data);
int						init_window(t_data *data);
void					handle_error(t_data *data);
int						err_msg(char *detail, char *str, int code);
void					ft_free_tab(char **tab);
void					ft_free_texture(t_data *data);

//draw function
void					draw_map(t_data *data);
void					drawPlayer(t_data *data);
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

// moove function
void					moove_up(t_data *data);
void					moove_down(t_data *data);
void					moove_left(t_data *data);
void					moove_right(t_data *data);
void					ft_rotate(t_data *data);
float					deg_to_rad(float pa);

#endif
