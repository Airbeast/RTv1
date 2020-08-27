/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeast <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:36:23 by chbeast           #+#    #+#             */
/*   Updated: 2019/04/24 14:48:16 by chbeast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int i;
	int diff;

	i = 0;
	if (n == 0)
		return (0);
	while (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i] && (n - 1))
	{
		if (s1[i] == '\0')
			return (0);
		else
		{
			i++;
			n--;
		}
	}
	diff = (int)(((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
	return (diff);
}
