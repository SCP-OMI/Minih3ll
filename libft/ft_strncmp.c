/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OMI <mcharouh@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 15:55:42 by mtourham          #+#    #+#             */
/*   Updated: 2023/02/16 21:38:51 by OMI              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	if (!n)
	{
		return (0);
	}
	i = 0;
	while (*s1 && *s2 && (*s1 == *s2) && (i + 1 < n))
	{
		++s1;
		++s2;
		++i;
	}
	return (((unsigned char)*s1) - ((unsigned char)*s2));
}
