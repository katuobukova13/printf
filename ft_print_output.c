/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qblinky <qblinky@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 14:28:57 by qblinky           #+#    #+#             */
/*   Updated: 2020/07/30 04:25:13 by qblinky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_putstr(char *s, int i)
{
	int		output;

	output = 0;
	while (s[output] != '\0' && i > 0)
	{
		write(1, &s[output], 1);
		output++;
		i--;
	}
	return (output);
}

int			ft_print_precision(int i, t_flags *flags)
{
	int		output;
	int		precision;
	char	sign;

	output = 0;
	precision = flags->precision;
	sign = flags->sign;
	if (sign == '-')
	{
		if (flags->minus == 1)
			output += ft_putchar_fd('-', 1);
		i--;
	}
	while (precision-- > i)
		output += ft_putchar_fd('0', 1);
	return (output);
}

int			ft_print_width(int i, t_flags *flags)
{
	int		output;
	int		width;
	int		precision;

	output = 0;
	width = flags->width;
	precision = flags->precision;
	if (flags->specifier == 'p')
		i += 2;
	if (precision >= i && flags->sign == '-')
		precision++;
	if (precision >= i)
		i = precision;
	while (width-- > i && (flags->zero == 0 || precision != -1))
		output += ft_putchar_fd(' ', 1);
	if (flags->sign == '-' && flags->minus == 0)
		output += ft_putchar_fd('-', 1);
	width = flags->width;
	while (width-- > i && flags->zero == 1 && precision == -1)
		output += ft_putchar_fd('0', 1);
	return (output);
}

int			ft_strlen_unsigned(unsigned long long nbr, int base)
{
	int		i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

char		*ft_render_upx(unsigned long long nbr, int base, t_flags *flags)
{
	char	*low_hex;
	char	*up_hex;
	char	*s;
	char	specifier;
	int		i;

	low_hex = "0123456789abcdef";
	up_hex = "0123456789ABCDEF";
	specifier = flags->specifier;
	i = ft_strlen_unsigned(nbr, base);
	if (!(s = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	s[i] = '\0';
	while (--i >= 0)
	{
		if (specifier == 'p' || specifier == 'u' || specifier == 'x')
			s[i] = low_hex[nbr % base];
		else if (specifier == 'X')
			s[i] = up_hex[nbr % base];
		nbr /= base;
	}
	return (s);
}
