/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OMI <mcharouh@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 14:24:21 by mtourham          #+#    #+#             */
/*   Updated: 2023/02/17 01:27:19 by OMI              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Adds the element ’new’ at the beginning of the list.
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
	return ;
}
