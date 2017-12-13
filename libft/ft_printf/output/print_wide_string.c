/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wide_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 13:17:17 by pbie              #+#    #+#             */
/*   Updated: 2017/12/12 15:16:26 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_ws_strcmp(const wchar_t *s1, const wchar_t *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((wchar_t)s1[i] - (wchar_t)s2[i]);
}

void				ft_putwidestr(t_pf_item *pfi, wchar_t *ws)
{
	int			i;

	i = -1;
	while (ws[++i])
		print_wide_char(pfi, ws[i]);
}

int					get_ws_width(wchar_t *ws)
{
	int				width;
	int				i;

	i = -1;
	width = 0;
	while (ws[++i])
		width += get_wide_char_length(ws[i]);
	return (width);
}

void				print_ws_precision(t_pf_item *pfi, wchar_t *ws)
{
	int				i;
	int				width;

	i = 0;
	width = get_wide_char_length(ws[i]);
	while (i <= pfi->precision && i < width && width <= pfi->precision)
	{
		// ft_putendlnbr("wide is ", width);
		print_wide_char(pfi, ws[i]);
		i++;
		width += get_wide_char_length(ws[i]);
	}
	// ft_putendlnbr("i is ", i);
	// ft_putendlnbr("wide is ", width - get_wide_char_length(ws[i]));
}

int				get_ws_precision(t_pf_item *pfi, wchar_t *ws)
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
	int			width;
	int			prcsn;

	prcsn = get_ws_width(ws);
	if (pfi->precision > 0)
		prcsn = get_ws_precision(pfi, ws);
	else if (pfi->lenmods->p && pfi->precision == 0)
		prcsn = 0;
	width = pfi->field_w - prcsn - 1;;
	if (!pfi->flags->minus)
	{
		while (width >= 0)
		{
			if (pfi->flags->zero)
				ft_putchar('0');
			else
				ft_putchar(' ');
			pfi->bytes++;
			width--;
		}
	}
	if (pfi->precision > 0)
		print_ws_precision(pfi, ws);
	else if (pfi->lenmods->p && pfi->precision == 0)
		;
	else
		ft_putwidestr(pfi, ws);
	if (pfi->flags->minus)
	{
		while (width >= 0)
		{
			if (pfi->flags->zero)
				ft_putchar('0');
			else
				ft_putchar(' ');
			pfi->bytes++;
			width--;
		}
	}
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
