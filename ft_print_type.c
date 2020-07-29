/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qblinky <qblinky@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 18:04:29 by qblinky           #+#    #+#             */
/*   Updated: 2020/07/29 19:01:50 by qblinky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_type(t_flags *flags, va_list ap)
{
	int length;

	length = 0;
	length += flags->specifier == 'i' || flags->specifier == 'd' ? \
	ft_print_d_i(va_arg(ap, int), flags) : 0;
	length += flags->specifier == 'u' ? \
	ft_print_u(va_arg(ap, unsigned int), flags) : 0;
	length += flags->specifier == 'c' ? ft_print_c(va_arg(ap, int), flags) : 0;
	length += flags->specifier == 's' ? \
	ft_print_s(va_arg(ap, char *), flags) : 0;
	length += flags->specifier == 'p' ? \
	ft_print_p(va_arg(ap, unsigned long long), flags) : 0;
	length += flags->specifier == 'x' || flags->specifier == 'X' ? \
	ft_print_x(va_arg(ap, unsigned int), flags) : 0;
	length += flags->specifier == '%' ? ft_print_percent(flags) : 0;
	return (length);
}
