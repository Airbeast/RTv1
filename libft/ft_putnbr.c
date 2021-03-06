/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeast <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 18:46:44 by chbeast           #+#    #+#             */
/*   Updated: 2019/04/27 19:34:34 by chbeast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

void		ft_putnbr(int n)
{
	int		grade;
	int		nb;
	char	c;

	if (n == -2147483648LL)
		write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n *= -1;
		}
		grade = ft_grade(n);
		while (grade)
		{
			nb = n / grade;
			c = (char)nb + 48;
			write(1, &c, 1);
			n %= grade;
			grade /= 10;
		}
	}
}
