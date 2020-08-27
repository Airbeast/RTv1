/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeast <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 21:16:43 by chbeast           #+#    #+#             */
/*   Updated: 2019/04/24 21:18:54 by chbeast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *dst;

	dst = (char *)malloc(sizeof(char) * (size + 1));
	if (!dst)
		return (NULL);
	ft_bzero(dst, (size + 1));
	return (dst);
}
