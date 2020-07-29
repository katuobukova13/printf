/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qblinky <qblinky@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 20:43:56 by qblinky           #+#    #+#             */
/*   Updated: 2020/07/29 19:22:49 by qblinky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef	struct	s_flags
{
	int			sign;
	int			width;
	int			minus;
	int			zero;
	int			precision;
	int			specifier;
	int			error;
}				t_flags;

int				ft_printf(const char *format, ...);
t_flags			ft_init(void);
int				ft_parser(char **format, t_flags *flags, va_list ap);
int				ft_check_flag(char *format, t_flags *flags);
int				ft_check_width(char *format, t_flags *flags, va_list ap);
int				ft_check_precision(char *format, t_flags *flags, va_list ap);
int				ft_check_specifier(char format, t_flags *flags);
int				ft_print_type(t_flags *flags, va_list ap);
int				ft_putstr(char *s, int i);
int				ft_print_precision(int i, t_flags *flags);
int				ft_print_width(int i, t_flags *flags);
int				ft_strlen_unsigned(unsigned long long nbr, int base);
char			*ft_render_upx(unsigned long long nbr, int base, \
t_flags *flags);
int				ft_print_d_i(int d_i, t_flags *flags);
int				ft_print_c(char c, t_flags *flags);
int				ft_print_s(char *s, t_flags *flags);
int				ft_print_u(unsigned int u, t_flags *flags);
int				ft_print_p(unsigned long long address, t_flags *flags);
int				ft_print_x(unsigned int hex, t_flags *flags);
int				ft_print_percent(t_flags *flags);

#endif
