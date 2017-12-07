/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/12/07 16:17:34 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			print_hex_max_precision(t_pf_item *pfi, char *num, t_bool field)
{
	int			i;
	int			len;

	i = pfi->precision;
	len = ft_strlen(num);
	while (i-- > len)
		print_zero_byte(pfi);
	if (pfi->flags->hash && pfi->flags->zero && (num != 0) && !field)
		print_prefix(pfi);
	if (pfi->lenmods->p && (ft_strcmp(num, "0") == 0) && (pfi->precision == 0))
		ft_putchar(' ');
	else if (pfi->cspecs->lg_x)
		ft_strrev(ft_strupper(num));
	else
		ft_strrev(ft_strlower(num));
	pfi->bytes += len;
}

int				hex_max_get_width(t_pf_item *pfi, char *num)
{
	int			width;

	width = 0;
	if (pfi->precision >= pfi->field_w)
		pfi->precision = 0;
	width = pfi->field_w - ft_strlen(num) - 1;
	if (pfi->flags->hash)
		width -= 2;
	return (width);
}

void			print_hex_max_field_w(t_pf_item *pfi, char *num)
{
	int			i;
	int			width;

	i = 0;
	width = hex_max_get_width(pfi, num);
	if (pfi->flags->minus)
	{
		print_hex_max_precision(pfi, num, FALSE);
		while (i++ <= width)
			print_space_byte(pfi);
	}
	else
	{
		if (pfi->flags->hash && pfi->flags->zero && (ft_strcmp(num, "0") != 0))
			print_prefix(pfi);
		while (i++ <= width)
			print_zero_space(pfi);
		if (pfi->flags->hash && !pfi->flags->zero && (ft_strcmp(num, "0") != 0))
			print_prefix(pfi);
		print_hex_max_precision(pfi, num, TRUE);
	}
}

void			print_hex_max(t_pf_item *pfi, intmax_t num)
{
	char		*tmp;

	tmp = ft_dec_to_hex_max(num);
	if (pfi->flags->hash && (ft_strcmp(tmp, "0") != 0))
		pfi->bytes += 2;
	if (pfi->field_w > 0)
		if (pfi->precision >= pfi->field_w)
			print_hex_max_precision(pfi, tmp, FALSE);
		else
			print_hex_max_field_w(pfi, tmp);
	else if (pfi->precision > 0)
		print_hex_max_precision(pfi, tmp, FALSE);
	else
	{
		if (pfi->flags->hash && (ft_strcmp(tmp, "0") != 0))
			print_prefix(pfi);
		if (pfi->lenmods->p && (ft_strcmp(tmp, "0") == 0)
			&& (pfi->precision == 0))
			pfi->bytes--;
		else
			print_x_ul(pfi, tmp);
		pfi->bytes += ft_strlen(tmp);
	}
	free(tmp);
}
