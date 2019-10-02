/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 22:15:47 by jdesmond          #+#    #+#             */
/*   Updated: 2018/12/09 16:16:41 by jdesmond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	*free_lst(t_list **result)
{
	t_list		*to_free;

	if (!result)
		return (NULL);
	while (*result)
	{
		to_free = *result;
		(*result) = (*result)->next;
		free(to_free->content);
		free(to_free);
	}
	*result = NULL;
	return (NULL);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*elem;
	t_list		*prev_elem;
	t_list		*rmb_next;
	t_list		*result;

	if (!(elem = lst) || !f)
		return (NULL);
	prev_elem = NULL;
	result = NULL;
	while (elem)
	{
		rmb_next = elem->next;
		elem = f(elem);
		if (!(elem = ft_lstnew(elem->content, elem->content_size)))
			return (free_lst(&result));
		if (prev_elem)
			prev_elem->next = elem;
		else
			result = elem;
		prev_elem = elem;
		elem = rmb_next;
	}
	return (result);
}
