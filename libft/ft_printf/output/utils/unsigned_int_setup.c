/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_int_setup.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2018/01/04 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

uintmax_t			unsigned_int_setup(t_pf_item *pfi, intmax_t num)
{
	uintmax_t			i;

	if (!pfi->lenmods->l && !pfi->lenmods->h && !pfi->lenmods->ll
		&& !pfi->lenmods->j && !pfi->cspecs->lg_u && !pfi->lenmods->hh
		&& !pfi->lenmods->z)
		num = (unsigned int)num;
	if (pfi->lenmods->l)
		num = (unsigned long int)num;
	if (pfi->lenmods->ll)
		num = (unsigned long long int)num;
	if (pfi->cspecs->lg_u)
		num = (uintmax_t)num;
	if (pfi->cspecs->u && pfi->lenmods->hh)
		num = (unsigned char)num;
	i = num;
	return (i);
}
