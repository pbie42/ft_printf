/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conversions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/11/10 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
