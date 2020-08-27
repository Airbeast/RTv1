/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeast <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 22:45:36 by chbeast           #+#    #+#             */
/*   Updated: 2019/04/19 23:03:49 by chbeast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int n;

	n = ft_strlen(s);
	if (c == '\0')
		return (&(((char *)s)[n]));
	else
	{
		while (s[n] != c)
		{
			if (n < 0)
				return (NULL);
			n--;
		}
	}
	return ((char *)&s[n]);
}
