/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_invalid_identifier.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/12/09 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void				print_invalid_identifier(t_pf *pf, t_pf_item *pfi)
{
	if (pf->format[pf->pos] != '%')
	{
		print_char(pfi, pf->format[pf->pos]);
	}
}