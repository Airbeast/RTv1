/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeast <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 00:03:48 by chbeast           #+#    #+#             */
/*   Updated: 2019/04/27 20:22:37 by chbeast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char const *s)
{
	int i;
	int count;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		i++;
		count++;
	}
	if (!s[i])
		return (count);
	i = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		i--;
		count++;
	}
	return (count);
}

char		*ft_strtrim(char const *s)
{
	char	*dst;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	k = ft_strlen(s) - 1;
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s) - count(s) + 1));
	if (!dst || !s)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[k] == ' ' || s[k] == '\n' || s[k] == '\t')
		k--;
	while (i <= k)
	{
		dst[j] = s[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (dst);
}
