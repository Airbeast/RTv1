/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbeast <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 04:35:39 by chbeast           #+#    #+#             */
/*   Updated: 2019/09/26 04:51:54 by chbeast          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *new;
	t_list *tmp;

	new = *alst;
	while (new)
	{
		tmp = new;
		ft_lstdelone(&new, del);
		new = tmp->next;
	}
	*alst = NULL;
}
