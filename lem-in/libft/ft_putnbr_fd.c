/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 20:15:36 by jdesmond          #+#    #+#             */
/*   Updated: 2018/12/05 20:38:31 by jdesmond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	to_write;
	int		sign;

	sign = 1;
	if (n < 0 && sign == 1)
	{
		write(fd, "-", 1);
		sign = -1;
	}
	to_write = (n % 10) * sign + '0';
	n = n / 10;
	if (n < 0)
		n = n * -1;
	if (n != 0)
		ft_putnbr_fd(n, fd);
	write(fd, &to_write, 1);
}
