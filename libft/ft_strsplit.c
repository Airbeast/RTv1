/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeast <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 00:41:09 by chbeast           #+#    #+#             */
/*   Updated: 2019/11/26 21:12:31 by chbeast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkalloc(char **dst, int n, int wordsize)
{
	if (!(dst[n] = (char *)malloc(sizeof(char) * (wordsize + 1))))
	{
		while (--n >= 0)
			free(dst[n]);
		free(dst);
		return (0);
	}
	return (1);
}

static char	**allocation(char const *s, char c)
{
	int		n;
	int		wordsize;
	char	**dst;
	int		words;

	n = 0;
	words = ft_countwords(s, c);
	if (!(dst = (char **)malloc(sizeof(char *) * (words + 1))) || !s)
		return (NULL);
	while (n < words)
	{
		wordsize = 0;
		while (*s == c)
			s++;
		while (*s != c && *s != '\0')
		{
			s++;
			wordsize++;
		}
		if (!checkalloc(dst, n, wordsize))
			return (NULL);
		s++;
		n++;
	}
	return (dst);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**dst;
	int		n;
	int		wordsize;
	int		words;

	n = 0;
	words = ft_countwords(s, c);
	dst = allocation(s, c);
	if (!dst || !s)
		return (NULL);
	while (n < words)
	{
		wordsize = 0;
		while (*s == c)
			s++;
		while (*s != c && *s != '\0')
		{
			dst[n][wordsize++] = *s;
			s++;
		}
		dst[n++][wordsize] = '\0';
		s++;
	}
	dst[n] = NULL;
	return (dst);
}
