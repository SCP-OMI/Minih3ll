/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OMI <mcharouh@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 19:19:58 by mtourham          #+#    #+#             */
/*   Updated: 2023/02/17 01:27:46 by OMI              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Finds the first occurance of c in string s
 *
 * @details If n is bigger than the size of s,
 * it will search past the end of the string
 * @param s String
 * @param c Char to be found
 * @param n
 * @return pointer to the location the char was found
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	int	i;

	i = 0;
	while (n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((unsigned char *)s + i);
		i++;
		n--;
	}
	return (0);
}
