/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qblinky <qblinky@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 01:29:27 by qblinky           #+#    #+#             */
/*   Updated: 2020/05/26 15:06:05 by qblinky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**free_s(char **s)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static char		**fill_s(char const *s, char **newwords, char c)
{
	size_t i;
	size_t saveword;
	size_t lenword;

	i = 0;
	saveword = 0;
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		lenword = 0;
		while (s[i + lenword] != c && s[i + lenword] != '\0')
			lenword++;
		if (lenword == 0)
			break ;
		if (!(newwords[saveword] = ft_substr(s, i, lenword)))
			return (free_s(newwords));
		saveword++;
		i = i + lenword;
	}
	newwords[saveword] = NULL;
	return (newwords);
}

char			**ft_split(char	const *s, char c)
{
	char	**words;
	size_t	split;
	size_t	i;

	i = 0;
	split = 0;
	while (s[i++] != '\0')
	{
		if ((s[i] == c || s[i] == '\0') && s[i - 1] != c)
			split++;
	}
	words = malloc(sizeof(char *) * (split + 1));
	if (words == NULL)
		return (NULL);
	words = fill_s(s, words, c);
	return (words);
}
