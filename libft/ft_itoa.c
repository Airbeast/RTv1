/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeast <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 04:36:48 by chbeast           #+#    #+#             */
/*   Updated: 2019/04/27 18:57:59 by chbeast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(int n)
{
	int i;

	if (n <= 0)
		i = 1;
	else
		i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	ft_grade(int n)
{
	int grade;

	grade = 1;
	while (n > 9)
	{
		grade *= 10;
		n /= 10;
	}
	return (grade);
}

char		*ft_itoa(int n)
{
	char	*dst;
	int		i;
	int		grade;
	int		nb;

	if (!(dst = ft_strnew(count(n))))
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = 0;
	if (n < 0)
	{
		dst[i++] = '-';
		n *= -1;
	}
	grade = ft_grade(n);
	while (grade)
	{
		nb = n / grade;
		dst[i++] = ((char)nb + 48);
		n %= grade;
		grade /= 10;
	}
	dst[i] = '\0';
	return (dst);
}
