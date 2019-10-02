/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:00:37 by jdesmond          #+#    #+#             */
/*   Updated: 2018/12/08 16:56:21 by jdesmond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			index;
	unsigned char	c1;
	unsigned char	c2;

	index = 0;
	while (s1[index] && s2[index] && s1[index] == s2[index] && index + 1 < n)
		index++;
	if (n == 0)
		return (0);
	c1 = (unsigned char)s1[index];
	c2 = (unsigned char)s2[index];
	if (c1 < 0)
		c1 *= -1;
	if (c2 < 0)
		c2 *= -1;
	return ((int)(c1) - (int)(c2));
}
