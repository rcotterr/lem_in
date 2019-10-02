/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 19:22:55 by jdesmond          #+#    #+#             */
/*   Updated: 2018/12/03 17:42:16 by jdesmond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	index;

	index = 0;
	while (src[index] && index < len)
	{
		dst[index] = src[index];
		index++;
	}
	if (index < len)
	{
		while (index < len)
		{
			dst[index] = '\0';
			index++;
		}
	}
	return (dst);
}
