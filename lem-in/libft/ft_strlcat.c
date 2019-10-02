/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:18:31 by jdesmond          #+#    #+#             */
/*   Updated: 2018/12/08 17:20:04 by jdesmond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_length;
	size_t	s_length;
	size_t	i;

	d_length = ft_strlen(dst);
	s_length = ft_strlen(src);
	i = 0;
	while (size > d_length + i + 1)
	{
		dst[d_length + i] = src[i];
		i++;
	}
	dst[d_length + i] = '\0';
	if (d_length > size)
		return (size + s_length);
	return (d_length + s_length);
}
