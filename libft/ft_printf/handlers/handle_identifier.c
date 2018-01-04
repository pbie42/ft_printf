/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_identifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2018/01/04 16:41:14 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

#define FORMAT pf->format
#define POS pf->pos

t_bool				valid_identifier(t_pf_item *pfi)
{
	if (!pfi->cspecs->s && !pfi->cspecs->lg_s && !pfi->cspecs->p
		&& !pfi->cspecs->d && !pfi->cspecs->lg_d && !pfi->cspecs->i
		&& !pfi->cspecs->o && !pfi->cspecs->lg_o && !pfi->cspecs->u
		&& !pfi->cspecs->lg_u && !pfi->cspecs->x && !pfi->cspecs->lg_x
		&& !pfi->cspecs->c && !pfi->cspecs->lg_c && !pfi->cspecs->percent)
		return (FALSE);
	return (TRUE);
}

void				handle_error(t_pf *pf, t_pf_item *pfi)
{
	if (FORMAT[POS] != '%')
	{
		ft_putchar(FORMAT[POS]);
		pfi->bytes++;
	}
}

t_bool				handle_identifier_bis(t_pf *pf, t_pf_item *pfi, \
														t_bool error)
{
	while (ft_isflag(FORMAT[POS]))
		handle_flag(pf, pfi);
	if (ft_isdigit(FORMAT[POS]))
		handle_field_width(pf, pfi);
	while (ft_isflag(FORMAT[POS]))
		handle_flag(pf, pfi);
	while (FORMAT[POS] == '.')
	{
		pfi->lenmods->p = !pfi->lenmods->p;
		handle_precision(pf, pfi);
	}
	while (ft_isflag(FORMAT[POS]))
		handle_flag(pf, pfi);
	while (ft_islmod(FORMAT[POS]) && !error)
		if (pfi->lenmods->l == TRUE)
			error = TRUE;
		else
			handle_len_mod(pf, pfi);
	while (ft_isflag(FORMAT[POS]) && !error)
		handle_flag(pf, pfi);
	return (error);
}

void				handle_identifier_ter(t_pf *pf, va_list args, \
								t_bool error, t_pf_item *pfi)
{
	if (!error)
		print_identifier(pfi, args);
	if (pfi->bytes == -1 && !error)
		pf->bytes = -1;
	else if (error)
	{
		pfi->bytes = 0;
		pf->len_error = TRUE;
	}
	else
		pf->bytes += pfi->bytes;
}

void				handle_identifier(t_pf *pf, va_list args)
{
	t_pf_item		*pfi;
	t_bool			error;

	pfi = NULL;
	error = FALSE;
	++POS;
	pfi = init_pfi(pfi);
	error = handle_identifier_bis(pf, pfi, error);
	if (ft_isconversion(FORMAT[POS]) && !error)
		handle_conversion(pf, pfi);
	else if (error)
		;
	else if (!valid_identifier(pfi) && FORMAT[POS] != 'Z'
	&& FORMAT[POS] != 'R' && FORMAT[POS - 1] && FORMAT[POS - 1] != '%')
		error = TRUE;
	else
		print_invalid_identifier(pf, pfi);
	handle_identifier_ter(pf, args, error, pfi);
	free_pfi(pfi);
}
