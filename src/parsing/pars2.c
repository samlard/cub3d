#include "test.h"

int	check_texture(t_data *data)
{
	char	*str;

	while (1)
	{
		str = get_next_line(data->fd_map);
		if (ft_strnstr(str, "NO", 1) != NULL)
			data->NO = get_texture(str, 0);
		else if (ft_strnstr(str, "SO", 1) != NULL)
			data->SO = get_texture(str, 0);
		else if (ft_strnstr(str, "EA", 1) != NULL)
			data->EA = get_texture(str, 0);
		else if (ft_strnstr(str, "WE", 1) != NULL)
			data->WE = get_texture(str, 0);
		else if (ft_strnstr(str, "C ", 1) != NULL)
			data->C = get_texture(str, 1);
		else if (ft_strnstr(str, "F ", 1) != NULL)
			data->F= get_texture(str, 1);
        else if(ft_strchr(str, '1') || (ft_strchr(str, '0')))
        {
            free(str);
            return (1);
        }
        free(str);
	}
}

int	parsing(t_data *data)
{
	if (check_texture(data))
		return (0);
}