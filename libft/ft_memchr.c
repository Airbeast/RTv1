/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeast <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:30:17 by chbeast           #+#    #+#             */
/*   Updated: 2019/04/27 23:38:57 by chbeast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	if (s == NULL && n == 0)
		return (NULL);
	while (0 < (n - 1) && *(unsigned char *)s != (unsigned char)c)
	{
		n--;
		s++;
	}
	if (*(unsigned char *)s == (unsigned char)c)
		return ((unsigned char *)s);
	else
		return (NULL);
}
