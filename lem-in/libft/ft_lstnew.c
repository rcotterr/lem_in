/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:22:04 by jdesmond          #+#    #+#             */
/*   Updated: 2018/12/09 15:55:41 by jdesmond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_list;

	new_list = (t_list*)malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	if (content)
	{
		if (!(new_list->content = malloc(content_size)))
		{
			free(new_list->content);
			return (NULL);
		}
		ft_memcpy(new_list->content, content, content_size);
		new_list->content_size = content_size;
	}
	else
	{
		new_list->content_size = 0;
		new_list->content = NULL;
	}
	new_list->next = NULL;
	return (new_list);
}
