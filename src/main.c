#include "test.h"

int	main(int	ac, char **av)
{
	t_data data;

	if (ac != 2)
		return (1);
	init_data(&data);
	if (!check_cub(av[1], &data))
	{
		printf("invalid map");
		return (1); // invalid extension .cub
	}
	if (!parsing(&data))
		return (1);
	return (0);
}
