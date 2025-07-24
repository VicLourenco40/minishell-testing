#include <libft.h>

int	env(char **envp)
{
	while (*envp)
		ft_putendl_fd(*envp++, 1);
	return (0);
}
