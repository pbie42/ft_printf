/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/11/10 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void					space_true(t_pf *pf, t_pf_item *pfi)
{
	pfi->flags->space = TRUE;
	pf->pos++;
}

void					handle_flag(t_pf *pf, t_pf_item *pfi)
{
	while (pf->format[pf->pos] == ' ')
		space_true(pf, pfi);
	while (pf->format[pf->pos] == '-')
	{
		pfi->flags->minus = TRUE;
		pf->pos++;
	}
	while (pf->format[pf->pos] == '+')
	{
		pfi->flags->plus = TRUE;
		pf->pos++;
	}
	while (pf->format[pf->pos] == '#')
	{
		pfi->flags->hash = TRUE;
		pf->pos++;
	}
	while (pf->format[pf->pos] == '0')
	{
		pfi->flags->zero = !pfi->flags->zero;
		pf->pos++;
	}
}
