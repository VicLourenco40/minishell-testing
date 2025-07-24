#include <libft.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

static int	print_error(const char *command, const char *const path,
	const char *const error)
{
	ft_putstr_fd("minishell: ", 2);
	if (command)
	{
		ft_putstr_fd(command, 2);
		ft_putstr_fd(": ", 2);
	}
	if (path)
	{
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
	}
	if (error)
		ft_putendl_fd(error, 2);
	else
		ft_putendl_fd(strerror(errno), 2);
	return (1);
}

int	cd(int argc, char **argv)
{
	const char	*path = argv[1];

	if (argc > 2)
		return (print_error("cd", NULL, "too many arguments"));
	if (!path)
		path = getenv("HOME");
	if (!path)
		return (print_error("cd", NULL, "HOME not set"));
	if (*path && chdir(path))
		return (print_error("cd", path, NULL));
	return (0);
}
