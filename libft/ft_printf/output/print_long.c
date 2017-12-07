/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/11/16 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void					handle_spaces(t_pf_item *pfi, long num, t_bool minus)
{
	int				len;

	len = long_length(num);
	if (num < 0)
		len += 1;
	if (pfi->flags->space && num >= 0)
	{
		len += 1;
		ft_putchar(' ');
	}
	if (minus)
		ft_putnbr(num);
	if (pfi->field_w - len > 0)
		while (pfi->field_w > len)
		{
			ft_putchar(' ');
			pfi->field_w--;
		}
}

void					print_long(t_pf_item *pfi, long num)
{
	if (pfi->field_w > 0 && !pfi->flags->minus)
	{
		handle_spaces(pfi, num, FALSE);
		ft_putnbr(num);
	}
	else if (pfi->field_w > 0 && pfi->flags->minus)
		handle_spaces(pfi, num, TRUE);
	else
		ft_putnbr(num);
}
