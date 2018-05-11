#include "wolf.h"

void	error(char *str)
{
	ft_putendl(str);
	exit(0);
}

int			main(int ac, char *av[])
{
	t_all data;

	if (ac == 2)
	{
		if (open(av[1], O_RDONLY) == -1)
			error("Error occured when opening map file");
		else
		{
			reader(av[1], &data);
			initialize_variable(&data);
			data.x = 0;
			while (data.running == 0)
			{
				while (data.x++ < data.width)
					raycasting(&data);
				key_movements(&data);
			}
			SDL_DestroyWindow(data.window);
			SDL_Quit();
		}
	}
	else
		error("more than one argument was given");
	return (0);
}