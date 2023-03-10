/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OMI <mcharouh@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 20:13:04 by mtourham          #+#    #+#             */
/*   Updated: 2023/02/16 21:38:54 by OMI              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locate a substring in a string
 * @details locates the first occurrence of the null-terminated string needle
 * in the string haystack, where not more than len characters are searched
 * @param haystack
 * @param needle
 * @param len
 * @return char*
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len)
	{
		if (*haystack == *needle)
		{
			i = 0;
			while (needle[i] && (needle[i] == haystack[i]) && (i < len))
				i++;
			if (!needle[i])
				return (((char *)haystack));
		}
		haystack++;
		len--;
	}
	return (0);
}
