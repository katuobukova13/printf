/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qblinky <qblinky@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 02:56:46 by qblinky           #+#    #+#             */
/*   Updated: 2020/05/28 17:50:41 by qblinky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*l;
	char	*b;

	if (*little == '\0')
		return ((char *)big);
	l = (char *)little;
	b = (char *)big;
	i = 0;
	while (b[i] != '\0' && i < len)
	{
		j = 0;
		while (l[j] != '\0' && l[j] == b[i + j] && (i + j) < len)
			j++;
		if (l[j] == '\0')
			return (&b[i]);
		i++;
	}
	return (NULL);
}
