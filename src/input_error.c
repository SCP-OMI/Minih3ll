/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OMI <mcharouh@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:56:41 by OMI               #+#    #+#             */
/*   Updated: 2023/02/16 20:56:42 by OMI              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	has_input_error(char *input, int *exit_status, t_env *minienv)
{
	int	result;

	result = FALSE;
	if (is_empty(input))
		result = TRUE;
	else if (has_unclosed_quotes(input))
		result = TRUE;
	else if (is_invalid_syntax(input))
	{
		*exit_status = 2;
		result = TRUE;
	}
	else if (handle_heredoc(input, exit_status, minienv) == FAILED)
		result = TRUE;
	if (result == TRUE)
		free(input);
	return (result);
}
