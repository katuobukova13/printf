/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qblinky <qblinky@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 21:33:58 by qblinky           #+#    #+#             */
/*   Updated: 2020/07/10 02:46:31 by qblinky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long long int	res;
	long long int	x;
	int				sign;
	int				i;

	i = 0;
	res = 0;
	sign = 1;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\r'
	|| nptr[i] == '\f' || nptr[i] == '\n' || nptr[i] == '\v')
		i++;
	if (nptr[i] == '-' || (nptr[i] == '+'))
		sign *= (nptr[i++] == '-') ? -1 : 1;
	while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		x = (res * 10) + (nptr[i] - '0');
		i++;
		if (x < res)
			return (sign > 0 ? -1 : 0);
		res = x;
	}
	return (res * sign);
}
