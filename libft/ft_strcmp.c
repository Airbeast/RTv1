/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeast <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:09:57 by chbeast           #+#    #+#             */
/*   Updated: 2019/04/24 14:37:35 by chbeast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;
	int diff;

	i = 0;
	while (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
	{
		if (s1[i] == '\0')
			return (0);
		else
			i++;
	}
	diff = (int)(((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
	return (diff);
}
