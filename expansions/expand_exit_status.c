/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_exit_status.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OMI <mcharouh@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:53:35 by OMI               #+#    #+#             */
/*   Updated: 2023/02/16 21:14:34 by OMI              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*find_exit_status_position(char *input)
{
	while (input && *input)
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
				if (*input == '$' && input[1] == '?')
					return (input);
				input++;
			}
		}
		if (*input == '$' && input[1] == '?')
			return (input);
		input++;
	}
	return (NULL);
}

static void	update_input(char **input, char *exit_code, char *second_part)
{
	char	*first_part;
	char	*updated_input;

	first_part = ft_strjoin(*input, exit_code);
	updated_input = ft_strjoin(first_part, second_part);
	free(*input);
	free(first_part);
	*input = updated_input;
}

void	expand_exit_status(char **input, int exit_status)
{
	char	*exit_status_position;
	char	*exit_status_str;

	exit_status_position = find_exit_status_position(*input);
	if (exit_status_position)
	{
		*exit_status_position = '\0';
		exit_status_str = ft_itoa(exit_status);
		update_input(input, exit_status_str, (exit_status_position + 2));
		free(exit_status_str);
		expand_exit_status(input, exit_status);
	}
}

void	handle_expansions(char **input, t_env *minienv, int exit_status)
{
	expand_exit_status(input, exit_status);
	expand_variables(input, minienv);
}
