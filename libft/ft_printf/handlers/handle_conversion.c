/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/12/07 13:37:43 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_bool				handle_conversion_ter(t_pf *pf, t_pf_item *pfi)
{
	t_bool			found;

	found = TRUE;
	if (pf->format[pf->pos] == 'o')
		pfi->cspecs->o = TRUE;
	else if (pf->format[pf->pos] == 'O')
		pfi->cspecs->lg_o = TRUE;
	else if (pf->format[pf->pos] == 'u')
		pfi->cspecs->u = TRUE;
	else if (pf->format[pf->pos] == 'U')
		pfi->cspecs->lg_u = TRUE;
	else if (pf->format[pf->pos] == 'x')
		pfi->cspecs->x = TRUE;
	else if (pf->format[pf->pos] == 'X')
		pfi->cspecs->lg_x = TRUE;
	else if (pf->format[pf->pos] == 'c')
		pfi->cspecs->c = TRUE;
	else if (pf->format[pf->pos] == 'C')
		pfi->cspecs->lg_c = TRUE;
	else if (pf->format[pf->pos] == '%')
		pfi->cspecs->percent = TRUE;
	else
		found = FALSE;
	return (found);
}

t_bool				handle_conversion_bis(t_pf *pf, t_pf_item *pfi)
{
	t_bool			found;

	found = TRUE;
	if (pf->format[pf->pos] == 's')
		pfi->cspecs->s = TRUE;
	else if (pf->format[pf->pos] == 'S')
		pfi->cspecs->lg_s = TRUE;
	else if (pf->format[pf->pos] == 'p')
		pfi->cspecs->p = TRUE;
	else if (pf->format[pf->pos] == 'd')
		pfi->cspecs->d = TRUE;
	else if (pf->format[pf->pos] == 'D')
		pfi->cspecs->lg_d = TRUE;
	else if (pf->format[pf->pos] == 'i')
		pfi->cspecs->i = TRUE;
	else
		found = FALSE;
	return (found);
}

void				handle_conversion(t_pf *pf, t_pf_item *pfi)
{
	if (!(handle_conversion_bis(pf, pfi)))
		if (!(handle_conversion_ter(pf, pfi)))
			ft_exit("ft_printf was not supplied a conversion variable");
}
