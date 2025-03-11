#include "test.h"

void	handle_error(t_data *data)
{
	(void)data;
}

void	init_data(t_data *data)
{
	data->map = NULL;
	data->fd_map = 0;
	data->count_direction = 0;
	data->count_player = 0;
	data->handle_error = 0;
	data->NO = NULL;
	data->SO = NULL;
	data->EA = NULL;
	data->WE = NULL;
	data->F = NULL;
	data->C = NULL;
    data->flag = 0;
	data->pos_x = 0;
	data->pos_y = 0;
    data->nbr_line = 0;
	data->larg_row = 0;
}