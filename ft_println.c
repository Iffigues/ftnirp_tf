/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_println.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 20:09:05 by bordenoy          #+#    #+#             */
/*   Updated: 2019/02/13 17:53:32 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_vsprintf(t_gob *opt, const char *format, va_list ap)
{
	while (*format && ft_getsize(opt->b, 1) >= 0)
	{
		if ((*format) == '%' && *format++)
		{
			opt->opt = getopts(format);
			format += par(format, &opt->opt, ap);
			format += taille(format, &opt->opt);
			ft_arrange(*opt, *format, ap);
			format++;
		}
		else
			ft_add(opt->b, *format++);
	}
	return (end(opt->b));
}

int		ft_printf(const char *format, ...)
{
	int		a;
	va_list	arg;
	t_gob	gob;
	char	b[BUFF_SIZE + sizeof(int) * 2 + 1];

	ft_bzero(b, BUFF_SIZE + sizeof(int) * 2);
	gob.b = b;
	va_start(arg, format);
	a = ft_vsprintf(&gob, format, arg);
	va_end(arg);
	return (a);
}
