/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qblinky <qblinky@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 01:31:59 by qblinky           #+#    #+#             */
/*   Updated: 2020/05/24 01:32:40 by qblinky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		j;
	char	*ss;

	i = 0;
	ss = (char *)s;
	j = ft_strlen(ss);
	while (i < j && ss[i] != (char)c)
		i++;
	return (ss[i] == (char)c ? &ss[i] : NULL);
}
