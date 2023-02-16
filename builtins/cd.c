
#include "../minishell.h"

int	cd(char **args, t_env *minienv)
{
	char	*path;
	char	*pwd;
	char	*oldpwd;
	char	cwd[PATH_MAX];

	if (args[1] && !str_equal(args[1], "~"))
		path = args[1];
	else
		path = minienv_value("HOME", minienv);
	if (!path)
		return (print_error_msg("cd", "HOME not set"));
	if (chdir(path) != 0)
	{
		print_perror_msg("cd", args[1]);
		return (EXIT_FAILURE);
	}
	pwd = minienv_value("PWD", minienv);
	oldpwd = minienv_value("OLDPWD", minienv);
	if (oldpwd && pwd && *pwd)
		minienv_var_update("OLDPWD", pwd, minienv);
	if (pwd && *pwd && getcwd(cwd, PATH_MAX))
		minienv_var_update("PWD", getcwd(cwd, PATH_MAX), minienv);
	return (EXIT_SUCCESS);
}
