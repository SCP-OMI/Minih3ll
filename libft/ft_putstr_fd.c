/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OMI <mcharouh@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 22:30:03 by mtourham          #+#    #+#             */
/*   Updated: 2023/02/16 21:37:31 by OMI              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Outputs the string ’s’ to the given file descriptor 'fd'.
void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, sizeof(*s) * ft_strlen(s));
}
