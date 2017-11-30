/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/11/24 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void					pr_int_us_precision(t_pf_item *pfi, unsigned int num)
{
	int				i;
	int				len;
	
	i = pfi->precision;
	len = int_length(num);
	while (i-- > len)
	{
		ft_putchar('0');
		pfi->bytes++;
	}
	ft_putll(num);
	pfi->bytes++;
}

int					int_us_get_width(t_pf_item *pfi, unsigned int num)
{
	int				width;

	width = 0;
	if (pfi->precision >= pfi->field_w)
		pfi->precision = 0;
	width = pfi->field_w - pfi->precision - 1;
	if (!pfi->precision)
		width -= int_length(num);
	return (width);
}

void					pr_int_us_field_w(t_pf_item *pfi, unsigned int num)
{
	int				i;
	int				width;

	i = 0;
	width = int_us_get_width(pfi, num);
	if (pfi->flags->minus)
	{
		pr_int_us_precision(pfi, num);
		while (i++ <= width)
			print_space_byte(pfi);
	}
	else
	{
		while (i++ <= width)
		{
			if (pfi->flags->zero)
				ft_putchar('0');
			else
				ft_putchar(' ');
			pfi->bytes++;
		}
		pr_int_us_precision(pfi, num);
	}
}

void					print_unsigned_int(t_pf_item *pfi, unsigned int num)
{
	unsigned int	i;

	i = num;
	if (pfi->field_w > 0)
	{
		if (pfi->precision > pfi->field_w)
			pr_int_us_precision(pfi, i);
		else
			pr_int_us_field_w(pfi, i);
	}
	else if (pfi->precision > 0)
		pr_int_us_precision(pfi, i);
	else
	{
		ft_putll(num);
		pfi->bytes++;
	}
}