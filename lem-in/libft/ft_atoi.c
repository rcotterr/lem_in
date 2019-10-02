/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:18:24 by jdesmond          #+#    #+#             */
/*   Updated: 2018/12/09 16:23:27 by jdesmond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t		i;
	int			znak;
	long int	result;

	result = 0;
	i = 0;
	znak = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ' || str[i] == '0')
		i++;
	if (str[i] == '-')
	{
		i++;
		znak = -1;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0') * znak;
		i++;
	}
	return ((int)result);
}
