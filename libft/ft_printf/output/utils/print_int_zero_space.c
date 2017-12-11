/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_zero_space.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/12/07 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void				print_int_zero_space(t_pf_item *pfi, int i, int prcsn)
{
	if (pfi->flags->zero && i >= prcsn)
		ft_putchar('0');
	else
		ft_putchar(' ');
	pfi->bytes++;
}
