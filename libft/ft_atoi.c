/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeast <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:52:49 by chbeast           #+#    #+#             */
/*   Updated: 2019/11/29 21:32:49 by chbeast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	b;
	int		negative;

	b = 0;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	if (*str == '\0')
		return (0);
	if (*str == '-')
		negative = 1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str > 47 && *str < 58 && *str != '\0')
	{
		b *= 10;
		b += (size_t)*str - 48;
		str++;
	}
	if (b > 9223372036854775807U && negative == 1)
		return (0);
	if (b > 9223372036854775808U)
		return (-1);
	if (negative == 1)
		return (-b);
	return (b);
}
