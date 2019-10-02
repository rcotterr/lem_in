/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:57:31 by jdesmond          #+#    #+#             */
/*   Updated: 2018/12/04 14:43:36 by jdesmond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d_ptr;
	unsigned char	*s_ptr;

	d_ptr = (unsigned char*)dst;
	s_ptr = (unsigned char*)src;
	while (n-- > 0)
	{
		*d_ptr = *s_ptr;
		d_ptr++;
		if (*s_ptr == (unsigned char)c)
			return (d_ptr);
		s_ptr++;
	}
	return (NULL);
}
