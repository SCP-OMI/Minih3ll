#include "../minishell.h"

int	fits_in_long_long(char *str)
{
	long long	out;
	int			c;

	if (ft_strlen(str) > 20)
		return (0);
	if (ft_strncmp(str, "-9223372036854775808", 21) == 0)
		return (1);
	out = 0;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		c = *str - '0';
		if (out > (LLONG_MAX - c) / 10)
			return (0);
		out = out * 10 + c;
		str++;
	}
	return (1);
}

static void	check_args_error(char **args)
{
	char	*exit_status;

	if (!args || !args[1])
	{
		if (args)
			free_array(args);
		close_all_fds();
		exit(EXIT_SUCCESS);
	}
	exit_status = args[1];
	if (!fits_in_long_long(exit_status))
		exit_with_error("exit", "numeric argument required", BUILTIN_MISUSE);
	if (args[2] != NULL)
		print_error_msg("exit", "too many arguments");
}

int	builtin_exit(char **args)
{
	int	exit_status;

	ft_putstr_fd("exit\n", STDOUT_FILENO);
	check_args_error(args);
	if (args[2] == NULL)
	{
		close_all_fds();
		exit_status = ft_atoll(args[1]);
		free_array(args);
		exit(exit_status);
	}
	return (EXIT_FAILURE);
}
