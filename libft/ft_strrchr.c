/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OMI <mcharouh@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 14:01:45 by mtourham          #+#    #+#             */
/*   Updated: 2023/02/16 21:36:46 by OMI              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*location;

	i = 0;
	location = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			location = ((char *)s + i);
		i++;
	}
	if (s[i] == c)
		return ((char *)s + i);
	return (location);
}
