/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:39:09 by jdesmond          #+#    #+#             */
/*   Updated: 2018/12/03 17:47:36 by jdesmond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	index;

	index = 0;
	dst[index] = src[index];
	index++;
	while (src[index - 1])
	{
		dst[index] = src[index];
		index++;
	}
	return (dst);
}
