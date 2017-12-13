/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/12/07 16:42:12 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void				print_address_precision(t_pf_item *pfi, char *num, int prcsn)
{
	int				i;
	int				len;

	i = prcsn;
	if (!pfi->flags->zero)
		ft_putstr("0x");
	i = pfi->precision;
	len = ft_strlen(num);
	while (i-- > len)
		print_zero_byte(pfi);
	if (pfi->cspecs->lg_x)
		ft_strrev(ft_strupper(num));
	else
		ft_strrev(ft_strlower(num));
	pfi->bytes += ft_strlen(num);
}

int					address_get_width(t_pf_item *pfi, char *num, int prcsn)
{
	int				width;

	width = 0;
	if (pfi->precision < (int)ft_strlen(num))
		pfi->precision = (int)ft_strlen(num);
	if (pfi->precision >= pfi->field_w)
	{
		pfi->precision = 0;
		prcsn = 0;
	}
	width = pfi->field_w - pfi->precision - 1;
	if (!pfi->precision)
		width -= ft_strlen(num);
	return (width - 2);
}

void				print_address_field_w(t_pf_item *pfi, char *num, int prcsn)
{
	int				i;
	int				width;

	i = 0;
	width = address_get_width(pfi, num, prcsn);
	if (pfi->flags->minus)
	{
		print_address_precision(pfi, num, prcsn);
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
		print_address_precision(pfi, num, prcsn);
	}
}

void				print_address(t_pf_item *pfi, long int num)
{
	char			*tmp;
	int				prcsn;

	pfi->bytes += 2;
	prcsn = pfi->precision;
	tmp = ft_address_to_hex(num);
	if (pfi->flags->zero)
		ft_putstr("0x");
	if (pfi->field_w > 0)
	{
		if (pfi->precision > pfi->field_w)
			print_address_precision(pfi, tmp, prcsn);
		else
			print_address_field_w(pfi, tmp, prcsn);
	}
	else if (pfi->precision > 0)
		print_address_precision(pfi, tmp, prcsn);
	else if (pfi->lenmods->p && pfi->precision == 0)
		ft_putstr("0x");
	else
	{
		ft_putstr("0x");
		if (pfi->cspecs->lg_x)
			ft_strrev(ft_strupper(tmp));
		else
			ft_strrev(ft_strlower(tmp));
		pfi->bytes += ft_strlen(tmp);
	}
	free(tmp);
}
