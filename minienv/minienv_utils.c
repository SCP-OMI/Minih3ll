/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minienv_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OMI <mcharouh@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:55:15 by OMI               #+#    #+#             */
/*   Updated: 2023/02/17 03:29:36 by OMI              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*minienv_value(char *name, t_env *minienv)
{
	t_env	*aux;

	aux = minienv_node(name, minienv);
	if (!aux)
		return (NULL);
	return (value_only(aux->key_pair));
}

t_env	*minienv_node(char *name, t_env *minienv)
{
	t_env	*aux;
	int		size;

	aux = minienv;
	size = ft_strlen(name);
	while (aux)
	{
		if (
			ft_strncmp(name, aux->key_pair, size) == 0
			&& (aux->key_pair[size] == '=' || aux->key_pair[size] == '\0')
		)
			return (aux);
		aux = aux->next;
	}
	return (NULL);
}

void	append_values(t_env **aux, char *value, char *name)
{
	char	*old_keypair;

	old_keypair = (*aux)->key_pair;
	(*aux)->key_pair = create_keypair(name, value);
	free(old_keypair);
}

void	minienv_var_update(char *name, char *value, t_env *minienv)
{
	t_env	*aux;
	char	*new_keypair;

	aux = minienv_node(name, minienv);
	if (aux)
		append_values(&aux, value, name);
	else
	{
		new_keypair = create_keypair(name, value);
		list_append(new_keypair, &minienv);
		free(new_keypair);
		return ;
	}
}

void	minienv_update(char *name, char *value, t_env *minienv)
{
	t_env	*aux;
	char	*new_keypair;
	char	*aux_value;
	char	*joined_str;

	aux = minienv_node(name, minienv);
	if (!aux)
	{
		new_keypair = create_keypair(name, value);
		list_append(new_keypair, &minienv);
		free(new_keypair);
		return ;
	}
	else if (value && *(value - 2) != '+')
		aux->key_pair = create_keypair(name, value);
	else
	{
		aux_value = value_only(aux->key_pair);
		if (!aux_value)
			aux_value = "";
		joined_str = ft_strjoin(aux_value, value);
		append_values(&aux, joined_str, name);
		free(joined_str);
	}
}
