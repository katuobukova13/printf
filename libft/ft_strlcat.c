/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qblinky <qblinky@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 01:39:23 by qblinky           #+#    #+#             */
/*   Updated: 2020/05/24 13:58:58 by qblinky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*s;
	size_t	len_d;
	size_t	len_s;
	size_t	i;

	s = (char *)src;
	len_d = ft_strlen(dst);
	len_s = ft_strlen(s);
	i = 0;
	if (size <= len_d)
		return (len_s + size);
	while (s[i] != '\0' && i < (size - len_d - 1))
	{
		dst[len_d + i] = s[i];
		i++;
	}
	dst[len_d + i] = '\0';
	return (len_d + len_s);
}
