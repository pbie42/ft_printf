/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_zero_space_ws.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2018/01/04 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				print_zero_space_ws(t_pf_item *pfi, int width)
{
	if (pfi->flags->zero)
		ft_putchar('0');
	else
		ft_putchar(' ');
	pfi->bytes++;
	width--;
	return (width);
}
