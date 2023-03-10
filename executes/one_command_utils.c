/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_command_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OMI <mcharouh@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:52:48 by OMI               #+#    #+#             */
/*   Updated: 2023/02/17 01:59:23 by OMI              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	save_original_fd_in(int original_fds[2])
{
	if (original_fds[IN] == NO_REDIRECT)
		original_fds[IN] = dup(STDIN_FILENO);
}

void	save_original_fd_out(int original_fds[2])
{
	if (original_fds[OUT] == NO_REDIRECT)
		original_fds[OUT] = dup(STDOUT_FILENO);
}

int	input_redirect(char *command, int original_fds[2])
{
	save_original_fd_in(original_fds);
	if (redirect_input(command) == FAILED)
	{
		redirect_fd(original_fds[IN], STDIN_FILENO);
		return (FAILED);
	}
	return (SUCCESS);
}

int	output_redirect(char *command, int original_fds[2])
{
	save_original_fd_out(original_fds);
	if (redirect_output(command) == FAILED)
	{
		redirect_fd(original_fds[OUT], STDOUT_FILENO);
		return (FAILED);
	}
	return (SUCCESS);
}
