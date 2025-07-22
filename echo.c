#include <unistd.h>
#include <string.h>

int	main(int argc, char **argv)
{
	int	newline;
	int	i;

	(void)argc;
	newline = 1;
	++argv;
	while (*argv && **argv == '-' && (*argv)[1] == 'n')
	{
		i = 2;
		while ((*argv)[i] == 'n')
			++i;
		if ((*argv)[i])
			break ;
		newline = 0;
		++argv;
	}
	while (*argv)
	{
		write(1, *argv, strlen(*argv));
		if (*(argv + 1))
			write(1, " ", 1);
		++argv;
	}
	if (newline)
		write(1, "\n", 1);
}
