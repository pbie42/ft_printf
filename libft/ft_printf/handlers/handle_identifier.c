/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_identifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/11/10 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					handle_identifier(t_pf *pf)
{
	t_pf_item		*pfi;

	++pf->pos;
	if(!(pfi = (t_pf_item *)malloc(sizeof(t_pf_item) * 1)))
		ft_exit("malloc error handle_identifier");
	pfi->field_w = 0;
	pfi->precision = 0;
	init_pfi(pfi);
	if (ft_isflag(pf->format[pf->pos]))
	{
		ft_putendl("isflag");
		ft_putchar(pf->format[pf->pos]);
		handle_flag(pf, pfi);
	}
	if (ft_isdigit(pf->format[pf->pos]))
	{
		ft_putendl("isdigit");
		ft_putchar(pf->format[pf->pos]);
		handle_field_width(pf, pfi);
	}
	if (pf->format[pf->pos] == '.')
	{
		ft_putendl("isprecision");
		ft_putchar(pf->format[pf->pos]);
		handle_precision(pf, pfi);
	}
	if (ft_islmod(pf->format[pf->pos]))
	{
		ft_putendl("islmod");
		ft_putchar(pf->format[pf->pos]);
		handle_len_mod(pf, pfi);
	}
	if (ft_isconversion(pf->format[pf->pos]))
	{
		ft_putendl("isconversion");
		ft_putchar(pf->format[pf->pos]);
		handle_conversion(pf, pfi);
	}
	print_pfi(pfi);
}