/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_identifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/11/18 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void					print_identifier(t_pf_item *pfi, va_list args)
{
	if (pfi->cspecs->lg_c || (pfi->cspecs->c && pfi->lenmods->l))
		print_wide_char(pfi, va_arg(args, wint_t));
	if (pfi->cspecs->lg_s || (pfi->cspecs->s && pfi->lenmods->l))
		print_wide_string(pfi, va_arg(args, wchar_t *));
	else if (pfi->cspecs->c)
		print_char(pfi, (unsigned char)va_arg(args, int));
	else if (pfi->cspecs->d || pfi->cspecs->i)
		print_int(pfi, va_arg(args, int));
	else if (pfi->cspecs->u)
		print_unsigned_int(pfi, va_arg(args, long long int));
	else if (pfi->cspecs->s)
		print_string(pfi, va_arg(args, char *));
	else if (pfi->cspecs->o)
		print_oct(pfi, va_arg(args, long int));
	else if ((pfi->lenmods->j)
		&& (pfi->cspecs->x || pfi->cspecs->lg_x ))
		print_hex_max(pfi, va_arg(args, intmax_t));
	else if ((pfi->lenmods->l || pfi->lenmods->ll)
		&& (pfi->cspecs->x || pfi->cspecs->lg_x ))
		print_hex_long(pfi, va_arg(args, long int));
	else if (pfi->cspecs->x || pfi->cspecs->lg_x)
		print_hex(pfi, va_arg(args, int));
	else if (pfi->cspecs->p)
		print_address(pfi, va_arg(args, long int));
	else if (pfi->cspecs->percent)
		print_char(pfi, '%');
}