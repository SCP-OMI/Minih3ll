/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OMI <mcharouh@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 00:56:38 by mtourham          #+#    #+#             */
/*   Updated: 2023/02/16 21:38:08 by OMI              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	len;

	len = ft_strlen((char *)s1) + 1;
	dup = malloc(sizeof(*s1) * len);
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s1, len);
	return (dup);
}
