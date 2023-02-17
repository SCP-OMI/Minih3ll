/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OMI <mcharouh@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:03:36 by OMI               #+#    #+#             */
/*   Updated: 2023/02/17 05:06:11 by OMI              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	minienv_del_next_node(t_env **node)
{
	t_env	*temp;

	temp = (*node)->next;
	(*node)->next = ((*node)->next)->next;
	free(temp->key_pair);
	free(temp);
}

static void	remove_from_minienv(char *varname, t_env **minienv)
{
	t_env	*aux;
	int		name_len;

	aux = *minienv;
	name_len = ft_strlen(varname);
	if (!ft_strncmp(aux->key_pair, varname, name_len)
		&& (aux->key_pair[name_len] == '=' || aux->key_pair[name_len] == '\0'))
	{
		*minienv = aux->next;
		free(aux->key_pair);
		free(aux);
		return ;
	}
	while (aux && aux->next)
	{
		if (!ft_strncmp((aux->next)->key_pair, varname, name_len)
			&& ((aux->next)->key_pair[name_len] == '='
				|| (aux->next)->key_pair[name_len] == '\0'))
			return (minienv_del_next_node(&aux));
		aux = aux->next;
	}
}

int	unset(char **args, t_env **minienv)
{
	char	*varname;
	int		exit_status;

	args++;
	exit_status = EXIT_SUCCESS;
	if (!*args)
		return (0);
	while (*args)
	{
		varname = *args;
		if (!is_valid_varname(varname))
		{
			print_varname_error_msg("unset", varname);
			exit_status = EXIT_FAILURE;
		}
		else
			remove_from_minienv(varname, minienv);
		args++;
	}
	return (exit_status);
}
