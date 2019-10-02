/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:14:36 by jdesmond          #+#    #+#             */
/*   Updated: 2018/12/06 12:36:05 by jdesmond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_len(int n)
{
	size_t		len;

	len = 1;
	if (n < 0)
		len++;
	while (n / 10 != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	size_t		len;
	char		*result;
	int			sign;

	len = count_len(n);
	result = (char*)malloc((len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	result[0] = '0';
	sign = 1;
	if (n < 0)
	{
		result[0] = '-';
		sign = -1;
	}
	while (n != 0)
	{
		result[--len] = (n % 10) * sign + '0';
		n = n / 10;
	}
	return (result);
}
