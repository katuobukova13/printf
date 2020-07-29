/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qblinky <qblinky@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:36:13 by qblinky           #+#    #+#             */
/*   Updated: 2020/07/29 18:54:44 by qblinky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_d_i(int d_i, t_flags *flags)
{
	char	*s;
	int		output;
	int		i;

	output = 0;
	if (!(s = ft_itoa(d_i)))
		return (flags->error = 1);
	i = ft_strlen(s);
	flags->sign = s[0];
	if (flags->precision == 0 && d_i == 0)
		i = 0;
	if (flags->minus == 0)
		output += ft_print_width(i, flags);
	output += ft_print_precision(i, flags);
	if (flags->sign == '-')
		output += ft_putstr(s + 1, i - 1);
	else
		output += ft_putstr(s, i);
	if (flags->minus == 1)
		output += ft_print_width(i, flags);
	free(s);
	return (output);
}
