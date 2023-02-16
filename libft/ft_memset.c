/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtourham<mtourham@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 15:41:43 by mtourham        #+#    #+#             */
/*   Updated: 2021/07/30 19:37:42 by mtourham       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *p, int value, size_t len)
{
	unsigned char	*str;

	str = p;
	while (len)
	{
		*str = (unsigned char)value;
		str++;
		len--;
	}
	return (p);
}
