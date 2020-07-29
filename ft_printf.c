/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qblinky <qblinky@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 15:45:27 by qblinky           #+#    #+#             */
/*   Updated: 2020/07/29 21:57:10 by qblinky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		ft_init(void)
{
	t_flags	flags;

	flags.minus = 0;
	flags.zero = 0;
	flags.sign = 0;
	flags.width = 0;
	flags.precision = -1;
	flags.specifier = 0;
	flags.error = 0;
	return (flags);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	t_flags	flags;
	int		length;

	length = 0;
	va_start(ap, format);
	flags = ft_init();
	while (*format && !(flags.error))
	{
		flags = ft_init();
		if (*format != '%')
			length += ft_putchar_fd(*format, 1);
		else
			length += ft_parser((char **)&format, &flags, ap);
		format++;
	}
	va_end(ap);
	if (flags.error)
		length = -1;
	return (length);
}
