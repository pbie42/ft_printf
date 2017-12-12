/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pfi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/11/10 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void					print_pfi_bis(t_pf_item *pfi)
{
	ft_putendl("CONVERSIONS");
	ft_putendlnbr("cspecs->s: ", pfi->cspecs->s);
	ft_putendlnbr("cspecs->lg_s: ", pfi->cspecs->lg_s);
	ft_putendlnbr("cspecs->p: ", pfi->cspecs->p);
	ft_putendlnbr("cspecs->d: ", pfi->cspecs->d);
	ft_putendlnbr("cspecs->lg_d: ", pfi->cspecs->lg_d);
	ft_putendlnbr("cspecs->i: ", pfi->cspecs->i);
	ft_putendlnbr("cspecs->o: ", pfi->cspecs->o);
	ft_putendlnbr("cspecs->lg_o: ", pfi->cspecs->lg_o);
	ft_putendlnbr("cspecs->u: ", pfi->cspecs->u);
	ft_putendlnbr("cspecs->lg_u: ", pfi->cspecs->lg_u);
	ft_putendlnbr("cspecs->x: ", pfi->cspecs->x);
	ft_putendlnbr("cspecs->lg_x: ", pfi->cspecs->lg_x);
	ft_putendlnbr("cspecs->c: ", pfi->cspecs->c);
	ft_putendlnbr("cspecs->lg_c: ", pfi->cspecs->lg_c);
	ft_putendlnbr("cspecs->percent: ", pfi->cspecs->percent);
	ft_putchar('\n');
}

void					print_pfi(t_pf_item *pfi)
{
	ft_putendl("FLAGS");
	ft_putendlnbr("flags->hash: ", pfi->flags->hash);
	ft_putendlnbr("flags->zero: ", pfi->flags->zero);
	ft_putendlnbr("flags->plus: ", pfi->flags->plus);
	ft_putendlnbr("flags->minus: ", pfi->flags->minus);
	ft_putendlnbr("flags->space: ", pfi->flags->space);
	ft_putchar('\n');
	ft_putendl("FIELD WIDTH");
	ft_putendlnbr("field_w: ", pfi->field_w);
	ft_putendl("PRECISION WIDTH");
	ft_putendlnbr("precision: ", pfi->precision);
	ft_putendl("LENGTH MODIFIERS");
	ft_putendlnbr("lenmods->h: ", pfi->lenmods->h);
	ft_putendlnbr("lenmods->hh: ", pfi->lenmods->hh);
	ft_putendlnbr("lenmods->l: ", pfi->lenmods->l);
	ft_putendlnbr("lenmods->ll: ", pfi->lenmods->ll);
	ft_putendlnbr("lenmods->j: ", pfi->lenmods->j);
	ft_putendlnbr("lenmods->j: ", pfi->lenmods->j);
	ft_putendlnbr("lenmods->z: ", pfi->lenmods->z);
	ft_putendlnbr("lenmods->p: ", pfi->lenmods->p);
	ft_putchar('\n');
	print_pfi_bis(pfi);
}
