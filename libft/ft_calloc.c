/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qblinky <qblinky@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 21:38:48 by qblinky           #+#    #+#             */
/*   Updated: 2020/05/26 15:03:32 by qblinky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void *dest;

	dest = malloc(nmemb * size);
	if (dest == NULL)
		return (NULL);
	ft_memset(dest, 0, nmemb * size);
	return (dest);
}
