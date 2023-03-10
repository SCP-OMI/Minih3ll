/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OMI <mcharouh@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:53:41 by OMI               #+#    #+#             */
/*   Updated: 2023/02/17 03:57:55 by OMI              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_varname(char c)
{
	return (ft_isalnum(c) || c == '_' || c == '+');
}

int	is_valid_varname(char *name)
{
	int	i;

	i = 0;
	if (!ft_isalpha(*name) && *name != '_')
		return (FALSE);
	while (name[i])
	{
		if (!is_varname(name[i]))
			return (FALSE);
		if (name[i] == '+' && name[i + 1] != '=')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static char	*find_var_position(char *input)
{
	while (*input)
	{
		if (*input == '\'')
		{
			input++;
			while (*input && *input != '\'')
				input++;
		}
		if (*input == '\"')
		{
			input++;
			while (*input && *input != '\"')
			{
				if (*input == '$' && is_varname(input[1]))
					return (input);
				input++;
			}
		}
		if (*input == '$' && is_varname(input[1]))
			return (input);
		input++;
	}
	return (NULL);
}

static void	update_input(char **input, char *var_value, char *second_part)
{
	char	*first_part;
	char	*updated_input;

	if (!*input[0] && !var_value)
		first_part = ft_strdup("");
	else if (!*input[0] && var_value)
		first_part = ft_strdup(var_value);
	else if (!var_value)
		first_part = ft_strdup(*input);
	else
		first_part = ft_strjoin(*input, var_value);
	updated_input = ft_strjoin(first_part, second_part);
	free(first_part);
	free(*input);
	*input = updated_input;
}

void	expand_variables(char **input, t_env *minienv)
{
	char	*var_position;
	char	*var_name;
	char	*var_value;
	int		name_size;

	var_position = find_var_position(*input);
	if (var_position)
	{
		name_size = 0;
		while (is_varname(var_position[name_size + 1]))
			name_size++;
		var_name = ft_substr(var_position, 1, name_size);
		*var_position = '\0';
		var_value = minienv_value(var_name, minienv);
		update_input(input, var_value, (var_position + 1 + name_size));
		free(var_name);
		expand_variables(input, minienv);
	}
}
