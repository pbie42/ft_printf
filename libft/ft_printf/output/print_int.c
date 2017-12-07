/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/12/07 15:04:40 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int					int_get_width(t_pf_item *pfi, intmax_t num)
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
		width -= 1;
	if (num < 0)
		width -= 1;
	return (width);
}

void				pr_int_precision(t_pf_item *pfi, intmax_t num)
{
	int				i;
	int				len;
	intmax_t		anum;
	char			*test;

	i = pfi->precision;
	len = int_length(num);
	if (num < 0 && !pfi->flags->zero && num != 2147483648 && num != -2147483648)
		ft_putchar('-');
	while (i-- > len)
		print_zero_byte(pfi);
	if (num < 0)
		pfi->bytes++;
	if (num < 0)
		anum = num * -1;
	else
		anum = num;
	test = ft_llitoa(anum);
	if (pfi->lenmods->p && (num == 0) && (pfi->precision == 0))
		ft_putchar(' ');
	else
		ft_putstr(test);
	pfi->bytes += int_length(num);
}

void				pr_int_field_w(t_pf_item *pfi, intmax_t num)
{
	int				i;
	int				width;

	i = 0;
	width = int_get_width(pfi, num);
	if (pfi->flags->minus)
	{
		if (pfi->flags->plus && num >= 0 && !pfi->flags->zero)
			print_plus_byte(pfi);
		pr_int_precision(pfi, num);
		while (i++ <= width)
			print_space_byte(pfi);
	}
	else
	{
		if (pfi->flags->plus && num >= 0 && pfi->flags->zero)
			print_plus_byte(pfi);
		while (i++ <= width)
		{
			if (pfi->flags->zero && i >= pfi->precision)
				ft_putchar('0');
			else
				ft_putchar(' ');
			pfi->bytes++;
		}
		if (pfi->flags->plus && num >= 0 && !pfi->flags->zero)
			print_plus_byte(pfi);
		pr_int_precision(pfi, num);
	}
}

void				print_int(t_pf_item *pfi, intmax_t num)
{
	intmax_t		anum;
	char			*test;

	if (!pfi->lenmods->h && !pfi->lenmods->hh && !pfi->lenmods->l
		&& !pfi->lenmods->ll && !pfi->lenmods->j && !pfi->lenmods->z)
		num = (int)num;
	if (pfi->lenmods->h)
		num = (short)num;
	if (pfi->lenmods->hh)
		num = (signed char)num;
	if (pfi->lenmods->l)
		num = (long long)num;
	if (pfi->flags->space && !pfi->flags->plus && num > 0)
		print_space_byte(pfi);
	if (pfi->flags->plus && num >= 0 && pfi->field_w == 0)
		print_plus_byte(pfi);
	if (pfi->flags->zero && num < 0 && num != 2147483648)
		ft_putchar('-');
	if (pfi->field_w > 0)
		if (pfi->precision > pfi->field_w)
			pr_int_precision(pfi, num);
		else
			pr_int_field_w(pfi, num);
	else if (pfi->precision > 0)
		pr_int_precision(pfi, num);
	else
	{
		anum = num;
		if (num < 0)
			pfi->bytes++;
		if (num < 0 && !pfi->flags->zero && num != 2147483648)
			ft_putchar('-');
		if (num < 0)
			anum = num * -1;
		else
			anum = num;
		test = ft_llitoa(anum);
		if (pfi->lenmods->p && (num == 0) && (pfi->precision == 0))
			pfi->bytes--;
		else
			ft_putstr(test);
		pfi->bytes += int_length(num);
	}
}
