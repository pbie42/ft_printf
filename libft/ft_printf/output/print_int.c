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

#define MAX8 "9223372036854775808"
#define MAX7 "9223372036854775807"
#define FLAGS pfi->flags

int					int_get_width(t_pf_item *pfi, intmax_t num, int prcsn)
{
	int				width;

	width = 0;
	if (pfi->precision < int_length(num))
		pfi->precision = int_length(num);
	if (pfi->precision >= pfi->field_w)
	{
		pfi->precision = 0;
		prcsn = 0;
	}
	width = pfi->field_w - pfi->precision - 1;
	if (!pfi->precision)
		width -= int_length(num);
	if (FLAGS->space && !FLAGS->plus)
		width -= 1;
	if (FLAGS->plus && num >= 0)
		width -= 1;
	if (num < 0)
		width -= 1;
	return (width);
}

void				pr_int_precision(t_pf_item *pfi, intmax_t num, int prcsn)
{
	int				i;
	int				len;
	intmax_t		anum;
	char			*test;

	i = pfi->precision;
	len = int_length(num);
	if (num < 0 && !FLAGS->zero && num != 2147483648 && num != -2147483648)
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
	if (pfi->lenmods->p && (num == 0) && (prcsn == 0))
		ft_putchar(' ');
	else
		ft_putstr(test);
	pfi->bytes += int_length(num);
	if (ft_strcmp(test, MAX7) != 0 && ft_strcmp(test, MAX8) != 0)
		free(test);
}

void				pr_int_field_w(t_pf_item *pfi, intmax_t num, int prcsn)
{
	int				i;
	int				width;

	i = 0;
	width = int_get_width(pfi, num, prcsn);
	if (FLAGS->minus)
	{
		if (FLAGS->plus && num >= 0 && !FLAGS->zero)
			print_plus_byte(pfi);
		if (FLAGS->plus && num >= 0 && FLAGS->zero && FLAGS->minus)
			print_plus_byte(pfi);
		pr_int_precision(pfi, num, prcsn);
		while (i++ <= width)
			print_space_byte(pfi);
	}
	else
	{
		if (FLAGS->plus && num >= 0 && FLAGS->zero)
			print_plus_byte(pfi);
		while (i <= width)
			print_int_zero_space(pfi, i++, prcsn);
		if (FLAGS->plus && num >= 0 && !FLAGS->zero)
			print_plus_byte(pfi);
		pr_int_precision(pfi, num, prcsn);
	}
}

void				print_int_bis(t_pf_item *pfi)
{
	intmax_t		anum;
	char			*test;

	anum = pfi->num;
	if (pfi->num < 0)
		pfi->bytes++;
	if (pfi->num < 0 && !FLAGS->zero && pfi->num != 2147483648)
		ft_putchar('-');
	if (pfi->num < 0)
		anum = pfi->num * -1;
	else
		anum = pfi->num;
	test = ft_llitoa(anum);
	if (pfi->lenmods->p && (pfi->num == 0) && (pfi->precision == 0))
		pfi->bytes--;
	else
		ft_putstr(test);
	pfi->bytes += int_length(pfi->num);
	if (ft_strcmp(test, "9223372036854775807") != 0
		&& ft_strcmp(test, "9223372036854775808") != 0)
		free(test);
}

void				print_int(t_pf_item *pfi, intmax_t num)
{
	int				prcsn;

	pfi->num = num;
	prcsn = pfi->precision;
	get_int_type(pfi);
	if (FLAGS->space && !FLAGS->plus && pfi->num >= 0)
		print_space_byte(pfi);
	if (FLAGS->plus && pfi->num >= 0 && pfi->field_w == 0)
		print_plus_byte(pfi);
	if (FLAGS->zero && pfi->num < 0 && pfi->num != 2147483648)
		ft_putchar('-');
	if (pfi->field_w > 0)
		if (pfi->precision > pfi->field_w)
			pr_int_precision(pfi, pfi->num, prcsn);
		else
			pr_int_field_w(pfi, pfi->num, prcsn);
	else if (pfi->precision > 0)
		pr_int_precision(pfi, pfi->num, prcsn);
	else
		print_int_bis(pfi);
}
