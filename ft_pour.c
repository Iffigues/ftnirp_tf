/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pour.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:52:32 by bordenoy          #+#    #+#             */
/*   Updated: 2019/02/13 19:57:45 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_pour(t_gob opt)
{
	while (((int)opt.opt.largeur > 1) && !(opt.opt.opt & 4))
	{
		ft_add(opt.b, ' ');
		opt.opt.largeur--;
	}
	ft_add(opt.b, '%');
	while (((int)opt.opt.largeur > 1) && (opt.opt.opt & 4))
	{
		ft_add(opt.b, ' ');
		opt.opt.largeur--;
	}
}
