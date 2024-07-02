#include "inc/minishell.h"

void	ft_error(char *str, char *arg)
{
	ft_putstr_fd(str, 2);
	if (arg)
		ft_putstr_fd(arg, 2);
	ft_putstr_fd("\n", 2);
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}