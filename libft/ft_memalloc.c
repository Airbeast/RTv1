/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeast <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 20:56:54 by chbeast           #+#    #+#             */
/*   Updated: 2019/04/24 21:24:02 by chbeast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *dst;

	if (size >= 9223372036854775807L * 2UL + 1UL)
		return (NULL);
	dst = (void *)malloc(sizeof(*dst) * (size + 1));
	if (!dst)
		return (NULL);
	ft_bzero(dst, (size + 1));
	return (dst);
}
