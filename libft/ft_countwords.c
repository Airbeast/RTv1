/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeast <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 06:08:54 by chbeast           #+#    #+#             */
/*   Updated: 2019/09/26 06:17:56 by chbeast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countwords(char const *s, char c)
{
	int count;

	if (!s)
		return (0);
	count = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != c && *s != '\0')
		{
			while (*s != c && *s != '\0')
				s++;
			count++;
		}
		if (*s != '\0')
			s++;
	}
	return (count);
}
