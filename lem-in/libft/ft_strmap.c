/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:42:20 by jdesmond          #+#    #+#             */
/*   Updated: 2018/12/09 15:51:10 by jdesmond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	size;
	char	*str;

	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	str = ft_strnew(size);
	if (!str)
		return (NULL);
	while (size-- > 0)
		str[size] = f(s[size]);
	return (str);
}
