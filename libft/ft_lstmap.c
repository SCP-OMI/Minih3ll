/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OMI <mcharouh@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 14:49:05 by mtourham          #+#    #+#             */
/*   Updated: 2023/02/17 01:27:34 by OMI              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_next_links(t_list *lst, void (*del)(void *));

// Iterates the list ’lst’ and applies the function
// ’f’ to the content of each element. Creates a new
// list resulting of the successive applications of
// the function ’f’. The ’del’ function is used to
// delete the content of an element if needed.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_link;

	new_lst = NULL;
	while (lst)
	{
		new_link = ft_lstnew(f(lst->content));
		if (!new_link)
		{
			free_next_links(lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_link);
		lst = lst->next;
	}
	return (new_lst);
}

static void	free_next_links(t_list *lst, void (*del)(void *))
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst->next;
		ft_lstclear(&lst, del);
		lst = tmp;
	}
	return ;
}
