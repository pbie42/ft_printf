/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oct_change.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2018/01/04 14:57:01 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char				*oct_change(t_pf_item *pfi, intmax_t n)
{
	char			*tmp;
	intmax_t		oct;

	if (!pfi->cspecs->lg_o && pfi->lenmods->hh)
		n = (unsigned char)n;
	if (!pfi->cspecs->lg_o && pfi->lenmods->h)
		n = (unsigned short)n;
	if (!pfi->cspecs->lg_o)
		n = (unsigned int)n;
	oct = ft_dec_to_oct(n);
	tmp = ft_llitoa(oct);
	return (tmp);
}
