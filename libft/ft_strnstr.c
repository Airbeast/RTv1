/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeast <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 19:08:26 by chbeast           #+#    #+#             */
/*   Updated: 2019/04/24 17:56:35 by chbeast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && len)
	{
		while (*haystack && *haystack != *needle && len)
		{
			len--;
			haystack++;
		}
		if (!ft_strncmp(haystack, needle, ft_strlen(needle))
					&& len >= ft_strlen(needle))
			return ((char *)haystack);
		else if (*haystack && len)
			haystack++;
	}
	return (NULL);
}
