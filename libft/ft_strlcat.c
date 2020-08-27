/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeast <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 18:58:55 by chbeast           #+#    #+#             */
/*   Updated: 2019/04/22 20:07:54 by chbeast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;
	size_t	j;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = 0;
	j = ft_strlen(dst);
	if (size <= dstlen)
		return (srclen + size);
	else
	{
		while (src[i] != '\0' && i < (size - dstlen - 1))
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		dst[j] = '\0';
		return (dstlen + srclen);
	}
}
