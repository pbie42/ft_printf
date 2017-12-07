/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 13:17:17 by pbie              #+#    #+#             */
/*   Updated: 2017/12/07 16:31:17 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void				print_hex_long_precision(t_pf_item *pfi, char *num)
{
	int				i;
	int				len;

	i = pfi->precision;
	len = ft_strlen(num);
	while (i-- > len)
		print_zero_byte(pfi);
	if (pfi->cspecs->lg_x)
		ft_strrev(ft_strupper(num));
	else
		ft_strrev(ft_strlower(num));
	pfi->bytes += len;
}

int					hex_long_get_width(t_pf_item *pfi, char *num)
{
	int				width;

	width = 0;
	if (pfi->precision >= pfi->field_w)
		pfi->precision = 0;
	width = pfi->field_w - pfi->precision - 1;
	if (!pfi->precision)
		width -= ft_strlen(num);
	return (width);
}

void				print_hex_long_field_w(t_pf_item *pfi, char *num)
{
	int				i;
	int				width;

	i = 0;
	width = hex_long_get_width(pfi, num);
	if (pfi->flags->minus)
	{
		print_hex_long_precision(pfi, num);
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
		print_hex_long_precision(pfi, num);
	}
}

void				print_hex_long(t_pf_item *pfi, long long int num)
{
	char			*tmp;
	t_ulli			i;

	i = num;
	if (pfi->flags->hash)
		print_hex_long_prefix(pfi);
	tmp = ft_dec_to_hex_long(i);
	if (pfi->field_w > 0)
		if (pfi->precision > pfi->field_w)
			print_hex_long_precision(pfi, tmp);
		else
			print_hex_long_field_w(pfi, tmp);
	else if (pfi->precision > 0)
		print_hex_long_precision(pfi, tmp);
	else
	{
		if (pfi->cspecs->lg_x)
			ft_strrev(ft_strupper(tmp));
		else
			ft_strrev(ft_strlower(tmp));
		pfi->bytes += ft_strlen(tmp);
	}
	free(tmp);
}
