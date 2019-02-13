/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outil.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:12:17 by bordenoy          #+#    #+#             */
/*   Updated: 2019/02/13 20:11:41 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned	int	hexa(t_gob opt, char c, int g)
{
	if ((c == 'x' && (opt.opt.opt & 2)) || c == 'p')
	{
		if (g)
		{
			ft_add(opt.b, '0');
			ft_add(opt.b, 'x');
		}
		return (2);
	}
	if (c == 'X' && (opt.opt.opt & 2))
	{
		if (g)
		{
			ft_add(opt.b, '0');
			ft_add(opt.b, 'X');
		}
		return (2);
	}
	if (c == 'o' && (opt.opt.opt & 2))
	{
		if (g)
			ft_add(opt.b, '0');
		return (1);
	}
	return (0);
}

unsigned	int	or(int a, int b)
{
	if (b & 16)
		a += 1;
	return (a);
}

int				signe(t_gob opt, int b, int c)
{
	if (c == -1)
		return (0);
	if (opt.opt.opt & 16 && b >= +0)
	{
		if (c)
			ft_add(opt.b, '+');
		if (opt.opt.precision > -1)
			return (1);
		return (0);
	}
	if (b < 0)
	{
		if (c)
			ft_add(opt.b, '-');
		return (1);
	}
	return (0);
}

void			affre(t_gob opt, unsigned int a, int b)
{
	char		pp;
	unsigned	gg;

	pp = opts(opt, b);
	gg = hexa(opt, opt.opt.conversion, opt.opt.opt & 1);
	opt.opt.largeur -= signe(opt, b, 0);
	if ((opt.opt.opt & 8) && (!(opt.opt.opt & 16)))
		ft_add(opt.b, ' ');
	if (!(opt.opt.opt & 4) && (opt.opt.largeur > 0))
		while ((int)opt.opt.largeur > opt.opt.precision
				&& opt.opt.largeur > gg + or(a, opt.opt.opt))
		{
			ft_add(opt.b, pp);
			opt.opt.largeur--;
		}
	signe(opt, b, 1);
	while (opt.opt.precision > (int)a)
	{
		ft_add(opt.b, '0');
		opt.opt.precision--;
	}
	hexa(opt, opt.opt.conversion, (!(opt.opt.opt & 1)));
}

void			offre(t_gob opt, unsigned int a, union u_datas nbr)
{
	unsigned gg;

	opt.opt.largeur -= signe(opt, nbr.d, 0);
	gg = hexa(opt, opt.opt.conversion, 0);
	if (opt.opt.opt & 4)
		while ((int)opt.opt.largeur > opt.opt.precision
				&& opt.opt.largeur > gg + or(a, opt.opt.opt))
		{
			ft_add(opt.b, ' ');
			opt.opt.largeur--;
		}
}
