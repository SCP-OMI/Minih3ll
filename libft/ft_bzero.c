/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtourham<mtourham@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 15:41:43 by mtourham        #+#    #+#             */
/*   Updated: 2021/07/30 19:20:28 by mtourham       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Adds char 0 (\\n) to a string
 *
 * @param p Pointer to the string
 * @param n Amount of zeros to add
 */
void	ft_bzero(void *p, size_t n)
{
	ft_memset(p, 0, n);
}
