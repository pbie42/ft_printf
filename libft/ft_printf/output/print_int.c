/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/11/16 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int					int_get_width(t_pf_item *pfi, long int num)
{
	int				width;

	width = 0;
	if (pfi->precision >= pfi->field_w)
		pfi->precision = 0;
	width = pfi->field_w - pfi->precision - 1;
	if (!pfi->precision)
		width -= int_length(num);
	if (pfi->flags->space && !pfi->flags->plus)
		width -= 1;
	if (pfi->flags->plus && num >= 0)
	{
		// ft_putendl("in here bruh");
		width -= 1;
	}
	if (num < 0)
		width -= 1;
	return (width);
}

void					pr_int_precision(t_pf_item *pfi, long int num)
{
	int				i;
	int				len;
	int				anum;
	
	i = pfi->precision;
	len = int_length(num);
	while (i-- > len)
	{
		ft_putchar('0');
		pfi->bytes++;
	}
	if (num < 0)
		pfi->bytes++;
	if (num < 0 && !pfi->flags->zero && num != 2147483648 && num != -2147483648)
	{
		ft_putchar('-');
		// pfi->bytes++;
	}
	anum = labs(num);
	ft_putnbr(anum);
	pfi->bytes += int_length(num);
}

void					pr_int_field_w(t_pf_item *pfi, int num)
{
	int				i;
	int				width;

	i = 0;
	width = int_get_width(pfi, num);
	if (pfi->flags->minus)
	{
		pr_int_precision(pfi, num);
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
		pr_int_precision(pfi, num);
	}
}

void					print_int(t_pf_item *pfi, long int num)
{
	int				anum;

	if (pfi->lenmods->h)
		num = (short)num;
	if (pfi->lenmods->hh)
		num = (signed char)num;
	if (pfi->flags->space && !pfi->flags->plus && num > 0)
		print_space_byte(pfi);
	if (pfi->flags->plus && num >= 0)
	{
		ft_putchar('+');
		pfi->bytes++;
	}
	if (pfi->flags->zero && num < 0 && num != 2147483648 && num != -2147483648)
	{
		ft_putchar('-');
		// pfi->bytes++;
	}
	if (pfi->field_w > 0)
	{
		if (pfi->precision > pfi->field_w)
			pr_int_precision(pfi, num);
		else
			pr_int_field_w(pfi, num);
	}
	else if (pfi->precision > 0)
		pr_int_precision(pfi, num);
	else
	{
		// ft_putendl("it's here");
		if (num < 0)
			pfi->bytes++;
		if (num < 0 && !pfi->flags->zero && num != 2147483648 && num != -2147483648)
		{
			ft_putchar('-');
			// pfi->bytes++;
		}
		anum = labs(num);
		ft_putnbr(anum);
		// ft_putendlnbr("bytes before int_length", pfi->bytes);
		pfi->bytes += int_length(num);
		// ft_putendlnbr("bytes after int_length", pfi->bytes);
	}
}