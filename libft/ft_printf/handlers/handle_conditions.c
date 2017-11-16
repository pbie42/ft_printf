/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conditions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/11/10 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					check_conversions(t_pf_item *pfi)
{
	if (ft_isalpha(pfi->c_error))
	{
		ft_putstr("invalid conversion specifier '");
		ft_putchar(pfi->c_error);
		ft_exit("'");
	}
	if (!pfi->cspecs->s && !pfi->cspecs->lg_s && !pfi->cspecs->p
		&& !pfi->cspecs->d && !pfi->cspecs->lg_d && !pfi->cspecs->i
		&& !pfi->cspecs->o && !pfi->cspecs->lg_o && !pfi->cspecs->u
		&& !pfi->cspecs->lg_u && !pfi->cspecs->x && !pfi->cspecs->lg_x
		&& !pfi->cspecs->c && !pfi->cspecs->lg_c)
		ft_exit("invalid conversion specifier ' '");
}

void					handle_conditions(t_pf_item *pfi)
{
	if (pfi->flags->minus && pfi->flags->zero)
		ft_exit("warning: flag '0' is ignored when flag '-' is present");
	if (pfi->flags->hash && pfi->cspecs->d)
		ft_exit("flag '#' results in undefined behavior with 'd' conversion specifier");
	if (pfi->flags->space && pfi->cspecs->s)
		ft_exit("flag ' ' results in undefined behavior with 's' conversion specifier");
	if (pfi->flags->space && pfi->cspecs->c)
		ft_exit("flag ' ' results in undefined behavior with 'c' conversion specifier");
	// if (pfi->lenmods->h && pfi->cspecs->d)
	// 	ft_exit("format specifies type 'short' but the argument has type 'int'");
	// if (pfi->lenmods->hh && pfi->cspecs->d)
	// 	ft_exit("format specifies type 'char' but the argument has type 'int'");
	check_conversions(pfi);
}