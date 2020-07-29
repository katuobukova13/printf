/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qblinky <qblinky@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 21:51:04 by qblinky           #+#    #+#             */
/*   Updated: 2020/07/29 21:27:24 by qblinky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	strlen_n(unsigned int nb)
{
	if (nb > 9)
		return (1 + strlen_n(nb / 10));
	return (1);
}

char			*ft_itoa(int n)
{
	char			*s;
	size_t			len;
	int				sign;
	unsigned int	nb;

	sign = (n < 0) ? 1 : 0;
	nb = (n < 0) ? -n : n;
	len = strlen_n(nb) + sign;
	s = (char *)malloc(sizeof(char) * len + 1);
	if (s == NULL)
		return (NULL);
	s[len] = '\0';
	while (len-- > (size_t)sign)
	{
		s[len] = nb % 10 + '0';
		nb /= 10;
	}
	if (sign == 1)
		s[len] = '-';
	return (s);
}
