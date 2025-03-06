/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:39:26 by mvan-vel          #+#    #+#             */
/*   Updated: 2025/03/06 17:25:20 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

#include "../minilibx-linux/mlx.h"
# include "../libft42/Include/libft.h"
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
    char    **map;
    int     fd_map;
    int     count_direction;
    char    *NO;
    char    *SO;
    char    *EA;
    char    *WE;
    char    *F;
    char    *C;

} t_data ;

// parsing

int check_cub(char *str, t_data *data);

# endif
