/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OMI <mcharouh@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:12:32 by mtourham          #+#    #+#             */
/*   Updated: 2023/02/16 21:38:41 by OMI              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// copies up to (dstsize - 1) characters from the string src to dst,
// NUL-terminating the result if dstsize is not 0
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_size;

	src_size = 0;
	while (src[src_size] != '\0')
	{
		src_size++;
	}
	if (size == 0)
	{
		return (src_size);
	}
	i = 0;
	while ((i < size - 1) && (i < src_size))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_size);
}
