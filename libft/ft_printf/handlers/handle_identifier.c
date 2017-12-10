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

t_bool				valid_identifier(t_pf_item *pfi)
{
	if (!pfi->cspecs->s && !pfi->cspecs->lg_s && !pfi->cspecs->p
		&& !pfi->cspecs->d && !pfi->cspecs->lg_d && !pfi->cspecs->i
		&& !pfi->cspecs->o && !pfi->cspecs->lg_o && !pfi->cspecs->u
		&& !pfi->cspecs->lg_u && !pfi->cspecs->x && !pfi->cspecs->lg_x
		&& !pfi->cspecs->c && !pfi->cspecs->lg_c)
		return (FALSE);
	return (TRUE);
}

void					handle_error(t_pf *pf, t_pf_item *pfi)
{
	if (pf->format[pf->pos] != '%')
	{
		ft_putchar(pf->format[pf->pos]);
		pfi->bytes++;
	}
}

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
		print_invalid_identifier(pf, pfi);
	// if (!valid_identifier(pfi))
	// 	print_invalid_identifier(pf, pfi);
	// else
	print_identifier(pfi, args);
	// print_pfi(pfi);
	pf->bytes += pfi->bytes;
	free(pfi);
}
