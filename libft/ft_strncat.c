/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeast <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 21:39:09 by chbeast           #+#    #+#             */
/*   Updated: 2019/04/19 19:03:27 by chbeast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(s1);
	j = 0;
	if (ft_strlen(s2) > n)
	{
		while (j < n)
		{
			s1[i] = s2[j];
			i++;
			j++;
		}
	}
	else
	{
		while (j < ft_strlen(s2))
		{
			s1[i] = s2[j];
			i++;
			j++;
		}
	}
	s1[i] = '\0';
	return (s1);
}
