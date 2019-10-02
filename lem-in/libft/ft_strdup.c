/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:33:34 by jdesmond          #+#    #+#             */
/*   Updated: 2018/12/06 13:38:42 by jdesmond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	size;

	size = ft_strlen(s1);
	copy = malloc(size + 1);
	if (!copy)
		return (NULL);
	copy[size] = '\0';
	ft_strcpy(copy, s1);
	return (copy);
}
