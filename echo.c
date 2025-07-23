#include <libft.h>

int	main(int argc, char **argv)
{
	int	newline;
	int	i;

	(void)argc;
	newline = 1;
	++argv;
	while (*argv && (*argv)[0] == '-' && (*argv)[1])
	{
		i = 1;
		while ((*argv)[i] == 'n')
			++i;
		if ((*argv)[i])
			break ;
		newline = 0;
		++argv;
	}
	while (*argv)
	{
		ft_putstr_fd(*argv, 1);
		if (*(argv + 1))
			ft_putchar_fd(' ', 1);
		++argv;
	}
	if (newline)
		ft_putchar_fd('\n', 1);
}
