/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qblinky <qblinky@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:43:30 by qblinky           #+#    #+#             */
/*   Updated: 2020/07/30 05:10:49 by qblinky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_u(unsigned int u, t_flags *flags)
{
	char	*s;
	int		output;
	int		precision;
	int		i;

	output = 0;
	precision = flags->precision;
	u = (unsigned int)(4294967295 + 1 + u);
	if (!(s = ft_render_upx((unsigned long long)u, 10, flags)))
		return (flags->error = 1);
	i = ft_strlen(s);
	if (precision == 0 && u == 0)
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
