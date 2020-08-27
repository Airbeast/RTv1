/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeast <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 23:10:43 by chbeast           #+#    #+#             */
/*   Updated: 2019/04/23 19:18:37 by chbeast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	count;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		count = 0;
		while (*haystack && *haystack != *needle)
			haystack++;
		while (*needle && *haystack == *needle)
		{
			needle++;
			haystack++;
			count++;
		}
		if (count == ft_strlen(needle - count))
			return ((char *)haystack - count);
		else if (*haystack)
		{
			needle -= count;
			haystack -= (count - 1);
		}
	}
	return (NULL);
}
