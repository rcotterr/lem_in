/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <rcotter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 19:26:30 by jdesmond          #+#    #+#             */
/*   Updated: 2019/08/06 15:22:27 by rcotter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	mov_buf(char *buf, size_t buf_i)
{
	size_t	i;

	i = 0;
	while (buf_i < BUFF_SIZE)
	{
		buf[i] = buf[buf_i];
		i++;
		buf_i++;
	}
	while (i < BUFF_SIZE)
	{
		buf[i] = '\0';
		i++;
	}
}

static int	add_from_buf(char **line, char *buf)
{
	char	*to_add;
	char	*to_free;
	size_t	buf_i;

	buf_i = 0;
	while (buf[buf_i] != '\n' && buf_i < BUFF_SIZE)
		buf_i++;
	to_add = ft_strsub(buf, 0, buf_i);
	if (!to_add)
		return (-1);
	to_free = *line;
	*line = ft_strjoin(*line, to_add);
	free(to_free);
	free(to_add);
	if (!line)
		return (-1);
	if (buf[buf_i] == '\n')
	{
		mov_buf(buf, buf_i + 1);
		return (1);
	}
	mov_buf(buf, buf_i + 1);
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char buf[BUFF_SIZE];
	int			ret_value;
	int			add_result;
	int			prev;

	if (!line)
		return (-1);
	add_result = 1;
	ret_value = 0;
	if (!(*line = ft_strnew(1)))
		return (-1);
	while (ret_value != -1 && (!(add_result == 0 && ret_value == 0)))
	{
		prev = ret_value;
		if (buf[0])
			prev = 1;
		if ((add_result = add_from_buf(line, buf)) != 0)
			return (add_result);
		ret_value = read(fd, buf, BUFF_SIZE);
	}
	if (ret_value == -1)
		return (-1);
	if (prev >= 1)
		return (1);
	return (0);
}
