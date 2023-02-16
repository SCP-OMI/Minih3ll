/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OMI <mcharouh@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 14:01:45 by mtourham          #+#    #+#             */
/*   Updated: 2023/02/16 21:37:01 by OMI              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locate character in string
 * @details
 * If the character searched for is \0,
 * it will return the location of the end of the string
 * Locates the first occurance of a character `c` on a given string 's'
 * @see strrchr
 * @param s String ( expects a null-terminated )
 * @param c Char to find on string
 * @return String starting from char c
 */
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == c)
		return ((char *)s + i);
	return (0);
}
