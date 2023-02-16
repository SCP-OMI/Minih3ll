/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtourham<mtourham@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 15:41:43 by mtourham        #+#    #+#             */
/*   Updated: 2021/08/13 20:17:04 by mtourham       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Similar to memcpy, but avoids overlapping
void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	if (src < dst)
	{
		i = n - 1;
		while (n)
		{
			*((char *)dst + i) = *((char *)src + i);
			i--;
			n--;
		}
	}
	else
	{
		i = 0;
		while (n)
		{
			*((char *)dst + i) = *((char *)src + i);
			i++;
			n--;
		}
	}
	return (dst);
}
