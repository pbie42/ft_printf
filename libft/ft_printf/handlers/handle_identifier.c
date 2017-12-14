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
	// ft_putendl("in hurr");
	if (!pfi->cspecs->s && !pfi->cspecs->lg_s && !pfi->cspecs->p
		&& !pfi->cspecs->d && !pfi->cspecs->lg_d && !pfi->cspecs->i
		&& !pfi->cspecs->o && !pfi->cspecs->lg_o && !pfi->cspecs->u
		&& !pfi->cspecs->lg_u && !pfi->cspecs->x && !pfi->cspecs->lg_x
		&& !pfi->cspecs->c && !pfi->cspecs->lg_c && !pfi->cspecs->percent)
		return (FALSE);
	// ft_putendl("past hurr");
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
	t_bool			error;

	pfi = NULL;
	error = FALSE;
	++pf->pos;
	pfi = init_pfi(pfi);
	while (ft_isflag(pf->format[pf->pos]))
		handle_flag(pf, pfi);
	if (ft_isdigit(pf->format[pf->pos]))
		handle_field_width(pf, pfi);
	while (ft_isflag(pf->format[pf->pos]))
		handle_flag(pf, pfi);
	while (pf->format[pf->pos] == '.')
	{
		pfi->lenmods->p = !pfi->lenmods->p;
		handle_precision(pf, pfi);
	}
	while (ft_isflag(pf->format[pf->pos]))
		handle_flag(pf, pfi);
	while (ft_islmod(pf->format[pf->pos]) && !error)
	{
		if (pfi->lenmods->l == TRUE)
			error = TRUE;
		else
			handle_len_mod(pf, pfi);
	}
	while (ft_isflag(pf->format[pf->pos]) && !error)
		handle_flag(pf, pfi);
	if (ft_isconversion(pf->format[pf->pos]) && !error)
		handle_conversion(pf, pfi);
	else if (error)
		;
	else if (!valid_identifier(pfi) && pf->format[pf->pos] != 'Z' && pf->format[pf->pos] != 'R'
	&& pf->format[pf->pos - 1] && pf->format[pf->pos - 1] != '%')
		error = TRUE;
	else
		print_invalid_identifier(pf, pfi);
	// if (!valid_identifier(pfi))
	// 	print_invalid_identifier(pf, pfi);
	if (!error)
		print_identifier(pfi, args);
	// print_pfi(pfi);
	if (pfi->bytes == -1 && !error)
		pf->bytes = -1;
	else if (error)
	{
		pfi->bytes = 0;
		pf->len_error = TRUE;
	}
	else
		pf->bytes += pfi->bytes;
	free_pfi(pfi);
}
