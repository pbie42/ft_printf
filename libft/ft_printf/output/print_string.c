/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/11/17 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					print_precision(t_pf_item *pfi, char *s)
{
	int				i;
	
	i = 0;
	if (pfi->precision > 0)
		while (i < pfi->precision)
		{
			ft_putchar(s[i++]);
			pfi->bytes++;
		}
	else
	{
		ft_putstr(s);
		pfi->bytes++;
	}
}

// void					print_field_w_bis(t_pf_item *pfi, char *s)
// {
// 	if ()
// 		while (i++ <= width)
// 		{
// 			if (pfi->flags->zero)
// 				ft_putchar('0');
// 			else
// 				ft_putchar(' ');
// 			pfi->bytes++;
// 		}
// }

void					print_field_w(t_pf_item *pfi, char *s)
{
	int				i;
	int				width;

	i = 0;
	if (pfi->precision >= pfi->field_w)
		pfi->precision = 0;
	width = pfi->field_w - pfi->precision - 1;
	if (!pfi->precision)
		width -= ft_strlen(s);
	ft_putendlnbr("width is: ", width);
	if (pfi->flags->minus)
	{
		print_precision(pfi, s);
		while (i++ <= width)
		{
			ft_putchar(' ');
			pfi->bytes++;
		}
	}
	else
	{
		ft_putendl("no minus");
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

void					print_string(t_pf_item *pfi, char *s)
{
	if (pfi->field_w > 0)
	{
		if (pfi->precision > pfi->field_w)
			print_precision(pfi, s);
		else{
			ft_putendl("field_w > precision");
			print_field_w(pfi, s);
		}
	}
	else if (pfi->precision > 0)
		print_precision(pfi, s);
	else
	{
		ft_putstr(s);
		pfi->bytes++;
	}
}