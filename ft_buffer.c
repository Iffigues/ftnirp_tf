/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:10:49 by bordenoy          #+#    #+#             */
/*   Updated: 2019/02/13 14:51:20 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		aff(char *b, int bb)
{
	return (ft_putstrlensize(b, bb));
}

int		ft_getsize(char *b, int c)
{
	return (b[sizeof(int) * c]);
}

int		end(char *b)
{
	int a;

	if (*b && b[sizeof(int)] > 0)
		aff(&b[sizeof(int) * 2], *b);
	a = b[sizeof(int)];
	ft_bzero(b, BUFF_SIZE + sizeof(int) * 2);
	return (a);
}

void	ft_add(char *b, const char c)
{
	b[sizeof(int) * 2 + *b] = c;
	*b += 1;
	b[sizeof(int)] += 1;
	b[sizeof(int) * 2 + *b] = '\0';
	if ((int)*b == BUFF_SIZE)
	{
		aff(&b[sizeof(int) * 2], *b);
		ft_bzero(&b[sizeof(int) * 2], BUFF_SIZE);
		*b = 0;
	}
}
