/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeast <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:24:44 by chbeast           #+#    #+#             */
/*   Updated: 2019/09/23 23:49:11 by chbeast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*s1;
	const unsigned char	*s2;
	size_t				i;

	s1 = dst;
	s2 = src;
	i = 0;
	while (i < n)
	{
		s1[i] = s2[i];
		if (s2[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
