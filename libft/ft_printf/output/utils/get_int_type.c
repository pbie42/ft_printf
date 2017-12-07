/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/12/07 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void				get_int_type(t_pf_item *pfi)
{
	if (!pfi->lenmods->h && !pfi->lenmods->hh && !pfi->lenmods->l
		&& !pfi->lenmods->ll && !pfi->lenmods->j && !pfi->lenmods->z)
		pfi->num = (int)pfi->num;
	if (pfi->lenmods->h)
		pfi->num = (short)pfi->num;
	if (pfi->lenmods->hh)
		pfi->num = (signed char)pfi->num;
	if (pfi->lenmods->l)
		pfi->num = (long long)pfi->num;
}
