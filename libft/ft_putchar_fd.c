/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OMI <mcharouh@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:21:18 by mtourham          #+#    #+#             */
/*   Updated: 2023/02/16 21:37:42 by OMI              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Outputs the character ’c’ to the given file descriptor 'fd'.
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(c));
}
