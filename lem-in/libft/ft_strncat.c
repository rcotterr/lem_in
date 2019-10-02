/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:36:07 by jdesmond          #+#    #+#             */
/*   Updated: 2018/12/06 14:28:48 by jdesmond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	len1;
	size_t	index;

	len1 = ft_strlen(s1);
	index = 0;
	while (s2[index] && n-- > 0)
	{
		s1[len1 + index] = s2[index];
		index++;
	}
	s1[len1 + index] = '\0';
	return (s1);
}
