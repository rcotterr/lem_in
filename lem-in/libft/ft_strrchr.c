/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:03:30 by jdesmond          #+#    #+#             */
/*   Updated: 2018/12/04 17:18:01 by jdesmond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*found;
	size_t	index;

	found = NULL;
	index = 0;
	while (s[index])
	{
		if (s[index] == c)
			found = (char*)(s + index);
		index++;
	}
	if (c == '\0')
		return ((char*)(s + index));
	return (found);
}
