/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/11/18 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void					print_char_field_w(t_pf_item *pfi, unsigned char c)
{
	int				i;

	i = 0;
	if (pfi->flags->minus)
	{
		ft_putchar(c);
		while (i++ < pfi->field_w - 1)
			print_space_byte(pfi);
	}
	else
	{
		while (i++ < pfi->field_w - 1)
		{
			if (pfi->flags->zero)
				ft_putchar('0');
			else
				ft_putchar(' ');
			pfi->bytes++;
		}
		ft_putchar(c);
	}
}

void					print_char(t_pf_item *pfi, unsigned char c)
{
	if (pfi->field_w > 0)
		print_char_field_w(pfi, c);
	else
		ft_putchar(c);
	pfi->bytes++;
}
