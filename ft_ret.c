/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ret.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:52:20 by bordenoy          #+#    #+#             */
/*   Updated: 2019/02/13 20:58:51 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_ret(long long h, char *c, int a, t_gob opt)
{
	if (h == 0 && (opt.opt.opt & 2))
		opt.opt.opt = opt.opt.opt ^ 2;
	if (opt.opt.precision == 0 && h == 0)
	{
		affre(opt, 0, h);
		return (0);
	}
	return (ft_putnbr_base(h, c, a, opt));
}

int ft_retu(unsigned long long h, char *c, int a, t_gob opt)
{
	if (h == 0 && (opt.opt.opt & 2))
		opt.opt.opt = opt.opt.opt ^ 2;
	if (opt.opt.precision == 0 && h == 0)
	{
		affre(opt, 0, h);
		return (0);
	}
	return (ft_u_b(h, c, a, opt));
}

