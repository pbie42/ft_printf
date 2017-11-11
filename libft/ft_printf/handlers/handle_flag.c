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

#include "libft.h"

void					handle_flag(t_pf *pf, t_pf_item *pfi)
{
	if (pf->format[pf->pos] == '-')
		while(pf->format[pf->pos++] == '-')
			pfi->flags->minus = TRUE;
	if (pf->format[pf->pos] == '+')
		while(pf->format[pf->pos++] == '+')
			pfi->flags->plus = TRUE;
	if (pf->format[pf->pos] == '#')
		while(pf->format[pf->pos++] == '#')
			pfi->flags->hash = TRUE;
	if (pf->format[pf->pos] == '0')
		while(pf->format[pf->pos++] == '0')
			pfi->flags->zero = TRUE;
}