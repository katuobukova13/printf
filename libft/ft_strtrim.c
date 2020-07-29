/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qblinky <qblinky@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 00:55:35 by qblinky           #+#    #+#             */
/*   Updated: 2020/05/24 04:19:08 by qblinky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			start;
	size_t			end;
	char			*s2;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen((char*)s1 + start);
	if (end)
		while (s1[end + start - 1] != 0 &&
		ft_strchr(set, s1[end + start - 1]) != 0)
			end--;
	s2 = malloc(sizeof(char) * (end + 1));
	if (s2 == NULL)
		return (NULL);
	ft_strlcpy(s2, s1 + start, end + 1);
	s2[end] = '\0';
	return (s2);
}
