/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vletterp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:28:25 by vletterp          #+#    #+#             */
/*   Updated: 2020/07/22 15:28:29 by vletterp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_base_string(char letter, int base)
{
	char	*base_string;
	int		i;
	int		isset;

	i = -1;
	isset = 0;
	base_string = "0123456789abcdef";
	letter = ft_tolower(letter);
	while (++i < base)
	{
		if (base_string[i] == letter)
			isset = 1;
	}
	if (isset)
		return (1);
	return (0);
}
