/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:07:34 by jdesmond          #+#    #+#             */
/*   Updated: 2018/12/05 17:59:42 by jdesmond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			size;
	char			*str;

	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	str = ft_strnew(size);
	if (!str)
		return (NULL);
	i = 0;
	while (size-- > 0)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}
