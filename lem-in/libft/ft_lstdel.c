/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 21:58:08 by jdesmond          #+#    #+#             */
/*   Updated: 2018/12/06 12:30:53 by jdesmond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*prev_elem;
	t_list	*elem;

	if (!alst || !del)
		return ;
	prev_elem = *alst;
	*alst = NULL;
	elem = prev_elem->next;
	while (prev_elem)
	{
		del(prev_elem->content, prev_elem->content_size);
		free(prev_elem);
		prev_elem = elem;
		if (elem)
			elem = elem->next;
	}
}
