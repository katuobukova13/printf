/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qblinky <qblinky@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:40:47 by qblinky           #+#    #+#             */
/*   Updated: 2020/07/29 18:54:25 by qblinky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_percent(t_flags *flags)
{
	int		output;

	output = 0;
	if (flags->minus == 1)
		output += ft_putchar_fd('%', 1);
	while ((flags->width--) > 1)
	{
		if (flags->zero == 1)
			output += ft_putchar_fd('0', 1);
		else
			output += ft_putchar_fd(' ', 1);
	}
	if (flags->minus == 0)
		output += ft_putchar_fd('%', 1);
	return (output);
}
