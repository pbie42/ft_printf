/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2018/01/04 13:37:25 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

#define MAXUL "18446744073709551615"
#define MAX7 "9223372036854775807"
#define MAX8 "9223372036854775808"
#define LENMOD pfi->lenmods

void				pr_int_us_prcsn(t_pf_item *pfi, uintmax_t num, int prcsn)
{
	int				i;
	int				len;
	char			*tmp;

	i = prcsn;
	i = pfi->precision;
	len = int_length(num);
	while (i-- > len)
		print_zero_byte(pfi);
	if (num == ULONG_MAX)
	{
		tmp = (char *)malloc(sizeof(char) * ft_strlen(MAXUL) + 1);
		tmp = ft_strcpy(tmp, MAXUL);
	}
	else
		tmp = ft_llitoa(num);
	ft_putstr(tmp);
	pfi->bytes += ft_strlen(tmp);
	if (ft_strcmp(tmp, "9223372036854775807") != 0
		&& ft_strcmp(tmp, "9223372036854775808") != 0)
		free(tmp);
}

int					int_us_get_width(t_pf_item *pfi, uintmax_t num, int prcsn)
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
	return (width);
}

void				pr_int_us_field_w(t_pf_item *pfi, uintmax_t num, int prcsn)
{
	int				i;
	int				width;

	i = 0;
	width = int_us_get_width(pfi, num, prcsn);
	if (pfi->flags->minus)
	{
		pr_int_us_prcsn(pfi, num, prcsn);
		while (i++ <= width)
			print_space_byte(pfi);
	}
	else
	{
		while (i++ <= width)
		{
			if (pfi->flags->zero && i >= prcsn)
				ft_putchar('0');
			else
				ft_putchar(' ');
			pfi->bytes++;
		}
		pr_int_us_prcsn(pfi, num, prcsn);
	}
}

void				print_unsigned_int_bis(t_pf_item *pfi, uintmax_t i, \
							int prcsn, unsigned long num)
{
	char			*tmp;

	if (pfi->field_w > 0 && pfi->precision > pfi->field_w)
		pr_int_us_prcsn(pfi, i, prcsn);
	else if (pfi->field_w > 0 && pfi->precision < pfi->field_w)
		pr_int_us_field_w(pfi, i, prcsn);
	else if (pfi->precision > 0)
		pr_int_us_prcsn(pfi, i, prcsn);
	else
	{
		if ((unsigned long)num == ULONG_MAX)
		{
			tmp = (char *)malloc(sizeof(char) * ft_strlen(MAXUL) + 1);
			tmp = ft_strcpy(tmp, MAXUL);
		}
		else
			tmp = ft_llitoa(num);
		if (LENMOD->p && (ft_strcmp(tmp, "0") == 0) && (pfi->precision == 0))
			pfi->bytes--;
		else
			ft_putstr(tmp);
		pfi->bytes += ft_strlen(tmp);
		if (ft_strcmp(tmp, MAX7) != 0 && ft_strcmp(tmp, MAX8) != 0)
			free(tmp);
	}
}

void				print_unsigned_int(t_pf_item *pfi, intmax_t num)
{
	uintmax_t		i;
	int				prcsn;

	if (!LENMOD->l && !LENMOD->h && !LENMOD->ll
		&& !LENMOD->j && !pfi->cspecs->lg_u && !LENMOD->hh
		&& !LENMOD->z)
		num = (unsigned int)num;
	if (LENMOD->l)
		num = (unsigned long int)num;
	if (LENMOD->ll)
		num = (unsigned long long int)num;
	if (pfi->cspecs->lg_u)
		num = (uintmax_t)num;
	if (pfi->cspecs->u && LENMOD->hh)
		num = (unsigned char)num;
	i = num;
	prcsn = pfi->precision;
	print_unsigned_int_bis(pfi, i, prcsn, (unsigned long)num);
}
