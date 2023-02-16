#include "../minishell.h"

int	basic_check(char *s)
{
	if(ft_strncmp(s,"echo",4) == 0)
		return 1;
	return 0;
}

int checknew(char *args)
{
    int i = 1;

    if (args[0] == '-' && args[i])
    {
        while(args[i])
        {
            if(args[i] != 'n')
            {
                return 1;
            }
            i++;
        }
		return 0;
    }
    return 1;
}

int	echo(char **args)
{
	int	i;
	int	new_line;

	new_line = 1;
	i = 1;
	if (basic_check(args[0]) && args[1] == 0)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (checknew(args[i]) == 0)
	{
		new_line = 0;
		i++;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], STDOUT_FILENO);
		if (args[i + 1])
			ft_putstr_fd(" ", STDOUT_FILENO);
		i++;
	}
	if (new_line)
		ft_putstr_fd("\n", STDOUT_FILENO);
	return (0);
}