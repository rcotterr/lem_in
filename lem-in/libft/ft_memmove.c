/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:22:10 by jdesmond          #+#    #+#             */
/*   Updated: 2018/12/03 17:50:17 by jdesmond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*d_ptr;
	char			*s_ptr;
	size_t			i;

	d_ptr = (char*)dst;
	s_ptr = (char*)src;
	i = 0;
	if (d_ptr > s_ptr)
	{
		while (i++ < len)
			d_ptr[len - i] = s_ptr[len - i];
	}
	else
	{
		while (len-- > 0)
		{
			*d_ptr = *s_ptr;
			d_ptr++;
			s_ptr++;
		}
	}
	return ((char*)dst);
}
