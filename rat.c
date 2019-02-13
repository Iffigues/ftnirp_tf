/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 19:15:13 by bordenoy          #+#    #+#             */
/*   Updated: 2019/02/13 22:00:08 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen_at(const char *str, size_t a)
{
	while (str[a])
		a++;
	return (a);
}

char	opts(t_gob opt, int nb)
{
	if ((opt.opt.precision >= 0) & (opt.opt.opt & 1))
		opt.opt.opt = opt.opt.opt - 1;
	if (opt.opt.opt & 8 && nb >= +0 && !(opt.opt.opt & 16))
		ft_add(opt.b, ' ');
	if (opt.opt.opt & 1)
		return ('0');
	return (' ');
}

size_t	ft_strlen(char *c)
{
	int y;

	y = 0;
	while (c[y])
		y++;
	return (y);
}

void	ft_pourcentage(t_datas nbr, t_gob opt)
{
	nbr.d = 0;
	ft_add(opt.b, opt.opt.conversion);
}

void	ft_putstr(t_datas nbr, t_gob opt)
{
	int y;
	int u;

	u = (opt.opt.opt & 4);
	y = ft_strlen(nbr.s);
	if ((opt.opt.precision > -1) &&(opt.opt.precision <= y))
		y = opt.opt.precision;
	while (((int)opt.opt.largeur > y) && !(u))
	{
		ft_add(opt.b, ' ');
		opt.opt.largeur--;
	}
	opt.opt.opt = 0;
	if (opt.opt.precision >= 0)
		while (*nbr.s && opt.opt.precision--)
			ft_add(opt.b, *nbr.s++);
	else
		while (*nbr.s)
			ft_add(opt.b, *nbr.s++);
	while (((int)opt.opt.largeur > 0) && (u))
	{
		ft_add(opt.b, ' ');
		opt.opt.largeur--;
	}
}
