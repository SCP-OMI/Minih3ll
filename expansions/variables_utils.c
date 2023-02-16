#include "../minishell.h"

int	is_varname(char c)
{
	return (ft_isalnum(c) || c == '_' || c == '+');
}

int	is_valid_varname(char *name)
{
	if (!ft_isalpha(*name) && *name != '_')
		return (FALSE);
	while (*name)
	{
		if (!is_varname(*name))
			return (FALSE);
		name++;
	}
	return (TRUE);
}
