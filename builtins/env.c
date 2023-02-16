/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OMI <mcharouh@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:03:16 by OMI               #+#    #+#             */
/*   Updated: 2023/02/16 21:03:17 by OMI              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	env(t_env *minienv)
{
	t_env	*aux;

	aux = minienv;
	while (aux)
	{
		if (ft_strchr(aux->key_pair, '='))
		{
			ft_putstr_fd(aux->key_pair, STDOUT_FILENO);
			ft_putstr_fd("\n", STDOUT_FILENO);
		}
		aux = aux->next;
	}
	return (0);
}
