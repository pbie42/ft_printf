/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pfi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/12/07 13:59:13 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void					init_flags(t_pf_item *pfi)
{
	if (!(pfi->flags = (t_pf_flags *)malloc(sizeof(t_pf_flags) * 1)))
		ft_exit("malloc error init_flags");
	pfi->flags->minus = FALSE;
	pfi->flags->plus = FALSE;
	pfi->flags->hash = FALSE;
	pfi->flags->zero = FALSE;
	pfi->flags->space = FALSE;
}

void					init_lmods(t_pf_item *pfi)
{
	if (!(pfi->lenmods = (t_pf_lmods *)malloc(sizeof(t_pf_lmods) * 1)))
		ft_exit("malloc error init_lmods");
	pfi->lenmods->h = FALSE;
	pfi->lenmods->hh = FALSE;
	pfi->lenmods->l = FALSE;
	pfi->lenmods->ll = FALSE;
	pfi->lenmods->j = FALSE;
	pfi->lenmods->z = FALSE;
	pfi->lenmods->p = FALSE;
}

void					init_cspecs(t_pf_item *pfi)
{
	if (!(pfi->cspecs = (t_pf_cspecs *)malloc(sizeof(t_pf_cspecs) * 1)))
		ft_exit("malloc error init_cspecs");
	pfi->cspecs->s = FALSE;
	pfi->cspecs->lg_s = FALSE;
	pfi->cspecs->p = FALSE;
	pfi->cspecs->d = FALSE;
	pfi->cspecs->lg_d = FALSE;
	pfi->cspecs->i = FALSE;
	pfi->cspecs->o = FALSE;
	pfi->cspecs->lg_o = FALSE;
	pfi->cspecs->u = FALSE;
	pfi->cspecs->lg_u = FALSE;
	pfi->cspecs->x = FALSE;
	pfi->cspecs->lg_x = FALSE;
	pfi->cspecs->c = FALSE;
	pfi->cspecs->lg_c = FALSE;
	pfi->cspecs->percent = FALSE;
}

t_pf_item				*init_pfi(t_pf_item *pfi)
{
	if (!(pfi = (t_pf_item *)malloc(sizeof(t_pf_item) * 1)))
		ft_exit("malloc error handle_identifier");
	pfi->field_w = 0;
	pfi->precision = 0;
	pfi->bytes = 0;
	init_flags(pfi);
	init_lmods(pfi);
	init_cspecs(pfi);
	return (pfi);
}
