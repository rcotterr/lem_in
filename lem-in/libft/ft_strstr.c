/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:18:32 by jdesmond          #+#    #+#             */
/*   Updated: 2018/12/05 13:56:16 by jdesmond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	h_len;
	char	*result;

	h_len = ft_strlen(haystack);
	if (*needle == '\0')
		return ((char*)haystack);
	result = ft_strnstr(haystack, needle, h_len);
	return (result);
}
