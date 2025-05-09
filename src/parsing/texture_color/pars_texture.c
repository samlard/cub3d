#include "test.h"

int name_error_texture(t_data *data)
{
	int i;

	i = 0;
    if (data->f_NO == 0 || data->f_NO > 1 || !data->NO)
    	i = err_msg("only 1 texture for NO, no more, no less !", NULL, 1);
    if (data->f_SO == 0 || data->f_SO > 1 || !data->SO)
    	i = err_msg("only 1 texture for SO, no more, no less !", NULL, 1);
    if (data->f_WE == 0 || data->f_WE > 1 || !data->WE)
    	i = err_msg("only 1 texture for WE, no more, no less !", NULL, 1);
    if (data->f_EA == 0 || data->f_EA > 1 || !data->EA)
    	i = err_msg("only 1 texture for EA, no more, no less !", NULL, 1);
    if (data->f_C == 0 || data->f_C > 1 || !data->C)
        i = err_msg("only 1 C ask for ceiling color, no more, no less !", NULL, 1);
    if (data->F == 0 || data->f_F > 1 || !data->F)
        i = err_msg("only 1 F ask for floor color, no more, no less !", NULL, 1);
return(i);
}

void verif_flag(char *str, t_data *data)
{
	if (ft_strnstr(str, "NO", 3) != 0)
		data->f_NO += 1;
	if (ft_strnstr(str, "SO", 3) != 0)
		data->f_SO += 1;
	if (ft_strnstr(str, "WE", 3) != 0)
		data->f_WE += 1;
	if (ft_strnstr(str, "EA", 3) != 0)
		data->f_EA += 1;
	if (ft_strnstr(str, "C", 2) != 0)
		data->f_C += 1;
	if (ft_strnstr(str, "F", 2) != 0)
		data->f_F += 1;
}


char	*get_texture(char *str, int i, char *final, t_data *data)
{
	char	*result;
	char	*tmp;
	int		j;

	j = 2;
	result = NULL;
	verif_flag(str, data);
	if (final != NULL)
		free(final);
	if (i == 0)
		j = 1;
	str = str + j;
	while (*str == ' ')
		str++;
	result = ft_strdup(str);
	tmp = result;
	result = ft_strtrim(result, "\n");
	result = ft_strtrim(result, " ");
	free(tmp);
	data->count_texture++;
	return (result);
}

int	handle_texture(t_data *data, char *str)
{
	if ((ft_strnstr(str, "NO", 3)) != NULL)
		data->NO = get_texture(str, 1, data->NO, data);
	else if (ft_strnstr(str, "SO", 3) != NULL)
		data->SO = get_texture(str, 1, data->SO, data);
	else if (ft_strnstr(str, "EA", 3) != NULL)
		data->EA = get_texture(str, 1, data->EA, data);
	else if (ft_strnstr(str, "WE", 3) != NULL)
		data->WE = get_texture(str, 1, data->WE, data);
	else if (ft_strnstr(str, "C", 2) != NULL)
		data->C = get_texture(str, 0, data->C, data);
	else if (ft_strnstr(str, "F", 2) != NULL)
		data->F = get_texture(str, 0, data->F, data);
	else if (ft_strchr(str, '1') || (ft_strchr(str, '0')))
		return (1);
	return (0);
}
int	check_texture(t_data *data)
{
	char	*str;
	//int		err_flag;

	str = NULL;
	//err_flag = 0; //idee de boucle pour verifier plus que les 6 textures voirent si il y en a pas apres mais probleme sur lecture de map;
	while (data->count_texture != 6)
	{
		str = get_next_line(data->fd_map);
		if (!str)
			return (1);
		handle_texture(data, str);
		free(str);
	}
	return (name_error_texture(data));
}
