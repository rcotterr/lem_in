/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 20:42:26 by jdesmond          #+#    #+#             */
/*   Updated: 2018/12/09 16:02:26 by jdesmond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			words++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (words);
}

static void		*free_result(char ***result, size_t words)
{
	while (words != 0)
	{
		words--;
		free(*(result)[words]);
		(*(result)[words]) = NULL;
	}
	free(*result);
	*result = NULL;
	return (NULL);
}

static char		**malloc_words(char const *s, char c)
{
	char		**result;
	size_t		words;
	size_t		i;
	size_t		len;

	if (!(result = (char**)malloc((count_words(s, c) + 1) * sizeof(char*))))
		return (NULL);
	words = 0;
	i = 0;
	while (s[i])
	{
		len = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i + len] && s[i + len] != c)
			len++;
		i += len;
		if (!(result[words] = (char*)malloc(len + 1)))
			return (free_result(&result, words));
		result[words][len] = '\0';
		if (i != 0 && s[i - 1] != c)
			words++;
	}
	result[words] = NULL;
	return (result);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**result;
	size_t		i;
	size_t		words;
	size_t		len;

	i = 0;
	if (!s)
		return (NULL);
	if (!(result = malloc_words(s, c)))
		return (NULL);
	words = 0;
	while (s[i])
	{
		len = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			result[words][len] = s[i];
			len++;
			i++;
		}
		words++;
	}
	return (result);
}
