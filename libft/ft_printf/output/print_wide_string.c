/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wide_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 13:17:17 by pbie              #+#    #+#             */
/*   Updated: 2018/01/04 14:24:46 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void				ft_putwidestr(t_pf_item *pfi, wchar_t *ws)
{
	int				i;

	i = -1;
	while (ws[++i])
		print_wide_char(pfi, ws[i]);
}

void				print_ws_precision(t_pf_item *pfi, wchar_t *ws)
{
	int				i;
	int				width;

	i = 0;
	width = get_wide_char_length(ws[i]);
	while (i <= pfi->precision && i < width && width <= pfi->precision)
	{
		print_wide_char(pfi, ws[i]);
		i++;
		width += get_wide_char_length(ws[i]);
	}
}

int					get_ws_precision(t_pf_item *pfi, wchar_t *ws)
{
	int				i;
	int				width;

	i = 0;
	width = get_wide_char_length(ws[i]);
	while (i <= pfi->precision && i < width && width <= pfi->precision)
	{
		i++;
		width += get_wide_char_length(ws[i]);
	}
	return (width - get_wide_char_length(ws[i]));
}

void				print_ws_field_w(t_pf_item *pfi, wchar_t *ws)
{
	int				width;
	int				prcsn;

	prcsn = ft_ws_width(ws);
	if (pfi->precision > 0)
		prcsn = get_ws_precision(pfi, ws);
	else if (pfi->lenmods->p && pfi->precision == 0)
		prcsn = 0;
	width = pfi->field_w - prcsn - 1;
	if (!pfi->flags->minus)
		while (width >= 0)
			width = print_zero_space_ws(pfi, width);
	if (pfi->precision > 0)
		print_ws_precision(pfi, ws);
	else if (pfi->lenmods->p && pfi->precision == 0)
		;
	else
		ft_putwidestr(pfi, ws);
	if (pfi->flags->minus)
		while (width >= 0)
			width = print_zero_space_ws(pfi, width);
}

void				print_wide_string(t_pf_item *pfi, wchar_t *ws)
{
	if (MB_CUR_MAX == 1)
	{
		pfi->bytes = -1;
		return ;
	}
	if (!ws)
	{
		ft_putstr("(null)");
		pfi->bytes += ft_strlen("(null)");
		return ;
	}
	if (pfi->field_w > 0)
	{
		print_ws_field_w(pfi, ws);
	}
	else if (pfi->precision > 0)
	{
		print_ws_precision(pfi, ws);
	}
	else
		ft_putwidestr(pfi, ws);
}
