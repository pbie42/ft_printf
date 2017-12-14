/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_len_mod.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/11/10 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void					handle_len_mod(t_pf *pf, t_pf_item *pfi)
{
	if (pf->format[pf->pos] == 'h')
	{
		if (pf->format[pf->pos + 1] && pf->format[pf->pos + 1] == 'h')
		{
			pfi->lenmods->hh = TRUE;
			++pf->pos;
		}
		else
		{
			pfi->lenmods->h = TRUE;
			++pf->pos;
		}
	}
	else if (pf->format[pf->pos] == 'l')
	{
		if (pf->format[pf->pos + 1] && pf->format[pf->pos + 1] == 'l')
		{
			pfi->lenmods->ll = TRUE;
			++pf->pos;
		}
		else
		{
			pfi->lenmods->l = TRUE;
			++pf->pos;
		}
	}
	else if (pf->format[pf->pos] == 'j')
	{
		pfi->lenmods->j = TRUE;
		++pf->pos;
	}
	else if (pf->format[pf->pos] == 'z')
	{
		pfi->lenmods->z = TRUE;
		++pf->pos;
	}
	// ++pf->pos;
}
