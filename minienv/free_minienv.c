/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_minienv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OMI <mcharouh@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:55:06 by OMI               #+#    #+#             */
/*   Updated: 2023/02/17 01:53:37 by OMI              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_minienv(t_env **minienv)
{
	t_env	*aux;
	t_env	*next;

	aux = *minienv;
	while (aux)
	{
		free(aux->key_pair);
		next = aux->next;
		free(aux);
		aux = next;
	}
	minienv = NULL;
}
