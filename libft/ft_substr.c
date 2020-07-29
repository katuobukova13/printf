/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qblinky <qblinky@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 14:40:21 by qblinky           #+#    #+#             */
/*   Updated: 2020/05/26 15:21:06 by qblinky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*subs;

	if (s == NULL)
		return (NULL);
	i = ft_strlen((char *)s);
	j = 0;
	if (i < start)
		return (ft_strdup(""));
	subs = malloc(sizeof(char) * (len + 1));
	if (subs == NULL)
		return (NULL);
	while (j < len)
	{
		subs[j] = s[start + j];
		j++;
	}
	subs[j] = '\0';
	return (subs);
}
