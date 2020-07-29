/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qblinky <qblinky@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:46:32 by qblinky           #+#    #+#             */
/*   Updated: 2020/07/29 18:55:05 by qblinky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_flag(char *format, t_flags *flags)
{
	int		i;

	i = 0;
	while (format[i] == '0' || format[i] == '-')
	{
		if (format[i] == '-')
			flags->minus = 1;
		else if (format[i] == '0')
			flags->zero = 1;
		i++;
	}
	if (flags->minus == 1)
		flags->zero = 0;
	return (i);
}

int	ft_check_width(char *format, t_flags *flags, va_list ap)
{
	int		i;
	int		width;

	width = 0;
	i = 0;
	if (format[i] == '*')
	{
		width = va_arg(ap, int);
		if (width < 0)
		{
			flags->zero = 0;
			flags->minus = 1;
			width *= -1;
		}
		flags->width = width;
		i++;
		return (i);
	}
	while (ft_isdigit(*(format + i)))
	{
		width = (width * 10) + (*(format + i) - '0');
		i++;
	}
	flags->width = width;
	return (i);
}

int	ft_check_precision(char *format, t_flags *flags, va_list ap)
{
	int		precision;
	int		i;

	i = 1;
	precision = 0;
	if (format[i] == '*')
	{
		precision = va_arg(ap, int);
		if (precision < 0)
			precision = -1;
		flags->precision = precision;
		i++;
		return (i);
	}
	if (ft_isdigit(format[i]))
	{
		while (ft_isdigit(format[i]))
			precision = (precision * 10) + (format[i++] - '0');
	}
	else
		precision = 0;
	flags->precision = precision;
	return (i);
}

int	ft_check_specifier(char format, t_flags *flags)
{
	if (format == 'c' || format == 's' || format == 'd' ||
	format == 'i' || format == 'p' || format == 'u' ||
	format == 'x' || format == 'X' || format == '%')
		return (flags->specifier = format);
	else
		return (flags->error = 1);
}

int	ft_parser(char **format, t_flags *flags, va_list ap)
{
	int length;
	int i;

	length = 0;
	i = 1;
	i += (*(*format + i) == '0' || *(*format + i) == '-') ? \
	ft_check_flag(*format + i, flags) : 0;
	i += (ft_isdigit(*(*format + i)) || *(*format + i) == '*') ? \
	ft_check_width(*format + i, flags, ap) : 0;
	i += (*(*format + i) == '.') ? \
	ft_check_precision(*format + i, flags, ap) : 0;
	ft_check_specifier(*(*format + i), flags);
	length += ft_print_type(flags, ap);
	*format += i;
	return (length);
}
