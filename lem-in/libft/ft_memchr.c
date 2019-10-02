/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:25:28 by jdesmond          #+#    #+#             */
/*   Updated: 2018/12/04 17:11:57 by jdesmond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*s_ptr;

	s_ptr = (unsigned char*)s;
	index = 0;
	while (index < n)
	{
		if (s_ptr[index] == (unsigned char)(c))
			return (s_ptr + index);
		index++;
	}
	return (NULL);
}
