/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qblinky <qblinky@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:41:52 by qblinky           #+#    #+#             */
/*   Updated: 2020/07/29 22:37:23 by qblinky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_p(unsigned long long address, t_flags *flags)
{
	char	*s;
	int		output;
	int		precision;
	int		i;

	output = 0;
	if (!(s = ft_render_upx(address, 16, flags)))
		return (flags->error = 1);
	i = ft_strlen(s);
	precision = flags->precision;
	if (precision == 0 && address == 0)
		i = 0;
	if (flags->minus == 0)
		output += ft_print_width(i, flags);
	output += ft_putstr("0x", 2);
	while (precision-- > i)
		output += ft_putchar_fd('0', 1);
	output += ft_putstr(s, i);
	if (flags->minus == 1)
		output += ft_print_width(i, flags);
	free(s);
	return (output);
}

int			ft_print_x(unsigned int hex, t_flags *flags)
{
	char	*s;
	int		output;
	int		precision;
	int		i;

	output = 0;
	hex = (unsigned int)(4294967295 + 1 + hex);
	if (!(s = ft_render_upx((unsigned long long)hex, 16, flags)))
		return (flags->error = 1);
	i = ft_strlen(s);
	precision = flags->precision;
	if (precision == 0 && hex == 0)
		i = 0;
	if (flags->minus == 0)
		output += ft_print_width(i, flags);
	while (precision-- > i)
		output += ft_putchar_fd('0', 1);
	output += ft_putstr(s, i);
	if (flags->minus == 1)
		output += ft_print_width(i, flags);
	free(s);
	return (output);
}
