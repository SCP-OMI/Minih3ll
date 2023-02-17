/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OMI <mcharouh@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:03:27 by OMI               #+#    #+#             */
/*   Updated: 2023/02/17 03:48:01 by OMI              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	declare_env(t_env *minienv)
{
	t_env	*aux;
	char	*s;

	aux = minienv;
	while (aux)
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		s = name_only(aux->key_pair);
		ft_putstr_fd(s, STDOUT_FILENO);
		free(s);
		if (ft_strchr(aux->key_pair, '='))
		{
			ft_putstr_fd("=", STDOUT_FILENO);
			ft_putstr_fd("\"", STDOUT_FILENO);
			ft_putstr_fd(value_only(aux->key_pair), STDOUT_FILENO);
			ft_putstr_fd("\"", STDOUT_FILENO);
		}
		ft_putstr_fd("\n", STDOUT_FILENO);
		aux = aux->next;
	}
	return (0);
}

int	check_keypair(char *name)
{
	int	i;

	i = 0;
	while (name[i])
	{
		if (name[i + 1] && (name[i] == '+' && name[i + 1] != '='))
			return (FALSE);
		if (name[ft_strlen(name) - 1] == '+')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	check_dup(char *key_pair, t_env *minienv)
{
	t_env	*aux;

	aux = minienv;
	while (aux)
	{
		if (ft_strncmp(key_pair, aux->key_pair, ft_strlen(key_pair)) == 0)
			return (0);
		aux = aux->next;
	}
	return (1);
}

int	builtin_export(char **args, t_env **minienv)
{
	char	*key_pair;
	char	*varname;
	int		exit_status;

	args++;
	exit_status = EXIT_SUCCESS;
	if (!*args)
		return (declare_env(*minienv));
	while (*args)
	{
		key_pair = *args;
		varname = name_only(key_pair);
		if (!is_valid_varname(varname) || !check_keypair(key_pair))
		{
			print_varname_error_msg("export", key_pair);
			exit_status = EXIT_FAILURE;
		}
		else if (check_dup(key_pair, *minienv))
			minienv_update(varname, value_only(key_pair), *minienv);
		free(varname);
		args++;
	}
	return (exit_status);
}
