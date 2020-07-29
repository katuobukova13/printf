/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qblinky <qblinky@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 01:32:55 by qblinky           #+#    #+#             */
/*   Updated: 2020/05/26 23:44:49 by qblinky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	ss;
	char	*d;

	i = 0;
	ss = ft_strlen((char *)s);
	d = (char *)malloc(sizeof(*d) * (ss + 1));
	if (d == NULL)
		return (NULL);
	while (i < ss)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}
