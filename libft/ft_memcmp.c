/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeast <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:18:40 by chbeast           #+#    #+#             */
/*   Updated: 2019/04/18 17:41:46 by chbeast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int diff;

	if (n == 0)
		return (0);
	while (*(unsigned char *)s1 == *(unsigned char *)s2 && (n - 1) > 0)
	{
		s1++;
		s2++;
		n--;
	}
	diff = (int)(*(unsigned char *)s1 - *(unsigned char *)s2);
	return (diff);
}
