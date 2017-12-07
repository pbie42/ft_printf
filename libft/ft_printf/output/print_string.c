/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/12/07 14:57:16 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void				print_precision(t_pf_item *pfi, char *s)
{
	int				i;

	i = 0;
	if (pfi->precision > 0 && (ft_strcmp(s, "") != 0))
		while (i < pfi->precision)
		{
			ft_putchar(s[i++]);
			pfi->bytes++;
		}
	else if (ft_strcmp(s, "") != 0)
	{
		ft_putstr(s);
		pfi->bytes += ft_strlen(s);
	}
	else
		;
}

int					get_width(t_pf_item *pfi, char *s)
{
	int				width;

	width = 0;
	if (pfi->precision >= pfi->field_w)
		pfi->precision = 0;
	width = pfi->field_w - 1;
	if (ft_strcmp(s, ""))
		width -= pfi->precision;
	if (!pfi->precision)
		width -= ft_strlen(s);
	return (width);
}

void				print_field_w(t_pf_item *pfi, char *s)
{
	int				i;
	int				width;

	i = 0;
	width = get_width(pfi, s);
	if (pfi->flags->minus)
	{
		print_precision(pfi, s);
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
		print_precision(pfi, s);
	}
}

void				print_string(t_pf_item *pfi, char *s)
{
	if (!s)
		s = ft_strdup("(null)");
	if (pfi->field_w > 0)
	{
		if (pfi->precision > pfi->field_w)
			print_precision(pfi, s);
		else
			print_field_w(pfi, s);
	}
	else if (pfi->precision > 0)
		print_precision(pfi, s);
	else if (ft_strcmp(s, "") != 0)
	{
		ft_putstr(s);
		pfi->bytes += ft_strlen(s);
	}
	else
		;
}
