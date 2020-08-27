/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeast <chbeast@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 16:58:37 by vletterp          #+#    #+#             */
/*   Updated: 2020/07/22 18:30:04 by chbeast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *s, size_t n)
{
	char	*blank;

	if (!(blank = ft_strnew(n)))
		return (NULL);
	ft_strncpy(blank, s, n);
	return (blank);
}
