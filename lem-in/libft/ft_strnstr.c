/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 12:45:02 by jdesmond          #+#    #+#             */
/*   Updated: 2018/12/08 17:11:52 by jdesmond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	while (haystack[i])
	{
		k = 0;
		while (haystack[i + k] == needle[k] && needle[k] && (i + k) < len)
			k++;
		if (!(needle[k]))
			return ((char*)(haystack + i));
		i++;
	}
	return (NULL);
}
