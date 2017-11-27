/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/11/17 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void					print_hex_precision(t_pf_item *pfi, char *num)
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
	pfi->bytes += len;
}

int					hex_get_width(t_pf_item *pfi, char *num)
{
	int				width;

	width = 0;
	if (pfi->precision >= pfi->field_w)
		pfi->precision = 0;
	width = pfi->field_w - ft_strlen(num) - 1;
	if (pfi->flags->hash)
		width -= 2;
	return (width);
}

void					print_hex_field_w(t_pf_item *pfi, char *num)
{
	int				i;
	int				width;

	i = 0;
	width = hex_get_width(pfi, num);
	if (pfi->flags->minus)
	{
		print_hex_precision(pfi, num);
		while (i++ <= width)
		{
			ft_putchar(' ');
			pfi->bytes++;
		}
	}
	else
	{
		if (pfi->flags->hash && pfi->flags->zero)
		{
			if (pfi->cspecs->x)
				ft_putstr("0x");
			else
				ft_putstr("0X");
		}
		while (i++ <= width)
		{
			if (pfi->flags->zero)
				ft_putchar('0');
			else
				ft_putchar(' ');
			pfi->bytes++;
		}
		if (pfi->flags->hash && !pfi->flags->zero)
		{
			if (pfi->cspecs->x)
				ft_putstr("0x");
			else
				ft_putstr("0X");
		}
		print_hex_precision(pfi, num);
	}
}

void					print_hex(t_pf_item *pfi, int num)
{
	char				*tmp;
	unsigned int	i;

	i = num;
	if (pfi->flags->hash)
		pfi->bytes += 2;
	tmp = ft_dec_to_hex(i);
	if (pfi->field_w > 0)
	{
		if (pfi->precision >= pfi->field_w)
			print_hex_precision(pfi, tmp);
		else
			print_hex_field_w(pfi, tmp);
	}
	else if (pfi->precision > 0)
		print_hex_precision(pfi, tmp);
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