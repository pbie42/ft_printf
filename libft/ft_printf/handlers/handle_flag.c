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

#include "libftprintf.h"

void					handle_flag(t_pf *pf, t_pf_item *pfi)
{
	// ft_putendl("in handle flag");
	while (pf->format[pf->pos] == ' ')
	{
		// ft_putendl("space");
		pfi->flags->space = TRUE;
		pf->pos++;
	}
	if (pf->format[pf->pos] == '-')
	{
		// ft_putendl("is minus");
		while(pf->format[pf->pos] == '-')
		{
			pfi->flags->minus = TRUE;
			pf->pos++;
		}
	}
	if (pf->format[pf->pos] == '+')
	{
		// ft_putendl("is plus");
		while(pf->format[pf->pos] == '+')
		{
			pfi->flags->plus = TRUE;
			pf->pos++;
		}
	}
	if (pf->format[pf->pos] == '#')
	{
		// ft_putendl("is hash");
		while(pf->format[pf->pos] == '#')
		{
			pfi->flags->hash = TRUE;
			pf->pos++;
		}
	}
	if (pf->format[pf->pos] == '0')
	{
		// ft_putendl("is zero");
		while(pf->format[pf->pos] == '0')
		{
			pfi->flags->zero = TRUE;
			pf->pos++;
		}
	}
}