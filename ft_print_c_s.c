/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qblinky <qblinky@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:38:16 by qblinky           #+#    #+#             */
/*   Updated: 2020/07/30 05:51:43 by qblinky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_c(char c, t_flags *flags)
{
	int		output;

	output = 0;
	if (flags->minus == 1)
		output += ft_putchar_fd(c, 1);
	while ((flags->width--) > 1)
		output += ft_putchar_fd(' ', 1); //заполнение пробелами до или после с
	if (flags->minus == 0)
		output += ft_putchar_fd(c, 1);
	return (output);
}

int			ft_print_s(char *s, t_flags *flags)
{
	int		output;
	int		i;

	output = 0;
	if (s == NULL)
		s = "(null)";
	i = ft_strlen(s);
	if (flags->precision == 0 && flags->width == 0)
		return (0);
	if (flags->precision > 0 && flags->precision < i) //отрезает строку по точности (дает макс значение строки)
		i = flags->precision;
	if (flags->precision != 0)
		flags->width -= i;  //отнимает из ширины макс значение строки
	if (flags->minus == 1 && flags->precision != 0)
		output += ft_putstr(s, i);
	while ((flags->width--) > 0)
	{
		if (flags->zero == 1)
			output += ft_putchar_fd('0', 1);
		else
			output += ft_putchar_fd(' ', 1);
	}
	if (flags->minus == 0 && flags->precision != 0)  //заполняет пробелами ширину
		output += ft_putstr(s, i);
	return (output);
}
