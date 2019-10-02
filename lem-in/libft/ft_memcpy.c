/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:22:26 by jdesmond          #+#    #+#             */
/*   Updated: 2018/11/22 18:45:34 by jdesmond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d_ptr;
	unsigned char	*s_ptr;

	d_ptr = (unsigned char*)dst;
	s_ptr = (unsigned char*)src;
	while (n-- > 0)
	{
		*d_ptr = *s_ptr;
		d_ptr++;
		s_ptr++;
	}
	return (dst);
}
