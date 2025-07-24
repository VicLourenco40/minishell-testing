#include <libft.h>

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	while (*envp)
		ft_putendl_fd(*envp++, 1);
}
