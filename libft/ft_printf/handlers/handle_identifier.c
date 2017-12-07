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

#include "libftprintf.h"

void					handle_identifier(t_pf *pf, va_list args)
{
	t_pf_item		*pfi;

	pfi = NULL;
	++pf->pos;
	pfi = init_pfi(pfi);
	while (ft_isflag(pf->format[pf->pos]))
		handle_flag(pf, pfi);
	if (ft_isdigit(pf->format[pf->pos]))
		handle_field_width(pf, pfi);
	if (pf->format[pf->pos] == '.')
	{
		pfi->lenmods->p = TRUE;
		handle_precision(pf, pfi);
	}
	if (ft_islmod(pf->format[pf->pos]))
		handle_len_mod(pf, pfi);
	if (ft_isconversion(pf->format[pf->pos]))
		handle_conversion(pf, pfi);
	else
		pfi->c_error = pf->format[pf->pos];
	print_identifier(pfi, args);
	pf->bytes += pfi->bytes;
	free(pfi);
}
