/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/12/07 16:30:26 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			print_hex_precision(t_pf_item *pfi, char *num, t_bool field, int prcsn)
{
	int			i;
	int			len;

	if (field == FALSE && pfi->cspecs->x && pfi->flags->hash && pfi->lenmods->p)
		ft_putstr("0x");
	if (field == FALSE && pfi->cspecs->lg_x && pfi->flags->hash && pfi->lenmods->p)
		ft_putstr("0X");
	i = pfi->precision;
	len = ft_strlen(num);
	while (i-- > len)
	{
		ft_putchar('0');
		pfi->bytes++;
	}
	if (pfi->flags->hash && pfi->flags->zero && (num != 0) && !field)
		print_prefix(pfi);
	if (pfi->lenmods->p && (ft_strcmp(num, "0") == 0) && (prcsn == 0))
		ft_putchar(' ');
	else if (pfi->cspecs->lg_x)
		ft_strrev(ft_strupper(num));
	else
		ft_strrev(ft_strlower(num));
	pfi->bytes += len;
}

int				hex_get_width(t_pf_item *pfi, char *num, int prcsn)
{
	int			width;

	width = 0;
	if (pfi->precision < (int)ft_strlen(num))
		pfi->precision = (int)ft_strlen(num);
	if (pfi->precision >= pfi->field_w && pfi->field_w > (int)ft_strlen(num))
	{
		pfi->precision = 0;
		prcsn = 0;
	}
	// ft_putendlnbr("field_w ", pfi->field_w);
	// ft_putendlnbr("precision ", pfi->precision);
	width = pfi->field_w - pfi->precision - 1;
	if (pfi->flags->hash)
		width -= 2;
	// ft_putendlnbr("width is ", width);
	return (width);
}

void			print_hex_field_w(t_pf_item *pfi, char *num, int prcsn)
{
	int			i;
	int			width;

	i = 0;
	width = hex_get_width(pfi, num, prcsn);
	if (pfi->flags->minus)
	{
		print_hex_precision(pfi, num, FALSE, prcsn);
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
		print_hex_precision(pfi, num, TRUE, prcsn);
	}
}

void			print_hex_bis(t_pf_item *pfi, char *tmp)
{
	if (pfi->flags->hash && (ft_strcmp(tmp, "0") != 0))
		print_prefix(pfi);
	if (pfi->lenmods->p && (ft_strcmp(tmp, "0") == 0) && (pfi->precision == 0))
		pfi->bytes--;
	else
		print_x_ul(pfi, tmp);
	pfi->bytes += ft_strlen(tmp);
}

void			print_hex(t_pf_item *pfi, intmax_t num)
{
	char		*tmp;
	int			prcsn;

	// ft_putendl("here homie");
	if (!pfi->lenmods->hh && !pfi->lenmods->l
		&& !pfi->lenmods->ll && !pfi->lenmods->j && !pfi->lenmods->z
		&& !pfi->cspecs->lg_d)
		num = (unsigned int)num;
	if (pfi->lenmods->hh)
		num = (unsigned char)num;
	tmp = ft_dec_to_hex(num);
	prcsn = pfi->precision;
	if (pfi->flags->hash && (ft_strcmp(tmp, "0") != 0))
		pfi->bytes += 2;
	if (pfi->field_w > 0)
		if (pfi->precision >= pfi->field_w)
			print_hex_precision(pfi, tmp, FALSE, prcsn);
		else
			print_hex_field_w(pfi, tmp, prcsn);
	else if (pfi->precision > 0)
		print_hex_precision(pfi, tmp, FALSE, prcsn);
	else
		print_hex_bis(pfi, tmp);
	free(tmp);
}
