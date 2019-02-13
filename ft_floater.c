/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floater.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:37:59 by bordenoy          #+#    #+#             */
/*   Updated: 2019/02/13 18:02:30 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	float_opt(long long a, t_gob opt)
{
	int i;

	if (a < 0)
		ft_add(opt.b, '-');
	i = (opt.opt.precision > 0) + opt.opt.precision;
	i += float_count(a);
	if ((opt.opt.opt & 8) && !(opt.opt.opt & 16) && (a >= 0))
		ft_add(opt.b, ' ');
	if (!(opt.opt.opt & 8) && (opt.opt.opt & 16) && (a >= 0))
		ft_add(opt.b, '+');
	while ((int)opt.opt.largeur > i && !(opt.opt.opt & 4))
	{
		ft_add(opt.b, ft_floatzero(opt));
		opt.opt.largeur--;
	}
}

void	aff_float(long long a, long long b, t_gob opt)
{
	int g;
	int f;

	g = ft_size(opt.opt.precision + 1);
	f = (b % 10 > 4);
	if (opt.opt.precision == 0)
		a += f;
	ft_fl_base(ABS(a), "0123456789", opt);
	if ((opt.opt.opt) & 2 && (opt.opt.precision == 0))
		ft_add(opt.b, '.');
	if (opt.opt.precision > 0)
	{
		ft_add(opt.b, '.');
		if (opt.opt.precision == 1)
			b = ((b / (g * 10)) + f);
		else
			b = ((b / 10) + f);
		ft_fl_base(b, "0123456789", opt);
	}
}

void	ft_floater(long double hallo, t_gob opt)
{
	long long	m;
	int			g;

	g = opt.opt.precision + 1;
	m = (long long)hallo;
	hallo = hallo - (long double)m;
	while (g)
	{
		hallo *= 10;
		g--;
	}
	float_opt(m, opt);
	aff_float(m, hallo, opt);
	float_optafter(m, opt);
}

void	ft_getf(va_list ap, t_gob opt)
{
	if (opt.opt.taille == 0)
		ft_floater(va_arg(ap, double), opt);
	if (opt.opt.taille == 1)
		ft_floater(va_arg(ap, double), opt);
	if (opt.opt.taille == 8)
		ft_floater(va_arg(ap, long double), opt);
}
