#ifndef MINISHELL_H
# define MINISHELL_H

int	echo(char **argv);
int	cd(int argc, char **argv);
int	pwd(void);
int	env(char **envp);

#endif
