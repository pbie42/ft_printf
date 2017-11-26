/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/11/17 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void					print_address_precision(t_pf_item *pfi, char *num)
{
	int				i;
	int				len;
	
	i = pfi->precision;
	len = ft_strlen(num);
	while (i-- > len)
	{
		ft_putchar('0');
		pfi->bytes++;
	}
	if (pfi->cspecs->lg_x)
		ft_strrev(ft_strupper(num));
	else
		ft_strrev(ft_strlower(num));
	pfi->bytes++;
}

int					address_get_width(t_pf_item *pfi, char *num)
{
	int				width;

	width = 0;
	if (pfi->precision >= pfi->field_w)
		pfi->precision = 0;
	width = pfi->field_w - pfi->precision - 1;
	if (!pfi->precision)
		width -= ft_strlen(num);
	return (width - 2);
}

void					print_address_field_w(t_pf_item *pfi, char *num)
{
	int				i;
	int				width;

	i = 0;
	width = address_get_width(pfi, num);
	if (pfi->flags->minus)
	{
		print_address_precision(pfi, num);
		while (i++ <= width)
		{
			ft_putchar(' ');
			pfi->bytes++;
		}
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
		print_address_precision(pfi, num);
	}
}

void					print_address(t_pf_item *pfi, long int num)
{
	char				*tmp;
	
	ft_putstr("0x");
	tmp = ft_address_to_hex(num);
	if (pfi->field_w > 0)
	{
		if (pfi->precision > pfi->field_w)
			print_address_precision(pfi, tmp);
		else
			print_address_field_w(pfi, tmp);
	}
	else if (pfi->precision > 0)
		print_address_precision(pfi, tmp);
	else
	{
		if (pfi->cspecs->lg_x)
			ft_strrev(ft_strupper(tmp));
		else
			ft_strrev(ft_strlower(tmp));
		pfi->bytes++;
	}
	free(tmp);
}