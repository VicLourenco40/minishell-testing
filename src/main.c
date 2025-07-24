#include <minishell.h>
#include <libft.h>

int	main(int argc, char **argv, char **envp)
{
	if (argc < 2)
		return (1);
	if (!ft_strcmp("echo", argv[1]))
		return (echo(&argv[1]));
	if (!ft_strcmp("cd", argv[1]))
		return (cd(argc - 1, &argv[1]));
	if (!ft_strcmp("pwd", argv[1]))
		return (pwd());
	if (!ft_strcmp("env", argv[1]))
		return (env(envp));
}
