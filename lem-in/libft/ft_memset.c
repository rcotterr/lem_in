/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:42:46 by jdesmond          #+#    #+#             */
/*   Updated: 2018/11/22 18:46:07 by jdesmond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	byte;
	unsigned char	*b_ptr;

	byte = (unsigned char)c;
	b_ptr = (unsigned char*)b;
	while (len-- > 0)
		*(b_ptr++) = byte;
	return (b);
}
