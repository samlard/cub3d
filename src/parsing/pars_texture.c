#include "test.h"

int	check_cub(char *str, t_data *data)
{
	if ((data->fd_map = open(str, O_RDONLY)) == -1)
		return (err_msg("directory not found", NULL, 0));
	if (ft_strlen(str) < 5)
		return (err_msg(ERROR_CUB, NULL, 0));
	while (*str && *str != '.')
		str++;
	if (ft_strcmp(str, ".cub") != 0)
		return (err_msg(ERROR_CUB, NULL, 0));
	return (1);
}

char	*get_texture(char *str, int i, char *final, t_data *data)
{
	char	*result;
	char	*tmp;
	int		j;

	j = 2;
	result = NULL;
	if (final != NULL)
		free(final);
	if (i == 0)
		j = 1;
	data->count_direction++;
	str = str + j;
	while (*str == ' ')
		str++;
	result = ft_strdup(str);
	tmp = result;
	result = ft_strtrim(result, "\n");
	free(tmp);
	return (result);
}

int	handle_texture(t_data *data, char *str)
{
	if ((ft_strnstr(str, "NO ", 3)) != NULL)
		data->NO = get_texture(str, 1, data->NO, data);
	else if (ft_strnstr(str, "SO ", 3) != NULL)
		data->SO = get_texture(str, 1, data->SO, data);
	else if (ft_strnstr(str, "EA ", 3) != NULL)
		data->EA = get_texture(str, 1, data->EA, data);
	else if (ft_strnstr(str, "WE ", 3) != NULL)
		data->WE = get_texture(str, 1, data->WE, data);
	else if (ft_strnstr(str, "C ", 2) != NULL)
		data->C = get_texture(str, 0, data->C, data);
	else if (ft_strnstr(str, "F ", 2) != NULL)
		data->F = get_texture(str, 0, data->F, data);
	else if (ft_strchr(str, '1') || (ft_strchr(str, '0')))
		return (1);
	return (0);
}
int	check_texture(t_data *data)
{
	char	*str;

	str = NULL;
	while (data->count_direction != 6)
	{
		str = get_next_line(data->fd_map);
		if (!str)
			return (1);
		handle_texture(data, str);
		free(str);
	}
	return (0);
}

// attention au leaks quanf il y a repetition de NO SO etc
int	parsing(t_data *data)
{
	if (check_texture(data))
	{
		ft_free_texture(data);
		return (err_msg(ERROR_TEXTURE, NULL, 0));
	}
	if(copy_check_map(data))
		return(0);
	return (1);
}
