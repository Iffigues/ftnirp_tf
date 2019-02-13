/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 19:10:27 by bordenoy          #+#    #+#             */
/*   Updated: 2019/02/13 20:58:03 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*my_hexa(char c)
{
	if ((c == 'd') || (c == 'u') || (c == 'i'))
		return ("0123456789");
	if (c == 'b')
		return ("01");
	if (c == 'o')
		return ("01234567");
	if (c == 'x' || c == 'p')
		return ("0123456789abcdef");
	if (c == 'X')
		return ("0123456789ABCDEF");
	return (NULL);
}

void	ft_putnbr(t_datas nbr, t_gob opt)
{
	int a;

	if (opt.opt.taille == 0)
		a = ft_ret(nbr.d, my_hexa(opt.opt.conversion), 1, opt);
	if (opt.opt.taille == 1)
		a = ft_ret(nbr.l, my_hexa(opt.opt.conversion), 1, opt);
	if (opt.opt.taille == 2)
		a = ft_ret(nbr.ll, my_hexa(opt.opt.conversion), 1, opt);
	if (opt.opt.taille == 4)
		a = ft_ret(nbr.h, my_hexa(opt.opt.conversion), 1, opt);
	if (opt.opt.taille == 6)
		a = ft_ret(nbr.c, my_hexa(opt.opt.conversion), 1, opt);
	offre(opt, a, nbr);
}

void	ft_putnbr_address(t_datas nbr, t_gob opt)
{
	int			a;
	uintptr_t	t;

	t = (uintptr_t)nbr.f;
	a = ft_u_b(t, my_hexa(opt.opt.conversion), 1, opt);
	offre(opt, a, nbr);
}

void	ft_putnbr_unsigned(t_datas nbr, t_gob opt)
{
	int		a;
	char	c;

	c = opt.opt.conversion;
	if (opt.opt.taille == 0)
		a = ft_retu(nbr.us, my_hexa(c), 1, opt);
	if (opt.opt.taille == 1)
		a = ft_retu(nbr.ul, my_hexa(c), 1, opt);
	if (opt.opt.taille == 2)
		a = ft_retu(nbr.ull, my_hexa(c), 1, opt);
	if (opt.opt.taille == 4)
		a = ft_retu(nbr.ush, my_hexa(c), 1, opt);
	if (opt.opt.taille == 6)
		a = ft_retu(nbr.uc, my_hexa(c), 1, opt);
	offre(opt, a, nbr);
}

void	ft_putchar(t_datas nbr, t_gob opt)
{
	int u;

	u = (opt.opt.opt & 4);
	while (((int)opt.opt.largeur > 1) && !(u))
	{
		ft_add(opt.b, ' ');
		opt.opt.largeur--;
	}
	opt.opt.opt = 0;
	ft_add(opt.b, nbr.c);
	while (((int)opt.opt.largeur > 1) && (u))
	{
		ft_add(opt.b, ' ');
		opt.opt.largeur--;
	}
}
