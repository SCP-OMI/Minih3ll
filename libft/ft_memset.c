/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OMI <mcharouh@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 15:41:43 by mtourham          #+#    #+#             */
/*   Updated: 2023/02/17 01:27:59 by OMI              ###   ########.fr       */
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
