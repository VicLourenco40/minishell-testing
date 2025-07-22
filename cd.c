#include <libft.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>

#define MSG_SIZE 512

static int	cd_error(const char *path, const char *error)
{
	char	message[MSG_SIZE];

	ft_bzero(message, MSG_SIZE);
	ft_strlcat(message, "bash: ", MSG_SIZE);
	if (path)
	{
		ft_strlcat(message, path, MSG_SIZE);
		ft_strlcat(message, ": ", MSG_SIZE);
	}
	if (error)
		ft_strlcat(message, error, MSG_SIZE);
	else
		ft_strlcat(message, strerror(errno), MSG_SIZE);
	ft_strlcat(message, "\n", MSG_SIZE);
	ft_putstr_fd(message, 2);
	return (1);
}

int	main(int argc, char **argv)
{
	const char *const	home = getenv("HOME");
	const char			*path;
	char				cwd[PATH_MAX];

	getcwd(cwd, PATH_MAX);
	printf("%s\n", cwd);
	if (argc > 2)
		return (cd_error(NULL, "cd: too many arguments"));
	path = argv[1];
	if (!path)
	{
		if (!home)
			return (cd_error(NULL, "cd: HOME not set"));
		path = home;
	}
	if (chdir(path))
		return (cd_error(path, strerror(errno)));
	getcwd(cwd, PATH_MAX);
	printf("%s\n", cwd);
}
