/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minienv_str_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OMI <mcharouh@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:55:11 by OMI               #+#    #+#             */
/*   Updated: 2023/02/17 00:34:54 by OMI              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*name_only(char *key_pair)
{
	int	i;

	i = 0;
	while ((key_pair[i] != '=' && key_pair[i] != '+') && key_pair[i])
		i++;
	return (ft_substr(key_pair, 0, i));
}

char	*value_only(char *key_pair)
{
	int	i;

	i = 0;
	while (key_pair[i] != '=' && key_pair[i])
		i++;
	if (!key_pair[i])
		return (NULL);
	return (&key_pair[i + 1]);
}

char	*create_keypair(char *name, char *value)
{
	char	*key_pair;
	int		key_pair_size;
	int		i;

	key_pair_size = ft_strlen(name);
	if (value)
		key_pair_size += ft_strlen(value);
	key_pair = malloc((key_pair_size + 2) * sizeof(char));
	i = 0;
	while (name && *name)
		key_pair[i++] = *name++;
	if (value)
		key_pair[i++] = '=';
	while (value && *value)
		key_pair[i++] = *value++;
	key_pair[i] = '\0';
	return (key_pair);
}

char	**minienv_to_envp(t_env *minienv)
{
	char	**envp;
	t_env	*aux;
	int		i;

	envp = malloc(sizeof(char *) * (minienv_size(minienv) + 1));
	aux = minienv;
	i = 0;
	while (aux)
	{
		envp[i] = ft_strdup(aux->key_pair);
		i++;
		aux = aux->next;
	}
	envp[i] = NULL;
	return (envp);
}
